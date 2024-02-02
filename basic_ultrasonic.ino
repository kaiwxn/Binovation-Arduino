#include <Ultrasonic.h>
#include <ArduinoLowPower.h>

// 22 Times per day * 14 Days = 308 Elements
RTC_DATA_ATTR float füllstände[310];
RTC_DATA_ATTR int count = 0;

//Initialize ultrasonic sensor
RTC_DATA_ATTR Ultrasonic ultrasonic(8, 7);

void setup() {

  füllstände[count++] = ultrasonic.read();

  if(count % 22 >= 0 && count % 22 <= 4){
    // 1000 * 60 * 60 = 3600000 ms 
    LowPower.deepsleep(3600000);
  }
  else{
    LowPower.deepsleep(72000000);
  }
  
}

void loop() {

}
