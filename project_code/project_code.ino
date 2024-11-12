#include <dht_nonblocking.h> //This is the library provided by the supplier for temperature sensor to adjust temperature readings.
#define DHT_TYPE DHT_TYPE_11 //Type of the temperature sensor.

#define ledPin 13     //LED output
#define pirPin 7        // Input PIR motion detector.
//The motor driver module needs the next three to implement PWM and clockwise and counterclockwise motor rotation. 
#define ENABLE 5        // Enable pin for motor driver
#define DIRA 3          // Direction pin A for motor driver
#define DIRB 4          // Direction pin B for motor driver
#define TEMP_THRESHOLD 20 // This is the temperature threshold. Set it to a lower temperature to turn on the fan when colder.
#define DHT_PIN 2  //This is the sensor pin for the temperature sensor. 

DHT_nonblocking dht_sensor(DHT_PIN, DHT_TYPE); //Calls the library function for the temperature and humidity sensor.

void setup() {
  Serial.begin(9600);          // Initialize
  pinMode(ledPin, OUTPUT);    // Set LED as output
  pinMode(pirPin, INPUT);       // Set PIR as input
  pinMode(ENABLE, OUTPUT);     // Set motor driver enable as output
  pinMode(DIRA, OUTPUT);        // Set motor direction A as output
  pinMode(DIRB, OUTPUT);       // Set motor direction B as output

  Serial.println("System started.");
}


void loop() {
  int motionDetected = digitalRead(pirPin); // Read motion detector.
  float temperature;

  //This measures and prints out the current temperature.
  dht_sensor.measure(&temperature, nullptr);
  Serial.print("Temperature = ");
  Serial.print(temperature, 1);
  Serial.print(" °C\n");

  if (motionDetected == HIGH) { //If motion detected.
    digitalWrite(ledPin, HIGH); // Turn on the light
    Serial.println("Motion detected: Light is turned ON."); 

    if (temperature > TEMP_THRESHOLD) { //Check if temp above threshold.
      digitalWrite(ENABLE, HIGH); //Turns on the fans
      digitalWrite(DIRA, LOW);   
      digitalWrite(DIRB, HIGH);
      Serial.println("Fan ON");
    } else {
      digitalWrite(ENABLE, LOW);  // Turn off the fan if below threshold
      Serial.println("Fan OFF");
    }

  } else { //If motion is not detected
      digitalWrite(ledPin, LOW);    // Turn off the light 
      digitalWrite(ENABLE, LOW);    // Turn off the fan 
      Serial.println("No motion detected: Light OFF, Fan OFF");
  }

  delay(3000); // some delay between each loop
}
 