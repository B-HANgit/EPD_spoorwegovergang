const int NROFNUMBERS = 6;
const int DISPLAY_INTERVAL = 1000;
unsigned long displayPrevious;
bool displayDoneStatus;
int displayCounter;
//hex 0-5
const int HEXNR[NROFNUMBERS] = {B00111111, B00000110, B01011011, B01001111, B01100110, B01101101};

void displaySetup(){
  displayPrevious = millis();
  clearShiftRegister();
  displayCounter = NROFNUMBERS; //NROFNUMBERS-1;
  displayDoneStatus = false;
}

bool getDisplayDoneStatus(){
  return displayDoneStatus;  
}

void displayCounter5To0(){
  if(millis() - displayPrevious >= DISPLAY_INTERVAL){
    displayPrevious = millis();
    if(displayCounter>0){
      clearShiftRegister();
      setShiftRegister(HEXNR[displayCounter]);
      displayCounter--;
      } else if(displayCounter == 0){
      displayDoneStatus = true;
    }
  }
}

void displayCounterReset(){
  clearShiftRegister();
  displayCounter = NROFNUMBERS;
  displayDoneStatus = false;
}
