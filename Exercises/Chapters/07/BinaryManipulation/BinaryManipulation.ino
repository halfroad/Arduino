void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  int x = 0x8c; // 0b1000 1100

  int bit = bitRead(x, 3);

  Serial.println(sizeof(bit));
  Serial.println(bit);

  delay(500);
  
  bitWrite(x, 4, 1);

  Serial.println(x, HEX);

  delay(500);

}
