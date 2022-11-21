const int pin = 5;

void setup() {
  // put your setup code here, to run once:

  pinMode(pin, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  int reading = digitalRead(pin);

  Serial.println(reading);

  delay(1000);
}
