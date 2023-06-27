//int LEDPINS[NROFLEDS] = {2, 3, 4, 7, 12, 13};
//NORTH (0,1,2) -> GROEN,GEEL,ROOD 
//SOUTH  (3,4,5) -> ROOD,GEEL,GROEN

//1Hz -> t=1/f -> 1/1 = 1000ms dus 500ms aan en 500ms uit
const int BLINK_INTERVAL = 500;
unsigned long lightsPrevious;
bool ledOnState = 0;

//NORTH
void setRedLightNorthOn(){
  ledControlLedOn(2);
}
void setRedLightNorthOff(){
  ledControlLedOff(2);
}
void setYellowLightNorthOn(){
  ledControlLedOn(1);
}
void setYellowLightNorthOff(){
  ledControlLedOff(1);
}
void setGreenLightNorthOn(){
  ledControlLedOn(0);
}
void setGreenLightNorthOff(){
  ledControlLedOff(0);
}

//SOUTH
void setRedLightSouthOn(){
  ledControlLedOn(3);
}
void setRedLightSouthOff(){
  ledControlLedOff(3);
}
void setYellowLightSouthOn(){
  ledControlLedOn(4);
}
void setYellowLightSouthOff(){
  ledControlLedOff(4);
}
void setGreenLightSouthOn(){
  ledControlLedOn(5);
}
void setGreenLightSouthOff(){
  ledControlLedOff(5);
}

//Beide verkeerslichten
void setRedLightsOn(){
  setRedLightNorthOn();
  setRedLightSouthOn();
}
void setRedLightsOff(){
  setRedLightNorthOff();
  setRedLightSouthOff();
}
void setYellowLightsOn(){
  setYellowLightNorthOn();
  setYellowLightSouthOn();
}
void setYellowLightsOff(){
  setYellowLightNorthOff();
  setYellowLightSouthOff();
}
void setYellowLightsBlink(){
  if(millis() - lightsPrevious >= BLINK_INTERVAL){
    lightsPrevious = millis();
    if(ledOnState == 0){
     setYellowLightsOff();
     ledOnState = 1;
    } else if(ledOnState == 1){
      setYellowLightsOn();
      ledOnState = 0;
    }
  }
}
