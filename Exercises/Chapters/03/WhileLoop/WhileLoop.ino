int pin = 13;
int period = 100;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  int i = 0;

  while (i < 20)
  {
    digitalWrite(pin, HIGH);
    delay(period);

    digitalWrite(pin, LOW);
    delay(period);

    i ++;

  }

}
