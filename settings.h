#include <Arduino.h>
#include "IRremote.h"
#include "Keyboard.h"
#include "Mouse.h"
#define DECODE_SAMSUNG
#define receiver 11
#define vel 20
#define maxCom 18

enum colours {
  off = 0,
  blue = 8,
  red = 10,
  green = 9
};

// IR
int c, r;
unsigned long int result = 0;
byte command[2][maxCom] {
  {0x6C, 0x16, 0xFF, 0x45, 0x58, 0xFF, 0x2D, 0xFF, 0x1A, 0x4B, 0x15, 0x2, 0x14, 0x60, 0x65, 0x68, 0x62, 0x61},
  {}
};
//if (r == 0xFFA25D || r == 3772790473) {
//    Keyboard.press(KEY_LEFT_ALT);
//    Keyboard.press(KEY_F4);
//  }
//  else if (r == 0xFFE21D || r == 3772786903) {
//    Keyboard.press(KEY_LEFT_GUI);
//    Keyboard.press('d');
//  }
//  else if (r == 0xFF629D || r == 3772831273) {
//    Keyboard.press(KEY_UP_ARROW);
//    dir = 5;
//  }
//  else if (r == 0xFF22DD || r == 3772818013) {
//    Keyboard.press(KEY_LEFT_ARROW);
//    dir = 6;
//  }
//  else if (r == 0xFF02FD || r == 3772797613) {
//    Keyboard.press(KEY_RETURN);
//  }
//  else if (r == 0xFFC23D || r == 3772781293) {
//    Keyboard.press(KEY_RIGHT_ARROW);
//    dir = 7;
//  }
//  else if (r ==  0xFFE01F) {
//    Keyboard.press(KEY_TAB);
//  }
//  else if (r == 0xFFA857 || r == 3772834333) {
//    Keyboard.press(KEY_DOWN_ARROW);
//    dir = 8;
//  }
//  else if (r == 0xFF906F) {
//    Keyboard.press(KEY_LEFT_ALT);
//    Keyboard.press(KEY_TAB);
//  }
//  else if (r == 0xFF9867 || r == 3772803223) {
//    Keyboard.press(KEY_LEFT_GUI);
//  }
//  else if (r == 0xFFB04F || r == 3772819543) {
//    Keyboard.press(KEY_LEFT_GUI);
//    Keyboard.press('e');
//  }
//  else if (r == 0xFF6897 || r == 3772793023) {
//    Keyboard.press(KEY_LEFT_GUI);
//    Keyboard.press('x');
//    delay(100);
//    Keyboard.releaseAll();
//    delay(200);
//    Keyboard.write('e');
//    delay(200);
//    Keyboard.print("cmd");
//    delay(100);
//    Keyboard.press(KEY_RETURN);
//    delay(100);
//    Keyboard.releaseAll();
//    delay(600);
//    Keyboard.print("shutdown /h");
//    delay(100);
//    Keyboard.press(KEY_RETURN);
//    delay(100);
//    Keyboard.releaseAll();
//  }
//  else if (r == 0xFF18E7 || r == 3772778233) {
//    Mouse.move(0, -(vel), 0);
//    dir = 1;
//  }
//  else if (r == 0xFF10EF || r == 3772819033) {
//    Mouse.move(-(vel), 0, 0);
//    dir = 2;
//  }
//  else if (r == 0xFF38C7 || r == 3772782313) {
//    Mouse.press(MOUSE_LEFT);
//    delay(50);
//    Mouse.release(MOUSE_LEFT);
//  }
//  else if (r == 0xFF5AA5 || r == 3772794553) {
//    Mouse.move(vel, 0, 0);
//    dir = 3;
//  }
//  else if (r == 0xFF4AB5 || r == 3772810873) {
//    Mouse.move(0, vel, 0);
//    dir = 4;
//  }
//  else if (r == 0xFFFFFFFF) {
//    if (dir != 0) {
//      digitalWrite(8, HIGH);
//      digitalWrite(9, LOW);
//      digitalWrite(10, LOW);
//    }
