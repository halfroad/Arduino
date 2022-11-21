const int pin = A0;

void setup()
{
  // put your setup code here, to run once:

  pinMode(pin, OUTPUT);

  Serial.begin(9600);
  Serial.println("Enter 1 or 0");

}

void loop()
{
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0)
  {
    char ch = Serial.read();

    if (ch == '1')
    {
      digitalWrite(pin, HIGH);
    }
    else if (ch == '0')
    {
      digitalWrite(pin, LOW);
    }
  }

}
