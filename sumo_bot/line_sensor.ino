/**
 * Handle the light sensor readings and correct the path if the robot moves outside the ring.
 * Note: Higher values indicate a lighter surface (white line),
 * while lower values indicate a darker surface (the ring boundary).
 */
void handleLightSensor() {
  int lightSensorValue = analogRead(lightSensorPin);

  // Check if the robot is outside the ring
  if (lightSensorValue < lightThreshold) {
    // Move backward to get back into the ring
    moveBackward();
    delay(correctionDuration);

    // Randomly choose left or right turn
    if (random(2) == 0) {
      moveLeft(2); // The argument could be a constant
    } else {
      moveRight(2);
    }

    delay(correctionDuration);

    // Stop moving
    stopMoving();
  }
}