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
