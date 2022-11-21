int pin = 13;
int duration = 100;

void setup() {
  // put your setup code here, to run once:

  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(pin, HIGH);
  delay(duration);

  digitalWrite(pin, LOW);
  delay(duration);

  // duration += 100;
}
