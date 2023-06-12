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
  if (distance < targetDistance) {
    return true;  // Obstacle detected
  } else {
    return false;  // No obstacle detected
  }
}

// Function to print the distance in centimeters
void printDistance(int distance) {
  delay(300);
  Serial.println("----------------");
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");
}