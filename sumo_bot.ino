// Motor RIGHT (Needs to reworked)
int ena = 6;
int in4 = 2;
int in3 = 4;

// Motor LEFT (Needs to reworked)
int enb = 3;
int in2 = 5;
int in1 = 7;

void setup() {
  // Set the motor control pins as output
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);

  // Start the serial connection at 9600 Bauds
  Serial.begin(9600);

  // set the speed control (255 Max) for the motors
  analogWrite(ena, 255);  // LEFT
  analogWrite(enb, 180);  // RIGHT (-75 power) 
}

void loop() {
  // Our debug code to prove that the bot is running
  moveForward();
  delay(6000);
  moveBackward();
  delay(1000);
  moveLeft();
  delay(4000);
  moveRight();
  delay(4000);
  stopMoving();
}

// Bot moves forward
void moveForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

// Bot moves backwards
void moveBackward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

// Bot turns left
void moveLeft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

// Bot turns right
void moveRight() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

// Bot stops moving
void stopMoving() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
} 
