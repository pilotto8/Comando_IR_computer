int translateIR(){
  result = IrReceiver.decodedIRData.command;
  for(r = 0; r < 1; r++){
    for(c = 0; c < maxCom; c++){
      if(result == command[r][c]){
        led(green);
        return c;
      }
    }
  }
  Serial.println(result, HEX);
  led(red);
  return -1;
}
