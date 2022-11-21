#include <avr/eeprom.h>

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  int i = 123;

  eeprom_write_block(&i, 0, 2);

  int j = 0;

  eeprom_read_block(&j, 0, 2);

  Serial.println(j);

}

void loop() {
  // put your main code here, to run repeatedly:

}
