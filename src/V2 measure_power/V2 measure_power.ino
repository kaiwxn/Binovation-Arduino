#include <ArduinoLowPower.h>

void setup() {
  Serial.begin(9600);

  Serial.println("BEGIN...");
  // LowPower.idle(6000000);
  // LowPower.sleep(6000000);

}

void loop() {
  Serial.println("LOOP HAS BEGUN!");
  delay(3000);
}
