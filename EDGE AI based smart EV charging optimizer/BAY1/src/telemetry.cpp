#include <ArduinoJson.h>
#include "telemetry.h"
#include "network.h"
#include "state.h"
#include "config.h"

// ---------------------------------------------------------------------
// FR-7 telemetry publish. Adds `overloadActive` (additive, beyond SRS
// 8.3's baseline schema) so the ThingsBoard Overcurrent alarm rule can
// be a one-line filter. Also adds `manualOverrideActive` so the
// dashboard can show when a bay is under operator control instead of
// automatic optimization.
// ---------------------------------------------------------------------
void publishTelemetry() {
  // checck if the device is connected to cloud or not
  if (!mqtt.connected()) return;

  // store the values as key value pair format
  JsonDocument doc;
  doc["bayId"] = BAY_ID;
  doc["voltage"] = round(voltage * 10) / 10.0;
  doc["current"] = round(current * 10) / 10.0;
  doc["power"] = round(power * 10) / 10.0;
  doc["temperature"] = round(temperature * 10) / 10.0;
  doc["bayStatus"] = bayStatus;
  doc["predictedArrivalProb"] = round(predictedArrivalProb * 100)/100.0 ;
  doc["predictiveDurationMin"] = predictiveDurationMin; 

  // add  load decision,throttlr leveel, overload
  doc["throttleLevel"] = throttleLevel;
  doc["loadDecision"] = loadDecision;
  doc["overloadActive"] = overloadActive;

  char buffer[350];
  serializeJson(doc, buffer);

  // push the data to the cloud 
  mqtt.publish("v1/devices/me/telemetry", buffer);
  Serial.print("[MQTT >>] ");
  Serial.println(buffer);
}


//mqttcallback(topic, message)
//{

//}

void mqttCallback(char* topic, byte* payload, unsigned int length);
