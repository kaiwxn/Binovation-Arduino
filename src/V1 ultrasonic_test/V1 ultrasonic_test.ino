
#define MAX_DIST 150
#define MIN_DIST 2

#define ECHO_PIN 2
#define TRIG_PIN 3
#define BUTTON_PIN 4

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
    return 0.0;
  }
  return distance;
}

void setup(){
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT); // Sets the trigPin as an Output
  pinMode(ECHO_PIN, INPUT); // Sets the echoPin as an Input
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}
void loop(){
  Serial.clear();
  float distance = readUltrasonic();
  Serial.println(distance);
  delay(500);
}