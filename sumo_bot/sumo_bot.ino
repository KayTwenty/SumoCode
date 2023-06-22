// David Anton
// Cristian Artiom
// 2023 Sumo Code
// 

// Motor Pins - RIGHT
const int enaPin = 6;
const int in4Pin = 2;
const int in3Pin = 4;

// Motor Pins - LEFT
const int enbPin = 3;
const int in2Pin = 5;
const int in1Pin = 7;

// Ultrasonic Sensor Pins
const int triggerPin = 10;
const int echoPin = 9;

// Obstacle tracking variables
int targetDistance = 70;  // In CM

// Line Sensor Pins
const int lineSensorPin = 8;

// Threshold Value for Line Detection
const int lineThreshold = 100;

// Movement Duration when Correcting Position
const int correctionDuration = 1000;

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

  // Set the ultrasonic sensor pins as input and output
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Set the line Sensor pins as input
  pinMode(lineSensorPin, INPUT);

  // Set the speed control (0-255) for the motors
  analogWrite(enaPin, leftSpeed);
  analogWrite(enbPin, rightSpeed);

  // Five second delay for start
  delay(5000);
}

void loop() {

  if (!digitalRead(lineSensorPin)) {
    moveBackward();
    delay(200);
    rotateCounterClockwise();
  } else if (detectObstacle()) {
    for (int i = 1; i <= 3; ++i) {
        moveForward();
        //delay(50);
    }
  } else {
    rotateCounterClockwise();
  }
}