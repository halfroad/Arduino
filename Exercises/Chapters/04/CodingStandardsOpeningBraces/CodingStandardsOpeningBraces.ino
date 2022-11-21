void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  static int count = 0;

  count ++;

  if (count == 20)
  {
    count = 0;

    delay(3000);
  }
}
