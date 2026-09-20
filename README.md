# Edge AI-Based Smart EV Charging Optimizer

An embedded, multi-bay Edge AI system built on **ESP32 Microcontrollers** using **PlatformIO**. This project optimizes electric vehicle (EV) charging allocation locally (at the edge) by balancing real-time telemetry, predictive machine learning models, and dynamic power distribution constraints.

---

## 📌 Features

* **Edge AI Integration**: On-device ML inference (`edge_ai.h`, `model.h`) for local dynamic power optimization without relying on continuous cloud connectivity.
* **Multi-Bay Architecture**: Configured to scale and run independently across multiple charging bays (`BAY1`, `BAY2`, `BAY3`).
* **Real-time Telemetry**: Active monitoring for voltage, current, temperature, and battery state-of-charge (`telemetry.h`, `State.h`).
* **Network & RPC Protocols**: Robust communication interfaces (`network.h`, `rpc.h`) for local mesh interconnectivity and remote management.
* **Hardware Abstraction**: Dedicated peripheral management layer (`Peripherals.h`) handling relays, sensors, and status indicators.
* **Simulation Support**: Built-in support for offline hardware simulation using **Wokwi** (`wokwi.toml`, `diagram.json`).

## 🛠️ Hardware & Software Stack

### **Hardware Core**
* **Microcontroller:** ESP32 Development Board (NodeMCU / ESP32-WROOM-32)
### **Sensors:**
* Current Sensor (ACS712 / INA219)
* Voltage Sensor Module
* Temperature Sensor (DS18B20 / NTC)

* **Actuators:** Relays / PWM Output for dynamic EV charging rate control

## Software & Frameworks
* **Framework:** C++ / Arduino Framework via PlatformIO

* **IDE:** Visual Studio Code with PlatformIO Extension

* **Simulation:** Wokwi Simulator (wokwi.toml / diagram.json)

## 🔬 System Workflow
* The edge device operates through four primary functional modules:

* **Telemetry Pipeline (telemetry.cpp):** Periodically samples voltage, current, and thermal metrics.

* **State Machine (State.cpp):** Manages real-time bay state transitions (IDLE, CONNECTING, CHARGING, THROTTLED, FAULT).

* **Edge Optimization (edge_ai.cpp / optimization.cpp):** Evaluates real-time metrics against embedded machine learning models to dy/namically balance and throttle output power.

* **RPC Communication (rpc.cpp / network.cpp):** Handles bidirectional RPC synchronization with central dashboards and neighboring charging nodes.

## 🚀 Getting Started
### **Prerequisites:**
* Install Visual Studio Code.
* Install the PlatformIO IDE extension inside VS Code.

* **Install the Wokwi Simulator extension for VS Code to run simulations without hardware.**

## Building & Flashing
### **1. Clone the Repository:**
* **git clone https://github.com/YOUR-USERNAME/EDGE-AI-Based-smart-EV-charging-Optimizer.git
cd EDGE-AI-Based-smart-EV-charging-Optimizer**

### **2. Open a Target Bay in PlatformIO:**

* Open VS Code.
* Go to File ➔ Open Folder... and select the target bay project folder (e.g., BAY1).

### **3. Configure Parameters:**
* Open include/config.h inside the selected BAY folder.
* Set your Wi-Fi credentials, server endpoints, and pin configurations.

### **4. Build Firmware:**
* Click the PlatformIO: Build checkmark icon in the VS Code status bar (or press Ctrl+Alt+B).

### **5. Upload Firmware:**
* Connect your ESP32 board to your computer via USB.
* Click the PlatformIO: Upload arrow icon in the status bar.

## ⚡ Hardware Simulation (Wokwi)
### **To run and test the edge system virtually without physical hardware:**
* Open any BAY project directory in VS Code.
* Ensure test/diagram.json or test/wokwi.toml is present in the workspace.
* Open the Command Palette (F1 or Ctrl+Shift+P).
* Type and select Wokwi: Start Simulator.
---

## 📁 Repository Structure

```text
EDGE-AI-Based-smart-EV-charging-Optimizer/
└── EDGE AI based smart EV charging optimizer/
    ├── BAY1/                       # Controller firmware for Charging Bay 1
    │   ├── include/                # Header files (.h)
    │   │   ├── config.h            # Pin configurations & threshold parameters
    │   │   ├── edge_ai.h           # Inference runtime wrapper
    │   │   ├── model.h             # Embedded machine learning model arrays
    │   │   ├── optimization.h       # Power allocation algorithms
    │   │   ├── telemetry.h         # Sensor reading & metrics pipeline
    │   │   ├── network.h           # Wi-Fi/Ethernet stack interface
    │   │   ├── rpc.h               # Remote Procedure Call handling
    │   │   ├── State.h             # FSM (Finite State Machine) definitions
    │   │   └── Peripherals.h       # GPIO & hardware driver definitions
    │   ├── src/                    # Source files (.cpp)
    │   │   ├── main.cpp            # Entry point & execution loop
    │   │   └── ...                 # Corresponding implementation files
    │   ├── test/                   # Simulation files (Wokwi & unit tests)
    │   │   ├── diagram.json        # Wokwi circuit schema
    │   │   └── wokwi.toml          # Wokwi runner config
    │   └── platformio.ini          # PlatformIO environment & dependency settings
    ├── BAY2/                       # Controller firmware for Charging Bay 2
    └── BAY3/                       # Controller firmware for Charging Bay 3


## Note: Each BAY folder functions as an independent PlatformIO project node, enabling modular deployment to individual ESP32 microcontrollers.
