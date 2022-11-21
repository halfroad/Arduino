#include <avr/pgmspace.h>

const int maximum = 6;
PROGMEM const char letters[26][maximum] = {

  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",    // A-I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  // J-R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."          // S-Z

};
PROGMEM const char numbers[10][maximum] = {
  "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."
};
const int dotDelay = 200;
const int ledPin = 13;

void setup() {
  // put your setup code here, to run once:

  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  char ch;
  char sequence[maximum];

  char buffer[maximum];

  if (Serial.available() > 0)
  {
    ch = Serial.read();

    if (ch >= 'a' && ch <= 'z')
    {
      strcpy_P(buffer, (char *) pgm_read_word(&(letters[ch - 'a'])));

      Serial.println(F(buffer));

      memcpy_P(&sequence, letters[ch - 'a'], maximum);
      flashSequence(sequence);
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
      memcpy_P(&sequence, letters[ch - 'A'], maximum);
      flashSequence(sequence);
    }
    else if (ch >= '0' && ch <= '9')
    {
      memcpy_P(&sequence, numbers[ch - '0'], maximum);
      flashSequence(sequence);
    }
    else if (ch == ' ')
    {
      // Gap between words
      delay(dotDelay * 4);
    }
  }
}

void flashSequence(char *sequence)
{
  int i = 0;

  while (sequence[i] != NULL)
  {
    flashDotOrDash(sequence[i]);
    i ++;
  }

  // Gap between letters
  delay(dotDelay * 3);
}

void flashDotOrDash(char dotOrDash)
{
  digitalWrite(ledPin, HIGH);

  if (dotOrDash == '.')
  {
    delay(dotDelay);
  }
  else
  {
    // Must be a dash -
    delay(dotDelay * 3);
  }

  digitalWrite(ledPin, LOW);
  delay(dotDelay);  // Gap between flashes
}