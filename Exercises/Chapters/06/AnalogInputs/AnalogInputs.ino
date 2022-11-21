const int analogPin = 0;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  int reading = analogRead(analogPin);
  float voltage = reading / 204.6;

  Serial.print("Reading = ");
  Serial.print(reading);
  Serial.print("\t\tVolts = ");
  Serial.println(voltage);

  delay(500);
}
