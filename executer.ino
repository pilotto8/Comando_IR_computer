void execute_command(int com) {
  if (com != -1) {
    switch (com) {
      case 0: {
          Keyboard.press(KEY_LEFT_ALT);
          Keyboard.press(KEY_F4);
          break;
        }
      case 1: {
          Keyboard.press(KEY_LEFT_GUI);
          Keyboard.press('d');
          break;
        }
      case 2: {
          Keyboard.press(KEY_UP_ARROW);
          break;
        }
      case 3: {
          Keyboard.press(KEY_LEFT_ARROW);
          break;
        }
      case 4: {
          Keyboard.press(KEY_RETURN);
          break;
        }
      case 5: {
          Keyboard.press(KEY_RIGHT_ARROW);
          break;
        }
      case 6: {
          Keyboard.press(KEY_TAB);
          break;
        }
      case 7: {
          Keyboard.press(KEY_DOWN_ARROW);
          break;
        }
      case 8: {
          Keyboard.press(KEY_LEFT_ALT);
          Keyboard.press(KEY_TAB);
          break;
        }
      case 9: {
          Keyboard.press(KEY_LEFT_GUI);
          break;
        }
      case 10: {
          Keyboard.press(KEY_LEFT_GUI);
          Keyboard.press('e');
          break;
        }
      case 11: {
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
          break;
        }
        case 12: {
          Keyboard.press(KEY_LEFT_GUI);
          delay(100);
          Keyboard.releaseAll();
          delay(100);
          Keyboard.print("C:\Program Files\Google\Chrome Beta\Application\chrome.exe");
          delay(100);
          Keyboard.press(KEY_RETURN);
          break;
        }
      case 13: {
          Mouse.move(0, -(vel), 0);
          break;
        }
      case 14: {
          Mouse.move(-(vel), 0, 0);
          break;
        }
      case 15: {
          Mouse.press(MOUSE_LEFT);
          delay(50);
          Mouse.release(MOUSE_LEFT);
          break;
        }
      case 16: {
          Mouse.move(vel, 0, 0);
          break;
        }
      case 17: {
          Mouse.move(0, vel, 0);
          break;
        }
    }
  }
}
