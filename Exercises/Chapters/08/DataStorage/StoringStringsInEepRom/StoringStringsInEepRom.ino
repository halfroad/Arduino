#include <avr/eeprom.h>

const int maximumPasswordSize = 20;
char password[maximumPasswordSize];

void setup() {
  // put your setup code here, to run once:

  eeprom_read_block(&password, 0, maximumPasswordSize);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print("Your Password is:");
  Serial.println(password);

  Serial.println("Enter a New Passord:");

  while(!Serial.available())
  {

  };

  int number = Serial.readBytesUntil('\n', password, maximumPasswordSize);
  password[number] = '\0';

  eeprom_write_block(password, 0, maximumPasswordSize);

  Serial.println("Saved Password: ");
  Serial.println(password);
}
