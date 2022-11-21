const int pin = 13;
const int period = 250;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 0; i < 20; i ++)
  {
    flash();
  }

  delay(3000);

}

void flash()
{
  digitalWrite(pin, HIGH);
  delay(period);

  digitalWrite(pin, LOW);
  delay(period);

}
