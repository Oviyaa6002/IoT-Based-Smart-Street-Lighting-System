# 💡 IoT-Based Smart Street Lighting System

An IoT-based Smart Street Lighting System developed using **ESP32**, **LDR Sensor**, **Blynk**, and **ThingSpeak**. The system automatically adjusts street light brightness according to ambient light intensity, helping to reduce energy consumption while enabling remote monitoring through IoT platforms.

---

## 📌 Project Overview

This project uses an **LDR (Light Dependent Resistor)** to detect ambient light levels. The ESP32 processes the sensor data and controls LED brightness using PWM.

- 🌞 Day → Street Lights OFF
- 🌆 Evening → Street Lights DIM
- 🌙 Night → Street Lights BRIGHT

Sensor data and system status are monitored using **Blynk** and **ThingSpeak**.

---

## ✨ Features

- 💡 Automatic street light control
- 🌞 Day mode (Lights OFF)
- 🌆 Evening mode (Dim brightness)
- 🌙 Night mode (Full brightness)
- 📶 Wi-Fi connectivity using ESP32
- 📱 Remote monitoring with Blynk
- ☁️ Cloud data logging using ThingSpeak
- ⚡ PWM-based brightness control
- 🔋 Energy-efficient lighting system

---

## 🛠 Components Used

| Component | Quantity |
|-----------|----------|
| ESP32 DevKit | 1 |
| LDR Sensor (2-Pin Module) | 1 |
| LEDs | 3 |
| 220Ω Resistors | 3 |
| Breadboard | 1 |
| Jumper Wires | As Required |
| USB Cable | 1 |

---

## ⚙️ Hardware Connections

| ESP32 Pin | Connected To |
|------------|--------------|
| GPIO34 | LDR AO |
| 3.3V | LDR VCC |
| GND | LDR GND |
| GPIO26 | LED (+) through 220Ω resistor |
| GND | LED (-) |

---

## 🔄 System Flow

1. Read ambient light using LDR.
2. Determine lighting condition.
3. Adjust LED brightness:
   - Day → OFF
   - Evening → DIM
   - Night → BRIGHT
4. Send sensor data to Blynk.
5. Upload data to ThingSpeak.
6. Repeat continuously.

---

## 🧠 Flowchart

![Flowchart](Images/Flowchart.png)

---

## 🔌 Circuit Diagram

![Circuit Diagram](Images/Circuit_Diagram.png)

---

## 🖥 Hardware Setup

![Hardware Setup](Images/Hardware_Setup.png)

---

## 🧪 Wokwi Simulation

The project was first tested using the Wokwi simulator before hardware implementation.

![Wokwi Simulation](Wokwi/Wokwi_Simulation.png)

---

## 📱 IoT Platforms

### Blynk

- Monitor LDR Value
- Display Light Status
- Manual/Automatic Control (Optional)

### ThingSpeak

- Cloud Data Storage
- Live Sensor Graph
- Historical Data Monitoring

---

## 📂 Project Structure

```text
IoT-Based-Smart-Street-Lighting-System
│
├── Arduino_Code
│   └── SmartStreetLightSystem.ino
│
├── Wokwi
│   └── Wokwi_Simulation.png
│
├── Images
│   ├── Circuit_Diagram.png
│   ├── Flowchart.png
│   └── Hardware_Setup.png
│
├── PPT
│   └── Smart_Street_Lighting_Presentation.pptx
│
├── Report
│   └── Project_Report.pdf
│
└── README.md
```

---

## 📈 Results

✔️ Successfully detected ambient light using the LDR.

✔️ Automatically controlled LED brightness based on light intensity.

✔️ Achieved three operating modes:

- 🌞 Day → Lights OFF
- 🌆 Evening → DIM
- 🌙 Night → BRIGHT

✔️ Data transmitted successfully to Blynk and ThingSpeak.

---

## 🚀 Future Scope

- 🚶 Motion sensor integration
- ☀️ Solar-powered street lighting
- 🤖 AI-based brightness optimization
- 🌐 Smart city integration
- 📊 Energy consumption analytics

---

## 👨‍💻 Developed By

**Oviya A**

Department of Electronics and Communication Engineering

Project: **IoT-Based Smart Street Lighting System**

---

## 📜 License

This project is developed for educational and academic purposes.