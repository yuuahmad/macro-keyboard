#include <Arduino.h>
#include "Keyboard.h"
#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'},
};

byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
  Serial.begin(9600);
  Keyboard.begin();
}

// This will hold down all the following buttons.
void sendMacroCommand(uint8_t key)
{
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(key);
}

void loop()
{
  char key = keypad.getKey();

  if (key)
  {
    Serial.println(key);
    switch (key)
    {
    case '1':
      Keyboard.print('1');
      //ini volume up
      break;
    case '2':
      Keyboard.print('2');
      //ini volume down
      break;
    case '3':
      Keyboard.print('3');
      //ini mute
      break;
    case '4':
      Keyboard.print('4');
      break;
    case '5':
      Keyboard.print('5');
      break;
    case '6':
      Keyboard.print('6');
      break;
    case '7':
      Keyboard.print('7');
      break;
    case '8':
      Keyboard.print('8');
      break;
    case '9':
      Keyboard.print('9');
      break;
    case '0':
      Keyboard.print('0');
      break;
    case '*':
      Keyboard.print('*');
      break;
    case '#':
      Keyboard.print('#');
      break;
    case 'A':
      Keyboard.print('A');
      break;
    case 'B':
      Keyboard.print('B');
      break;
    case 'C':
      Keyboard.print('C');
      break;
    case 'D':
      Keyboard.print('D');
      break;
    }

    delay(100);
    Keyboard.releaseAll(); // this releases the buttons
  }
}