# Operation Steinadler - Gazebo Simulation

**Author:** Timo Trummer  
**Timeframe:** March 2026 – June 2026

---

## 1. Basis

The GitHub project by **Okalachev** was used as the basis and as a tutorial for installing Gazebo and all required tools. [file:11]

Repository: Okalachev [file:11]

---

## 2. 1st and 2nd session

Install the Gazebo simulator on **Ubuntu 20.04** and control the drone with the **QGroundControl** app. [file:11]

- PC and smartphone with the app must be in the same Wi‑Fi network. [file:11]  
- Duration of both sessions: see → 5.1. [file:11]

---

## 3. 3rd session (Schiggy & Timo)

### 3.1 Building the joystick

With the help of an **ESP32 microcontroller** and a **B103348 joystick**, the first prototype of a controller for steering the drone was built. [file:11]  
After the successful setup with one ESP, a second one was added to transmit the data from the transmitter to the receiver. [file:11]

### 3.2 MAVLink

For transmission, **MAVLink** was used, which we studied during this session. [file:11]

---

## 4. 4th session

*(No additional details were documented for this session.)* [file:11]

---

## 5. Notes

To build the simulator: [file:11]

```bash
cd flix
make simulation        # or: make simulator

