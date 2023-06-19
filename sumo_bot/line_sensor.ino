// Line Sensor Pins
const int lineSensorPin = A0;

// Threshold Value for Line Detection
const int lineThreshold = 500;

// Movement Duration when Correcting Position
const int correctionDuration = 1000;

/* Note: 
Higher values indicate a lighter surface (white line), 
while lower values indicate a darker surface (the ring boundary).
*/

void handleLineSensor() {
  int lineSensorValue = analogRead(lineSensorPin);

  // Check if line is detected
  if (lineSensorValue > lineThreshold) {
    // Move backward to get back into the ring
    moveBackward();
    delay(correctionDuration);

    // Randomly choose left or right turn
    if (random(2) == 0) {
      moveLeft();
    } else {
      moveRight();
    }

    delay(correctionDuration);

    // Stop moving
    stopMoving();
  }
}