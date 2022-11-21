const int pin = 13;
const int period = 250;

void setup() {
  // put your setup code here, to run once:

  pinMode(pin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  static int count = 0;

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
