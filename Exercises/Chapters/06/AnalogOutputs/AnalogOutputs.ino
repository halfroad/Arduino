const int outputPin = 3;


void setup()
{
  // put your setup code here, to run once:

  pinMode(outputPin, OUTPUT);

  Serial.begin(9600);
  Serial.println("enter Volts 0 to 5");
}

void loop()
{
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0)
  {
    float volts = Serial.parseFloat();
    int pwm = volts * 255.0 / 5.0;

    Serial.println(pwm);

    analogWrite(outputPin, pwm);
  }
}
