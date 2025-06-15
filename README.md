# 🔵 ESP32 Touch Sensor Controlled LED

This project uses an **ESP32 microcontroller** to control an LED based on the input from its **capacitive touch sensor**. When you touch the specified pin with your finger, the LED turns **ON or OFF** depending on the touch intensity.

---

## 🚀 Features

- Capacitive touch sensing using ESP32's built-in touchRead()
- Controls an LED connected to GPIO 23
- Touch input on GPIO 4 (T0 touch pin)
- Simple real-time interaction using touch input

---

## 🛠️ Hardware Required

- ESP32 Dev Module
- LED
- Resistor (220 ohm recommended)
- Breadboard and jumper wires
- USB cable for programming

---

## 📟 Circuit Diagram

- **LED anode** → GPIO 23 (through 220Ω resistor)
- **Touch input** → GPIO 4 (T0, usually the default touch pin)
- **LED cathode** → GND
- **ESP32** → Connected via USB to PC

---

## 🧠 Code Explanation

```cpp
void setup() {
  pinMode(23, OUTPUT);      // Set GPIO 23 as LED output
  pinMode(4, INPUT);        // Set GPIO 4 as touch input
  Serial.begin(9600);       // Initialize serial monitor
}

void loop() {
  Serial.print("Value\n ");
  int touchdata = touchRead(4);     // Read touch sensor value
  Serial.print(touchdata);          // Print value to Serial Monitor
  
  if (touchdata > 50) {
    digitalWrite(23, 0);  // Turn OFF LED
  }

  if (touchdata < 20) {
    digitalWrite(23, 1);  // Turn ON LED
  }

  delay(100);  // Small delay to avoid sensor bouncing
}
