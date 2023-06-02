// Motor Pins - RIGHT
const int enaPin = 6;
const int in4Pin = 2;
const int in3Pin = 4;

// Motor Pins - LEFT
const int enbPin = 3;
const int in2Pin = 5;
const int in1Pin = 7;

// Speed Values
const int leftSpeed = 255;   // Max speed for the left motor
const int rightSpeed = 250;  // Reduced speed for the right motor

void setup() {
  // Set the motor control pins as output
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  pinMode(enaPin, OUTPUT);
  pinMode(enbPin, OUTPUT);

  // Start the serial connection at 9600 Bauds
  Serial.begin(9600);

  // Set the speed control (0-255) for the motors
  analogWrite(enaPin, leftSpeed);
  analogWrite(enbPin, rightSpeed);
}

void loop() {
  // Go straight for a couple of seconds
  moveForward();
  delay(2000);

  // Move backward for a couple of seconds
  moveBackward();
  delay(2000);

  // Turn left
  moveLeft();
  delay(1000);

  // Turn right
  moveRight();
  delay(1000);

  // Stop moving
  stopMoving();
}

// Function to move the bot forward
void moveForward() {
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);
  digitalWrite(in3Pin, HIGH);
  digitalWrite(in4Pin, LOW);
}

// Function to move the bot backward
void moveBackward() {
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, HIGH);
  digitalWrite(in3Pin, LOW);
  digitalWrite(in4Pin, HIGH);
}

// Function to turn the bot left
void moveLeft() {
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, HIGH);
  digitalWrite(in3Pin, HIGH);
  digitalWrite(in4Pin, LOW);
  delay(500);
  stopMoving(); 
}

// Function to turn the bot right
void moveRight() {
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);
  digitalWrite(in3Pin, LOW);
  digitalWrite(in4Pin, HIGH);
  delay(1000);
  stopMoving(); 
}

// Function to stop the bot
void stopMoving() {
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, LOW);
  digitalWrite(in3Pin, LOW);
  digitalWrite(in4Pin, LOW);
}
