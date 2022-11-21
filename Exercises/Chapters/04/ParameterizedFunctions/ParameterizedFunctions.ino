const int pin = 13;
const int period = 250;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  flash(20, period);
  delay(3000);

}

void flash(int numberFlashes, int duration)
{
  for (int i = 0; i < numberFlashes; i ++)
  {
    digitalWrite(pin, HIGH);
    delay(duration);

    digitalWrite(pin, LOW);
    delay(duration);
  }
}
