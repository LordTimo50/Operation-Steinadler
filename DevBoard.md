# Dev-Board-Infrastructure

**Author: Emil Schoberegger**

#### Weblink to EasyEDA: [link](https://u.easyeda.com/join?type=project&key=d9cf635e8ea5f083779dda9d56f37d2b&inviter=fb4da0c93cf14f358111e43763df3262)
---

# 1. Picked Parts

| ID | Name                                      | Designator              | Quantity | Price |
|----|-------------------------------------------|-------------------------|----------|-------|
| 1  | ESP32-WROOM-32E(8MB)                      | U1                      | 1        | 4.371 |
| 2  | LiPo                                      | BT1                     | 1        |       |
| 3  | AMS1117-3.3_C347222                       | U2                      | 1        | 0.042 |
| 4  | DW01A_C351410                             | U3                      | 1        | 0.042 |
| 5  | 8205A_C2762931                            | U4                      | 1        | 0.03  |
| 6  | 22uF                                      | C2                      | 1        | 0.034 |
| 7  | 10uF                                      | C4,C5                   | 2        | 0.009 |
| 9  | 100nF                                     | C1, C3, C6, C7          | 4        | 0.001 |
| 10 | 10kΩ                                      | R1                      | 1        | 0.001 |
| 12 | 560Ω                                      | R2                      | 1        | 0.001 |
| 13 | 470Ω                                      | R3                      | 1        | 0.001 |
| 11 | 2kΩ                                       | R4                      | 1        | 0.001 |
| 16 | PTS645SH50SMTR92LFS                       | SW1,SW2                 | 2        | 0.418 |
| 17 | FC-2012HRK-620D                           | LED1                    | 1        | 0.013 |

# 2. Schematic

### Complete schematic

![Schematic](/images/ESP32Board.png)

---

## 2.1 ESP32 module

The **ESP32-WROOM-32E** forms the central processing unit and provides all digital and analog I/Os for the application.  
It is supplied with 3.3 V and has several GND pins as well as an EN pin for switching the internal controller on and off.  
The GPIOs are routed to pin headers and are partly labeled with function names such as SPI, SBUS, or motor directions (MFL, MFR, MRR, MRL), which prepares the board for use as a motor or drone controller.  
The decoupling capacitors C2 (22 µF) and C3 (100 nF) stabilize the 3.3 V supply directly at the module and suppress voltage spikes and noise.

---

## 2.2 Reset and boot/user buttons

This block enables resetting and boot mode of the ESP32 without external programming hardware.

### Reset button SW1

The reset button **SW1** is connected to the EN line of the ESP32 and briefly pulls the controller into reset when pressed.  
Capacitor C1 (100 nF) ensures that the reset signal is clean and free of interference.

### Boot/user button SW2

The boot/user button **SW2** is connected to IO0 (signal: IO0_BTN).  
C6 (100 nF) is used for filtering/debouncing this signal.  
By holding IO0 during reset, you can enter the bootloader; in normal operation, the button can be used as a general user input.

---

## 2.3 BMS block (LiPo supply)

This block enables direct operation of the board from a LiPo battery and protects the battery from fault conditions.

The LiPo **BT1** provides the raw voltage +3V7 (typical LiPo nominal voltage), which is used in the schematic as the +3V7 supply rail.  
The **battery management system** consists of the protection IC **DW01A (U3)** and the dual MOSFET **8205A (U4)**.  
The DW01A monitors the cell voltage and uses its outputs (OD, OC) to drive the MOSFET gates in U4, in order to connect or disconnect the current path between battery and system.  
Components R2, R4, and C7 form the required sensing and stabilization elements for the protection logic and gate drive.

Functionally, this block ensures that the battery is not further loaded in cases of undervoltage, overcurrent, or short circuit and that the board is automatically disconnected.

---

## 2.4 3.7 V to 3.3 V (3.3 V linear regulator)

The regulator block generates the stable **3.3 V supply** from the LiPo voltage.

The **AMS1117-3.3 (U2)** operates as a linear regulator; its input is connected to +3V7, and its output provides +3V3 for the ESP32 and the remaining logic.  
C4 (10 µF) on the input side and C5 (10 µF) on the output side stabilize the regulator and prevent oscillations.

This converts the strongly varying battery voltage into a defined, low-noise 3.3 V rail suitable for the ESP32.

---

## 2.5 Onboard LED

The onboard LED serves as a simple optical status and debug indicator.

The LED **LED1 (FC-2012HRK-620D)** is connected to 3.3 V via the series resistor **R2 = 560 Ω**, and its other side is connected to **IO2** of the ESP32.  
By driving IO2 (e.g., digital HIGH/LOW or PWM), the ESP32 can turn the LED on and off or make it blink.

This provides a permanently integrated diagnostic LED without requiring additional external components.

---

## 2.6 Connectors

Multiple headers are used to make routing more felxible and necessary pins easy to access. 



