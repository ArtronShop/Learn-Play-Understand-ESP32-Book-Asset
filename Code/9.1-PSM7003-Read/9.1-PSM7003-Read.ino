#include "PMS.h"

PMS pms(Serial1);

void setup() {
  Serial.begin(115200);   // GPIO1, GPIO3 (TX/RX pin on ESP-12E Development Board)
  Serial1.begin(9600, SERIAL_8N1, 26);  // GPIO2 (D4 pin on ESP-12E Development Board)
}

void loop() {
  PMS::DATA data;
  if (pms.read(data)) {
    Serial.print("PM 1.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_1_0);

    Serial.print("PM 2.5 (ug/m3): ");
    Serial.println(data.PM_AE_UG_2_5);

    Serial.print("PM 10.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_10_0);

    Serial.println();
  }

  // Do other stuff...
}