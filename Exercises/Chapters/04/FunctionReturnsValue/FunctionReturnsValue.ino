void setup() {
  // put your setup code here, to run once:

  int fahrenheit = centigrade2Fahrenheit(20);

  Serial.begin(9600);
  Serial.println(fahrenheit);

}

void loop() {
  // put your main code here, to run repeatedly:

}

int centigrade2Fahrenheit(int centigrade)
{
  int fahrenheit = centigrade * 9 / 5 + 32;

  return fahrenheit;
}
