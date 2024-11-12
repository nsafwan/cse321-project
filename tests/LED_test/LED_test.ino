//This is a simple push button led test. Pushing the button turns on the led and validates the functionality of the led.

#define led_out 12
#define button_in 4

void setup()
{
  pinMode(button_in, INPUT);
  pinMode(led_out, OUTPUT);
}

int button = 0;

void loop()
{
  button = digitalRead(button_in); 
  
  if(button == HIGH){
    digitalWrite(led_out, HIGH);
  } else {
    digitalWrite(led_out, LOW);
  }
  delay(20);
}