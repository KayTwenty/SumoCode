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
  if (distance > 2 && distance < targetDistance) {
    return true;  // Obstacle detected
  } else {
    return false;  // No obstacle detected
  }
}

// Print the distance read from the ultrasonic sensor.
void printDistance(int distance) {
  Serial.println("----------------");
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");

  // Calculate additional statistics rounded to two decimal places
  float inches = distance / 2.54;
  float feet = inches / 12;

  // Print the additional statistics
  Serial.print("Inches: ");
  Serial.println(String(inches, 2));
  Serial.print("Feet: ");
  Serial.println(String(feet, 2));
}