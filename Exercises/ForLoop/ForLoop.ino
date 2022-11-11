int pin =13;
int period = 100;

void setup() {
  // put your setup code here, to run once:

  pinMode(pin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 0; i < 20; i ++)
  {
    digitalWrite(pin, HIGH);
    delay(period);

    digitalWrite(pin, LOW);
    delay(period);
  }

  delay(3000);

}
