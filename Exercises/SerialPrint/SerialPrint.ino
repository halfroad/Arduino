void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(1234);

  int a = 2;
  int b = 3;

  int c = a + b;

  Serial.println(c);

  int degC = 20;
  int degF;

  degF = degC * 9 / 5 + 32;

  Serial.println(degF);
}

void loop() {
  // put your main code here, to run repeatedly:

}
