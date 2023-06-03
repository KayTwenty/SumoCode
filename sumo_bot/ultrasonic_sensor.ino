// Function to detect an obstacle using the ultrasonic sensor
bool detectObstacle() {
  long duration;
  int distance;

  // Trigger the ultrasonic sensor
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Measure the echo response time
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;

  // Print the distance for debugging
  printDistance(distance);

  // Check if an obstacle is within a certain range
  if (distance > 0 && distance < targetDistance) {
    targetDetected = true;
    return true;  // Obstacle detected
  } else {
    targetDetected = false;
    return false;  // No obstacle detected
  }
}

// Function to print the distance in centimeters
void printDistance(int distance) {
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");
}
