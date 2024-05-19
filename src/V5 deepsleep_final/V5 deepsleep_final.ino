// 
// Program for the Arduino Nano 
//

#include <ArduinoLowPower.h>

#define MAX_DIST 150
#define MIN_DIST 2

#define ECHO_PIN 2
#define TRIG_PIN 3
#define BUTTON_PIN 4

// Prepare for measuring
float measurements[310];
int count = 0;
bool inMeasurePeriod = 0;

float readUltrasonic(){
  //
  // Reads Data from Ultrasonic sensor HC-SR04P
  //

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(20);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  float t = pulseIn(ECHO_PIN, HIGH);
  float distance = t*0.017015;

  if(distance >= MAX_DIST || distance <= MIN_DIST){
    return -1;
  }
  else{
    return distance;
  }
}

bool readButton(){
  //
  // read the state of the switch/button:
  // OFF | 0
  // ON  | 1
  // 

  int button_state = digitalRead(BUTTON_PIN);
  return button_state;
}

void beginMeasurement(){
  //
  // This method waits till a button press thats marks the start of the measuring period
  //

  while(1){
    if(!readButton()){

      // Blink the on-board LED for signal
      Serial.println("BUTTON HAS BEEN PRESSED");
      pinMode(LED_BUILTIN, LOW);
      delay(200);
      pinMode(LED_BUILTIN, HIGH);
      delay(200);
      pinMode(LED_BUILTIN, LOW);
      return;
    }
    delay(500);
  }
}

void transferData(){
  //
  // Checks for Button press and sends the data to Serial if it responds. 
  //

  // Checks for Button Press
  while(1){
    if(!readButton()){
      Serial.println("The measurements have been disabled. Please write \"1\" to Serial window");

      // Checks for user answer
      while(1){
        if(Serial.read() == 49){
          for(int i = 0; i < 310; i++){
            Serial.print(measurements[i]);
            Serial.print(" ");
          }
          return;
        }
        delay(1000);
      }
    }
    delay(500);
  }
}

void measure(){

  // 22 times per day * 14 days = 308
  // In this case, dont measure
  if(count >= 308){
    inMeasurePeriod = 0;
    return;
  } 

  inMeasurePeriod = 1;

  float distance = readUltrasonic();

  measurements[count++] = distance;

  if(count % 22 >= 0 && count % 22 <= 4){
    // 1000 * 60 * 60 = 3600000 ms 
    LowPower.deepSleep(3600000);
  }
  else{
    LowPower.deepSleep(72000000);
  }
  
}

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT); // Sets the trigPin as an Output
  pinMode(ECHO_PIN, INPUT); // Sets the echoPin as an Input
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Sets the buttonPin as Input

  if(!inMeasurePeriod){
    beginMeasurement();
  }
  
  measure();

  if(!inMeasurePeriod){
    transferData();
  }

}

void loop() {
  Serial.println("loop has begun!");
  delay(2000);
}
