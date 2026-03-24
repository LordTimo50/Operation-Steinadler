# Operation Steinadler - Gazebo Simulation

**Author:** Timo Trummer  

---

## 1. Basis

The GitHub project by **Okalachev** was used as the basis and as a tutorial for installing Gazebo and all required tools. 

Repository: Okalachev 

---

## 2. 1st and 2nd session

Install the Gazebo simulator on **Ubuntu 20.04** and control the drone with the **QGroundControl** app.

- PC and smartphone with the app must be in the same Wi‑Fi network. 
- Duration of both sessions: see → 5.1. 

---

## 3. 3rd session (Schiggy & Timo)

### 3.1 Building the joystick

With the help of an **ESP32 microcontroller** and a **B103348 joystick**, the first prototype of a controller for steering the drone was built. 
After the successful setup with one ESP, a second one was added to transmit the data from the transmitter to the receiver. 

### 3.2 MAVLink

For transmission, **MAVLink** was used, which we studied during this session. 

---

## 4. 4th session

*(No additional details were documented for this session.)* 

---

## 5. Notes

To build the simulator:

```bash
cd flix
make simulation        # or: make simulator
```
### 5.1 Ubuntu / OS versions and issues

- Windows: Almost no support for Gazebo.

- Oracle VirtualBox: Problems with ARM chips.

- Ubuntu 25.10: Problems installing Gazebo11.

- Ubuntu 22.04: Problems installing tools for Gazebo11.

- Ubuntu 20.04: No problems.

## 5.1 Frame / characteristics

- 56x21mm + Antenne

- layer 0.2mm

- line 0.4mm

- infill 100%

