int pin = 13;
int period = 100;
int count = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(pin, HIGH);
  delay(period);
  
  digitalWrite(pin, LOW);
  delay(period);

  count ++;

  if (count == 20)
  {
    count = 0;
    delay(3000);
  }

}
