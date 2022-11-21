char name[] = "Jin Hui";
char *message = "Hello";

char *greet = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  greet = strcat(strcat(name, ", "), message);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(greet);

  delay(1000);

}
