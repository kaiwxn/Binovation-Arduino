
#define MAX_DIST 150
#define MIN_DIST 2

#define ECHO_PIN 2
#define TRIG_PIN 3
#define BUTTON_PIN 4

void readUltrasonic(){
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(20);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  float t = pulseIn(ECHO_PIN, HIGH);
  float distance = t*0.017015;

  if(distance >= MAX_DIST || distance <= MIN_DIST){
    Serial.println("Invalid measurement!");
  }
  else{
    Serial.print("Distance: ");
    Serial.println(distance);
  }
}

void readButton(){
  // read the state of the switch/button:
  int button_state = digitalRead(BUTTON_PIN);

  Serial.print("Button:");

  if(button_state) Serial.print("Not Pressed ");
  else Serial.print("Pressed ");
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT); // Sets the trigPin as an Output
  pinMode(ECHO_PIN, INPUT); // Sets the echoPin as an Input
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Sets the buttonPin as Input
  Serial.begin(9600);
}

void loop() {
  readUltrasonic();
  readButton();
  delay(500);
}
