// Function to detect an obstacle using the ultrasonic sensor
bool detectObstacle() {
  // Trigger the ultrasonic sensor
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Measure the echo response time
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  int distance = duration * 0.034 / 2;

  // Print the distance for debugging
  printDistance(distance);

  // Check if an obstacle is within a certain range
  if (distance > 0 && distance < targetDistance) {
    return true;  // Obstacle detected
  } else {
    return false;  // No obstacle detected
  }
}

// Function to print the distance in centimeters
void printDistance(int distance) {
  Serial.println("----------------");
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");
}