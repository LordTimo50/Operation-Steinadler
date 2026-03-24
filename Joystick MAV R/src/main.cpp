#include <WiFi.h>
#include <WiFiUdp.h>
#include <common/mavlink.h>

WiFiUDP udp;
const int port = 14550;

#define OBEN_L 4
#define UNTEN_L 17
#define LINKS_L 18
#define RECHTS_L 15

#define OBEN_R 25
#define UNTEN_R 26
#define LINKS_R 27
#define RECHTS_R 32

void setup() {
  Serial.begin(115200);
  WiFi.begin("CTest", "admin1234");
  
  while (WiFi.status() != WL_CONNECTED) { delay(500); }
  udp.begin(port);

  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) { 
    delay(500); 
    Serial.print("."); 
  }
  Serial.println("\nConnected!");
  // LEDS fuer linken Joystick
  pinMode(OBEN_L,OUTPUT);
  pinMode(UNTEN_L,OUTPUT);
  pinMode(RECHTS_L,OUTPUT);
  pinMode(LINKS_L,OUTPUT);

  pinMode(OBEN_R,OUTPUT);
  pinMode(UNTEN_R,OUTPUT);
  pinMode(RECHTS_R,OUTPUT);
  pinMode(LINKS_R,OUTPUT);

  // LEDS fuer rechten Joystick
  
}


void loop() {
  int packetSize = udp.parsePacket();
  if (packetSize) {
    uint8_t buf[MAVLINK_MAX_PACKET_LEN];
    udp.read(buf, MAVLINK_MAX_PACKET_LEN);

    mavlink_message_t msg;
    mavlink_status_t status;

    for (int i = 0; i < packetSize; i++) {
      if (mavlink_parse_char(MAVLINK_COMM_0, buf[i], &msg, &status)) {
        if (msg.msgid == MAVLINK_MSG_ID_MANUAL_CONTROL) {
          mavlink_manual_control_t ctrl;
          mavlink_msg_manual_control_decode(&msg, &ctrl);

          Serial.printf("X: %d, Y: %d, Z: %d, R: %d\n",ctrl.x,ctrl.y,ctrl.z,ctrl.r);

          if (ctrl.x > 900) // Oben
          {
            digitalWrite(UNTEN_L,1);
            digitalWrite(OBEN_L,0);
          }
          else if(ctrl.x < -900) // Unten
          {
            digitalWrite(OBEN_L,1);
            digitalWrite(UNTEN_L,0);
          }
          else if(ctrl.y > 900) // Links
          {
            digitalWrite(LINKS_L,1);
            digitalWrite(RECHTS_L,0);
          }
          else if(ctrl.y < -900) // Rechts
          {
            digitalWrite(RECHTS_L,1);
            digitalWrite(LINKS_L,0);
          }
          else{
            digitalWrite(OBEN_L,0);
            digitalWrite(UNTEN_L,0);
            digitalWrite(RECHTS_L,0);
            digitalWrite(LINKS_L,0);
          }
          
          // Rechter Joystick

          if (ctrl.z > 900) // Oben
          {
            digitalWrite(UNTEN_R,1);
            digitalWrite(OBEN_R,0);
          }
          else if(ctrl.z < -900) // Unten
          {
            digitalWrite(OBEN_R,1);
            digitalWrite(UNTEN_R,0);
          }
          else if(ctrl.r > 900) // Links
          {
            digitalWrite(LINKS_R,1);
            digitalWrite(RECHTS_R,0);
          }
          else if(ctrl.r < -900) // Rechts
          {
            digitalWrite(RECHTS_R,1);
            digitalWrite(LINKS_R,0);
          }
          else{
            digitalWrite(OBEN_R,0);
            digitalWrite(UNTEN_R,0);
            digitalWrite(RECHTS_R,0);
            digitalWrite(LINKS_R,0);
          }

        }
      }
    }
  }

  
}