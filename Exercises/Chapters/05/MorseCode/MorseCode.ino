char *letters[] = {

  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",    // A-I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  // J-R
  "...", "-", "..-", "...-", ".--", "-..-", "-.
  --", "--.."          // S-Z

};
char *numbers[] = {

  "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."
};

const int pin = 3;
const int dotDelay = 200;

void setup()
{
  // put your setup code here, to run once:

  pinMode(pin, OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  // put your main code here, to run repeatedly:

  char ch;

  /*

  Some of the rules of Morse code are that a dash is three times as long as a dot,
  the time between each dash or dot is equal to the duration of a dot,
  the space between two letters is the same length as a dash,
  and the space between two words is the same duration as seven dots.
  
  */

  if (Serial.available() > 0)
  {
    ch = Serial.read();

    if (ch >= 'a' && ch <= 'z')
    {
      flashSequence(letters[ch - 'a']);
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
      flashSequence(letters[ch - 'A']);
    }
    else if (ch >= '0' && ch <= '9')
    {
      flashSequence(numbers[ch - '0']);
    }
    else if (ch == ' ')  // Space
    {
      delay(dotDelay * 4); // Gap between words
    }
  }
}

void flashSequence(char *sequence)
{
  int i = 0;

  while (sequence[i] != '\0')
  {
    flashDotOrDash(sequence[i]);

    i ++;
  }

  delay(dotDelay * 3);  // Gap between letetrs
}

void flashDotOrDash(char dotOrDash)
{
  digitalWrite(pin, HIGH);

  if (dotOrDash == '.')
    delay(dotDelay);
  else
  {
    // A dash -: 3 times as long as dot
    delay(dotDelay * 3);
  }

  digitalWrite(pin, LOW);

  // Gap between flashes: the time between each dash or dot is equals to duration of a dot
  delay(dotDelay);
}
