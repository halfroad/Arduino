const int inputPin = 5;
const int ledPin = 13;
int ledValue = LOW;

void setup() {
  // put your setup code here, to run once:

  pinMode(inputPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  // Pressed
  if (digitalRead(inputPin) == LOW)
  {
    ledValue = !ledValue;

    digitalWrite(ledPin, ledValue);

    delay(500);
  }
}
