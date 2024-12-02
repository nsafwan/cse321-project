#include <dht_nonblocking.h> // Library for temperature sensor
#define DHT_TYPE DHT_TYPE_11 // Type of the temperature sensor.

#define ledPin 13     // LED output
#define pirPin 7      // Input PIR motion detector
#define ENABLE 5      // Enable pin for motor driver (PWM)
#define DIRA 3        // Direction pin A for motor driver
#define DIRB 4        // Direction pin B for motor driver
#define TEMP_THRESHOLD 22 // Temperature threshold
#define DHT_PIN 2     // Sensor pin for the temperature sensor 

DHT_nonblocking dht_sensor(DHT_PIN, DHT_TYPE); // Initialize DHT sensor

void setup() {
  Serial.begin(9600);          // Initialize serial communication
  pinMode(ledPin, OUTPUT);     // Set LED as output
  pinMode(pirPin, INPUT);      // Set PIR as input
  pinMode(ENABLE, OUTPUT);     // Set motor driver enable as output
  pinMode(DIRA, OUTPUT);       // Set motor direction A as output
  pinMode(DIRB, OUTPUT);       // Set motor direction B as output

  Serial.println("System started.");
}

void loop() {
  int motionDetected = digitalRead(pirPin); // Read motion detector
  float temperature;

  // Measure and print the current temperature
  dht_sensor.measure(&temperature, nullptr);
  Serial.print("Temperature = ");
  Serial.print(temperature, 1);
  Serial.println(" °C");

  if (motionDetected == HIGH) { // If motion detected
    digitalWrite(ledPin, HIGH); // Turn on the light
    Serial.println("Motion detected: Light is turned ON."); 

    if (temperature > TEMP_THRESHOLD) { // Check if temp above threshold
      int tempDifference = temperature - TEMP_THRESHOLD; 
      int speed = map(tempDifference, 0, 10, 50, 255); // Scale speed based on temperature difference
      speed = constrain(speed, 50, 255); // Ensure speed is within valid range
      analogWrite(ENABLE, speed); // Set fan speed
      digitalWrite(DIRA, LOW);   
      digitalWrite(DIRB, HIGH);
      Serial.print("Fan ON, Speed = ");
      Serial.println(speed);
    } else {
      digitalWrite(ENABLE, LOW);  // Turn off the fan if below threshold
      Serial.println("Fan OFF");
    }

  } else { // If no motion detected
    digitalWrite(ledPin, LOW);   // Turn off the light
    digitalWrite(ENABLE, LOW);   // Turn off the fan
    Serial.println("No motion detected: Light OFF, Fan OFF");
  }

  delay(3000); // Some delay between each loop
}

 