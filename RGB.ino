void led(byte colour){
  switch (colour){
    case blue:{
      digitalWrite(blue, 1);
      digitalWrite(red, 0);
      digitalWrite(green, 0);
      break;
    }
    case red:{
      digitalWrite(blue, 0);
      digitalWrite(red, 1);
      digitalWrite(green, 0);
      break;
    }
    case green:{
      digitalWrite(blue, 0);
      digitalWrite(red, 0);
      digitalWrite(green, 1);
      break;
    }
    case off:{
      digitalWrite(blue, 0);
      digitalWrite(red, 0);
      digitalWrite(green, 0);
      break;
    }
  }
}
