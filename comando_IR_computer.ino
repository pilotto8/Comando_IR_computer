#include "IRremote.h"
#include "Keyboard.h"
#include "Mouse.h"
const int vel = 20;
int receiver = 11;
IRrecv irrecv(receiver);
decode_results results;

int led = 0;
int assx = 0;
int assy = 0;
int dir = 0;
unsigned long int r;
void setup() {
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode");
  irrecv.enableIRIn();
  Keyboard.begin();
  Mouse.begin();
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}
char* cont[] {0xFF18E7, 0xFF10EF, 0xFF5AA5, 0xFF4AB5, 0xFFFFFFFF, 0xFF629D, 0xFF22DD, 0xFFC23D, 0xFFA857};
void translateIR() {
  r = results.value;
  if (r != 0xFFFFFFFF) {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
  }
  if (r == 0xFFA25D || r == 3772790473) {
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_F4);
  }
  else if (r == 0xFFE21D || r == 3772786903) {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('d');
  }
  else if (r == 0xFF629D || r == 3772831273) {
    Keyboard.press(KEY_UP_ARROW);
    dir = 5;
  }
  else if (r == 0xFF22DD || r == 3772818013) {
    Keyboard.press(KEY_LEFT_ARROW);
    dir = 6;
  }
  else if (r == 0xFF02FD || r == 3772797613) {
    Keyboard.press(KEY_RETURN);
  }
  else if (r == 0xFFC23D || r == 3772781293) {
    Keyboard.press(KEY_RIGHT_ARROW);
    dir = 7;
  }
  else if (r ==  0xFFE01F) {
    Keyboard.press(KEY_TAB);
  }
  else if (r == 0xFFA857 || r == 3772834333) {
    Keyboard.press(KEY_DOWN_ARROW);
    dir = 8;
  }
  else if (r == 0xFF906F) {
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_TAB);
  }
  else if (r == 0xFF9867 || r == 3772803223) {
    Keyboard.press(KEY_LEFT_GUI);
  }
  else if (r == 0xFFB04F || r == 3772819543) {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('e');
  }
  else if (r == 0xFF6897 || r == 3772793023) {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('x');
    delay(100);
    Keyboard.releaseAll();
    delay(200);
    Keyboard.write('e');
    delay(200);
    Keyboard.print("cmd");
    delay(100);
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.releaseAll();
    delay(600);
    Keyboard.print("shutdown /h");
    delay(100);
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.releaseAll();
  }
  else if (r == 0xFF18E7 || r == 3772778233) {
    Mouse.move(0, -(vel), 0);
    dir = 1;
  }
  else if (r == 0xFF10EF || r == 3772819033) {
    Mouse.move(-(vel), 0, 0);
    dir = 2;
  }
  else if (r == 0xFF38C7 || r == 3772782313) {
    Mouse.press(MOUSE_LEFT);
    delay(50);
    Mouse.release(MOUSE_LEFT);
  }
  else if (r == 0xFF5AA5 || r == 3772794553) {
    Mouse.move(vel, 0, 0);
    dir = 3;
  }
  else if (r == 0xFF4AB5 || r == 3772810873) {
    Mouse.move(0, vel, 0);
    dir = 4;
  }
  else if (r == 0xFFFFFFFF) {
    if (dir != 0) {
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
    }
    switch (dir) {
      case 1: Mouse.move(0, -(vel), 0); break;
      case 2: Mouse.move(-(vel), 0, 0); break;
      case 3: Mouse.move(vel, 0, 0); break;
      case 4: Mouse.move(0, vel, 0); break;
      case 5: Keyboard.press(KEY_UP_ARROW); break;
      case 6: Keyboard.press(KEY_LEFT_ARROW); break;
      case 7: Keyboard.press(KEY_RIGHT_ARROW); break;
      case 8: Keyboard.press(KEY_DOWN_ARROW); break;
    }
  }
  else {
    Serial.println(results.value, HEX);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
  }
  //  switch (results.value) {
  //    case 0xFF30CF: Serial.println("1"); break;
  //    case 0xFF7A85: Serial.println("3"); break;
  //    case 0xFF42BD: Serial.println("7"); break;
  //    case 0xFF52AD: Serial.println("9"); break;
  //  }
  boolean pul = false;
  for (int i = 0; i < 9; i++) {
    if (results.value == cont[i]) {
      pul = true;
      i = 9;
    }
  }
  if (pul == false) {
    dir = 0;
    delay(50);
    Keyboard.releaseAll();
  }
}
void loop() {
  if (irrecv.decode(&results)) {
    translateIR();
    irrecv.resume();
    if (dir == 0) {
      led = 450;
    }
    else {
      led = 10;
    }
  }
  delay(1);
  if (led > 0) {
    led = led - 1;
    if (led == 0) {
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      Keyboard.releaseAll();
    }
  }
}
