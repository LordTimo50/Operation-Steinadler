# Dev-Board-Infrastructure

# 1. Picked Parts

| ID | Name                                       | Designator           | Quantity | Price |
| -- | ------------------------------------------ | -------------------- | -------- | ----- |
|  1 | ESP32-WROOM-32E(8MB)                       | U1                   | 1        | 4.371 |
|  2 | AMS1117-3.3_C347222                        | U3                   | 1        | 0.037 |
|  3 | DW01A_C351410                              | U2                   | 1        | 0.042 |
|  4 | 8205A_C2762931                             | Q1                   | 1        | 0.03  |
|  5 | LiPo                                       | BT1                  | 1        |       |
|  6 | KH-2.54PH180-1X14P-L11.5                   | J1,J2                | 2        | 0.144 |
|  7 | HX PH254-01-04-Z-L11.5 STRAIGHT PIN HEADER | J3                   | 1        | 0.023 |
|  8 | PTS645SH50SMTR92LFS                        | SW1,SW2              | 2        | 0.418 |
|  9 | FC-2012HRK-620D                            | LED1                 | 1        | 0.013 |
| 10 | 10uF                                       | C1,C2                | 2        | 0.009 |
| 11 | 22uF                                       | C10                  | 1        | 0.03  |
| 12 | 100nF                                      | C3                   | 1        | 0.001 |
| 13 | 100nF                                      | C7,C8,C9,C11,C12,C13 | 6        | 0.001 |
| 14 | 470Ω                                       | R1                   | 1        | 0.001 |
| 15 | 2kΩ                                        | R2                   | 1        | 0.001 |
| 16 | 560Ω                                       | R3                   | 1        | 0.001 |
| 17 | 10kΩ                                       | R13                  | 1        | 0.001 |

# 2. Schematic

### Complete schematic

![Schematic](/images/CustomDevBoardSchem.png)

[ESP32 module](#311-esp32-module)
[Reset and boot/user buttons](#312-reset-and-bootuser-buttons)
[BMS block (LiPo supply)](#313-bms-block-lipo-supply)
[3.7 V to 3.3 V linear regulator](#314-37-v-to-33-v-33-v-linear-regulator)
[Onboard LED](#315-onboard-led)
[Connectors (GPIO expansion via pin headers)](#316-connectors-gpio-expansion-via-pin-headers)
[UART header](#317-uart-header)

### Used Documentation

[ESP32 Ducmenation](https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32/esp-dev-kits-en-master-esp32.pdf)

[ESP32 Reference Schematic 1](https://dl.espressif.com/dl/schematics/esp32_devkitc_v4_sch.pdf)

[ESP32 Reference Schematic 2](https://dl.espressif.com/dl/schematics/SCH_ESP32-S3-DevKitC-1_V1.1_20221130.pdf)

[ESP32 Reference Schematic 3](https://documentation.espressif.com/esp32-mini-1_datasheet_en.pdf)

---

## 2.1 ESP32 module

The **ESP32-WROOM-32E** forms the central processing unit and provides all digital and analog I/Os for the application.  
It is supplied with 3.3 V and has several GND pins as well as an EN pin for switching the internal controller on and off.  
The GPIOs are routed to pin headers and are partly labeled with function names such as SPI, SBUS, or motor directions (MFL, MFR, MRR, MRL), which prepares the board for use as a motor or drone controller.  
The decoupling capacitors C10 (22 µF) and C11 (100 nF) stabilize the 3.3 V supply directly at the module and suppress voltage spikes and noise.

---

## 2.2 Reset and boot/user buttons

This block enables resetting and boot mode of the ESP32 without external programming hardware.

### Reset button SW2

The reset button **SW2** is connected to the EN line of the ESP32 and briefly pulls the controller into reset when pressed.  
Capacitor C13 (100 nF) ensures that the reset signal is clean and free of interference.

### Boot/user button SW1

The boot/user button **SW1** is connected to IO0 (signal: IO0_BTN) and pulled up to 3.3 V via R13 (10 kΩ).  
C9 (100 nF) is used for filtering/debouncing this signal.  
By holding IO0 during reset, you can enter the bootloader; in normal operation, the button can be used as a general user input.

---

## 2.3 BMS block (LiPo supply)

This block enables direct operation of the board from a LiPo battery and protects the battery from fault conditions.

The LiPo **BT1** provides the raw voltage +3V7 (typical LiPo nominal voltage), which is used in the schematic as the +3V7 supply rail.  
The **battery management system** consists of the protection IC **DW01A (U2)** and the dual MOSFET **8205A (Q1)**.  
The DW01A monitors the cell voltage and uses its outputs (OD, OC) to drive the MOSFET gates in Q1, in order to connect or disconnect the current path between battery and system.  
Components R1, R2, and C3 form the required sensing and stabilization elements for the protection logic and gate drive.

Functionally, this block ensures that the battery is not further loaded in cases of undervoltage, overcurrent, or short circuit and that the board is automatically disconnected.

---

## 2.4 3.7 V to 3.3 V (3.3 V linear regulator)

The regulator block generates the stable **3.3 V supply** from the LiPo voltage.

The **AMS1117-3.3 (U3)** operates as a linear regulator; its input is connected to +3V7, and its output provides +3V3 for the ESP32 and the remaining logic.  
C1 (10 µF) on the input side and C2 (10 µF) on the output side stabilize the regulator and prevent oscillations.

This converts the strongly varying battery voltage into a defined, low-noise 3.3 V rail suitable for the ESP32.

---

## 2.5 Onboard LED

The onboard LED serves as a simple optical status and debug indicator.

The LED **LED1 (FC-2012HRK-620D)** is connected to 3.3 V via the series resistor **R3 = 560 Ω**, and its other side is connected to **IO2** of the ESP32.  
By driving IO2 (e.g., digital HIGH/LOW or PWM), the ESP32 can turn the LED on and off or make it blink.

This provides a permanently integrated diagnostic LED without requiring additional external components.

---

## 2.6 Connectors (GPIO expansion via pin headers)

The large pin headers bring the most important GPIOs of the ESP32 to the outside and allow external hardware to be connected.

The two headers **J1** and **J2** (each 1×14 pins) route signals such as IO21, IO19 (SPI_MISO), IO18 (SPI_SCK), IO5, IO17 (SBUS_TX), IO16 (SBUS_RX), IO4, IO35, IO32, IO33, IO25, IO26, IO27, IO14 (MFR), and IO12 (MRL) out of the board.  
This allows motor drivers, sensors, and bus interfaces (SPI, SBUS, etc.) to be connected directly via connectors.

This block turns the board into a flexibly usable ESP32 controller that is clearly designed for drive and control applications.

---

## 2.7 UART header

The UART header is used for programming and debugging via an external USB-UART interface.

The header **J3** routes **TXD0, RXD0, 3.3 V, and GND** to the outside.  
A USB-UART adapter can be connected directly to flash new firmware or read serial debug output.

Together with the reset and boot buttons, this block replicates the typical ESP32 devkit programming environment.

