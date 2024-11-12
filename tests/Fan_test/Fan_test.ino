//This is a simple example that just turns the motor in a direction then in the other direction to test its functionality.

#define ENABLE 5
#define DIRA 3
#define DIRB 4
 
void setup() {
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
}

void loop() {
  digitalWrite(ENABLE,HIGH);
  digitalWrite(DIRA,HIGH);
  digitalWrite(DIRB,LOW);
  delay(3000);

  digitalWrite(ENABLE,HIGH);
  digitalWrite(DIRA,LOW);
  digitalWrite(DIRB,HIGH);
  delay(3000);
}

   
