const int pin = 13;
const int period = 250;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // This doesn't work
  int count = 0;

  digitalWrite(pin, HIGH);
  delay(period);

  digitalWrite(pin, LOW);
  delay(period);

  Serial.println(count);

  count ++;

  if (count == 20)
  {
    count = 0;

    delay(3000);
  }

}
