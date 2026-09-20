#include <Arduino.h>
#include <WiFi.h>
#include "network.h"
#include "State.h"
#include "config.h"
#include "Peripherals.h"
#include "WiFi.h"
#include "telemetry.h"
#include "model.h"
#include "edge_ai.h"
#include "optimization.h"
#include "rpc.h"
#include "attributes.h"


//const char* WIFI_SSID = "Wokwi-GUEST";
//const char* WIFI_PASS = "";

void connect_wifi()
{
  WiFi.begin(WIFI_SSID,WIFI_PASS);
  Serial.print("Connecting to WIFI");

  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print("..");
  }

  Serial.println("Wifi connected");

}

void mqttCallback(char* topic, byte* payload, unsigned int length);

void setup()
{

    Serial.begin(115200);
    dht.begin();  // initialise sesnor

    configTime(0,0,"pool.ntp.org", "time.nist.gov");

    pinMode(BTN_PLUGIN,INPUT_PULLUP);
    pinMode(BTN_PLUGOUT,INPUT_PULLUP);
    pinMode(RELAY_PIN , OUTPUT);
    pinMode(LED_GREEN , OUTPUT);
    pinMode(LED_YELLOW , OUTPUT);
    pinMode(LED_RED , OUTPUT);

    
    connectWiFi();

    //config mqtt server
    mqtt.setServer(MQTT_SERVER,MQTT_PORT);

    // setup call back function after receiving data from the cloud
    mqtt.setCallback(mqttCallback);
    mqtt.setBufferSize(512);

    connectMQTT();
}

unsigned long now;
unsigned long last_print;

void loop()
{
  mqtt.loop();

    //print vals every 2 sec
    now = millis();
    if((now - last_print) > 5000)
    {
        last_print = now;
        // read data from sensors
        sample_sensor();
        // run AI to get predction
        runEdgeAIInference();
        // decide load based on predictions
        if(manualOverrideActive==0){ 
          runOptimization();
        }
        // publish the data
        publishTelemetry();

    }
    plug_status();
    updateLeds();

    
}




