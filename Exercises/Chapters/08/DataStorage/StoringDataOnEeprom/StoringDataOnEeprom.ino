#include <EEPROM.h>

int address = 0;
char ch;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  ch = EEPROM.read(address);

}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0)
  {
    ch = Serial.read();

    EEPROM.write(0, ch);

    Serial.println(ch);
  }

  Serial.println(ch);

  delay(1000);

}
