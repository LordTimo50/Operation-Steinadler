#include <common/mavlink.h>

#include <WiFi.h>
#include <WiFiUdp.h>

#define XL_PIN 35
#define YL_PIN 34
#define XR_PIN 32
#define YR_PIN 33

const char* ssid = "CTest";
const char* password = "admin1234";

WiFiUDP udp;
const char* remote_ip = "192.168.4.2"; // Standard IP for the first connected station
const int port = 14550;

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
  udp.begin(port);
}

void loop() {
  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MAX_PACKET_LEN];

  // 1. Read & Scale Joystick (0-4095 to -1000 to 1000)
  int16_t xl = map(analogRead(XL_PIN), 0, 4095, -1000, 1000);
  int16_t yl = map(analogRead(YL_PIN), 0, 4095, -1000, 1000);

  int16_t xr = map(analogRead(XR_PIN),0,4095,-1000,1000);
  int16_t yr = map(analogRead(YR_PIN),0,4095,-1000,1000);

  // 2. Pack the MANUAL_CONTROL message
  // SysID: 1, CompID: 1, Target: 1, x, y, z, r, buttons
  mavlink_msg_manual_control_pack(1, 1, &msg, 1, xl, yl, xr, yr, 0);

  // 3. Serialize and Send via UDP
  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
  udp.beginPacket(remote_ip, port);
  udp.write(buf, len);
  udp.endPacket();

  delay(20); // ~50Hz refresh rate is plenty for joysticks
}

