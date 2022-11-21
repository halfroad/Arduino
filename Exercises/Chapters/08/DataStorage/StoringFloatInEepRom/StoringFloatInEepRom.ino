#include <avr/eeprom.h>

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  float i = 1.2356;

  eeprom_write_block(&i, 0, 4);

  float j = 0.0;

  eeprom_read_block(&j, 0, 4);
  
  Serial.println(j, 4);

}

void loop() {
  // put your main code here, to run repeatedly:

}
