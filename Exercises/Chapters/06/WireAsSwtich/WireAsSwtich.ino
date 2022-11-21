const int inputPin = 5;
const int ledPin = 13;

void setup() {
  // put your setup code here, to run once:

  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:

  int switchOpen = digitalRead(inputPin);
  
  digitalWrite(ledPin, !switchOpen);

}
