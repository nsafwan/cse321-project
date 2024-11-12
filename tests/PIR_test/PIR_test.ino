//This is a simple button press to turn on the led test.

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