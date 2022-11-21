
const int pin = 13;
int durations[] = {200, 200, 200, 500, 500, 500, 200, 200, 200};


void setup() {
  // put your setup code here, to run once:

  pinMode(pin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 0; i < 9; i ++)
  {
    flash(durations[i]);
  }

  delay(1000);

}

void flash(int period)
{
  digitalWrite(pin, HIGH);
  delay(period);

  digitalWrite(pin, LOW);
  delay(period);
}
