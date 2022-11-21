#include <EEPROM.h>

void setup() {
  // put your setup code here, to run once:

  int x = 1234;

  EEPROM.write(0, highByte(x));
  EEPROM.write(1, lowByte(x));

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  byte high = EEPROM.read(0);
  byte low = EEPROM.read(1);

  int x = (high << 8) + low;
  int y = high << 8;

  /*

  0000 0000, 0000 0100b << 8
  0000 0100, 0000 0000
  0000 0100, 0000 0000
  0000 0000, 1101 0010

  +

  0000 0100 1101 0010

  */

  Serial.println(y, BIN);

  Serial.println(x);

  delay(1000);

}
