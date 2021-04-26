#include "settings.h"

void setup() {
  IrReceiver.begin(11, DISABLE_LED_FEEDBACK, USE_DEFAULT_FEEDBACK_LED_PIN);
  Keyboard.begin();
  Mouse.begin();
  Serial.begin(9600);
}

void loop() {
  if (IrReceiver.decode()) {
    execute_command(translateIR());
    IrReceiver.resume();
    if (c < maxCom - 4){
      delay(200);
    }
    led(off);
    Keyboard.releaseAll();
  }
}
