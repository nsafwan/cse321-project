//This is a simple test to test the DHT11 sensor. This is not using the library so the numbers are very off, but we are able to print something which shows that the sensor is working.

int sensorPin = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int reading = analogRead(sensorPin);
  float voltage = reading * 4.68;
  voltage /= 1024.0;
  
  float temperatureC = (voltage - 0.5) * 100;
  Serial.print(temperatureC);
  Serial.println(" degrees C");
  
  delay(1000);
}