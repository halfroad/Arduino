#include <EEPROM.h>

void setup() {
  // put your setup code here, to run once:

  float temperature = 20.75;

  Serial.println(temperature, 2);

  byte _byte = (int) (temperature * 4);

  Serial.println(_byte);

  EEPROM.write(0, _byte);

  byte _byte_ = EEPROM.read(0);

  Serial.println(_byte_);

  float temperature_ = (float) (_byte_) / 4;

  Serial.begin(9600);
  Serial.println("\n\n\n");

  Serial.println(temperature_);
}

void loop() {
  // put your main code here, to run repeatedly:

}
