void setup() {
  // put your setup code here, to run once:

  float fahrenheit = centigrade2Fahrenheit(17.0);

  Serial.begin(9600);
  Serial.println(fahrenheit);

}

void loop() {
  // put your main code here, to run repeatedly:

}

float centigrade2Fahrenheit(float centigrade)
{
  float fahrenheit = centigrade * 9.0 / 5.0 + 32.0;

  return fahrenheit;
}
