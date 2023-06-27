const int BUTTON_STATE_RELEASED = 0;
const int BUTTON_STATE_CHECK_PRESSED = 1;
const int BUTTON_STATE_PRESSED = 2;
const int BUTTON_STATE_CHECK_RELEASED = 3;

//Deze worden gebruikt in buttonControl en overgang mbv getters 
const int BUTTON_NORTH = 0;
const int BUTTON_SOUTH = 1;
const int BUTTON_EAST = 2;
const int BUTTON_WEST = 3;

int buttonStateNorth;
int buttonStateSouth;
int buttonStateEast;
int buttonStateWest;

const int BUTTON_INTERVAL = 10;
unsigned long buttonPrevious;
int buttonsPressed[] = {0, 0, 0, 0};

//extra voor dubbel klik
const int BUTTON_DOUBLE_INTERVAL = 500;
unsigned long buttonDoublePrevious;
int buttonsCounter[] = {0, 0};
int buttonsDoubleActive[] = {0, 0};

// 0 is een geldige knop dus 100 genomen
const int MEMORYBUTTON_DEFAULT = 100;
int memoryButton = MEMORYBUTTON_DEFAULT;
int previousMemoryButton = MEMORYBUTTON_DEFAULT;

void buttonControlSetup() {
  buttonStateNorth = BUTTON_STATE_RELEASED;
  buttonStateSouth = BUTTON_STATE_RELEASED;
  buttonStateEast = BUTTON_STATE_RELEASED;
  buttonStateWest = BUTTON_STATE_RELEASED;
}

int getButtonNorth(){
  return BUTTON_NORTH;
}
int getButtonSouth(){
  return BUTTON_SOUTH;
}
int getButtonEast(){
  return BUTTON_EAST;
}
int getButtonWest(){
  return BUTTON_WEST;
}


int getPreviousMemoryButton(){
  return previousMemoryButton;
}

void setPreviousMemoryButtonReset(){
  previousMemoryButton = MEMORYBUTTON_DEFAULT;
}
int getMemoryButton() {
  return memoryButton;
}

int getButtonPressed(int button) {
  return buttonsPressed[button];
}

void setButtonReset(int button){
  buttonsPressed[button] = 0;
  previousMemoryButton = button;
  if(button == memoryButton){
    memoryButton = MEMORYBUTTON_DEFAULT;
  }
}

void buttonLoop() {
  switch (buttonStateNorth) {
    case BUTTON_STATE_RELEASED:
      buttonReleasedDo(getButtonNorth());
      if (buttonHardwareDown(getButtonNorth())) {
        buttonReleasedExit();
        buttonStateNorth = BUTTON_STATE_CHECK_PRESSED;
        buttonCheckPressedEntry();
      }
      break;
    case BUTTON_STATE_CHECK_PRESSED:
      buttonCheckPressedDo();
      if (buttonHardwareUp(getButtonNorth())) {
        buttonCheckPressedExit();
        buttonStateNorth = BUTTON_STATE_RELEASED;
        buttonReleasedEntry();
      }
      else if ((buttonHardwareDown(getButtonNorth())) && (millis() - buttonPrevious >= BUTTON_INTERVAL)) {
        buttonCheckPressedExit();
        buttonStateNorth = BUTTON_STATE_PRESSED;
        buttonPressedEntry();
      }
      break;
    case BUTTON_STATE_PRESSED:
      buttonPressedDo();
      if (buttonHardwareUp(getButtonNorth())) {
        buttonPressedExit();
        buttonStateNorth = BUTTON_STATE_CHECK_RELEASED;
        buttonCheckReleasedEntry();
      }
      break;
    case BUTTON_STATE_CHECK_RELEASED:
      buttonCheckReleasedDo();
      if (buttonHardwareDown(getButtonNorth())) {
        buttonCheckReleasedExit(getButtonNorth());
        buttonStateNorth = BUTTON_STATE_PRESSED;
        buttonPressedEntry();
      }
      else if ((buttonHardwareUp(getButtonNorth())) && (millis() - buttonPrevious >= BUTTON_INTERVAL)) {
        buttonCheckReleasedExit(getButtonNorth());
        buttonStateNorth = BUTTON_STATE_RELEASED;
        buttonReleasedEntry();
      }
      break;
  }

  switch (buttonStateEast) {
    case BUTTON_STATE_RELEASED:
      buttonReleasedDo(getButtonEast());
      if (buttonHardwareDown(getButtonEast())) {
        buttonReleasedExit();
        buttonStateEast = BUTTON_STATE_CHECK_PRESSED;
        buttonCheckPressedEntry();
      }
      break;
    case BUTTON_STATE_CHECK_PRESSED:
      buttonCheckPressedDo();
      if (buttonHardwareUp(getButtonEast())) {
        buttonCheckPressedExit();
        buttonStateEast = BUTTON_STATE_RELEASED;
        buttonReleasedEntry();
      }
      else if ((buttonHardwareDown(getButtonEast())) && (millis() - buttonPrevious >= BUTTON_INTERVAL)) {
        buttonCheckPressedExit();
        buttonStateEast = BUTTON_STATE_PRESSED;
        buttonPressedEntry();
      }
      break;
    case BUTTON_STATE_PRESSED:
      buttonPressedDo();
      if (buttonHardwareUp(getButtonEast())) {
        buttonPressedExit();
        buttonStateEast = BUTTON_STATE_CHECK_RELEASED;
        buttonCheckReleasedEntry();
      }
      break;
    case BUTTON_STATE_CHECK_RELEASED:
      buttonCheckReleasedDo();
      if (buttonHardwareDown(getButtonEast())) {
        buttonCheckReleasedExit(getButtonEast());
        buttonStateEast = BUTTON_STATE_PRESSED;
        buttonPressedEntry();
      }
      else if ((buttonHardwareUp(getButtonEast())) && (millis() - buttonPrevious >= BUTTON_INTERVAL)) {
        buttonCheckReleasedExit(getButtonEast());
        buttonStateEast = BUTTON_STATE_RELEASED;
        buttonReleasedEntry();
      }
      break;
  }

  switch (buttonStateSouth) {
    case BUTTON_STATE_RELEASED:
      buttonReleasedDo(getButtonSouth());
      if (buttonHardwareDown(getButtonSouth())) {
        buttonReleasedExit();
        buttonStateSouth = BUTTON_STATE_CHECK_PRESSED;
        buttonCheckPressedEntry();
      }
      break;
    case BUTTON_STATE_CHECK_PRESSED:
      buttonCheckPressedDo();
      if (buttonHardwareUp(getButtonSouth())) {
        buttonCheckPressedExit();
        buttonStateSouth = BUTTON_STATE_RELEASED;
        buttonReleasedEntry();
      }
      else if ((buttonHardwareDown(getButtonSouth())) && (millis() - buttonPrevious >= BUTTON_INTERVAL)) {
        buttonCheckPressedExit();
        buttonStateSouth = BUTTON_STATE_PRESSED;
        buttonPressedEntry();
      }
      break;
    case BUTTON_STATE_PRESSED:
      buttonPressedDo();
      if (buttonHardwareUp(getButtonSouth())) {
        buttonPressedExit();
        buttonStateSouth = BUTTON_STATE_CHECK_RELEASED;
        buttonCheckReleasedEntry();
      }
      break;
    case BUTTON_STATE_CHECK_RELEASED:
      buttonCheckReleasedDo();
      if (buttonHardwareDown(getButtonSouth())) {
        buttonCheckReleasedExit(getButtonSouth());
        buttonStateSouth = BUTTON_STATE_PRESSED;
        buttonPressedEntry();
      }
      else if ((buttonHardwareUp(getButtonSouth())) && (millis() - buttonPrevious >= BUTTON_INTERVAL)) {
        buttonCheckReleasedExit(getButtonSouth());
        buttonStateSouth = BUTTON_STATE_RELEASED;
        buttonReleasedEntry();
      }
      break;
  }

  switch (buttonStateWest) {
    case BUTTON_STATE_RELEASED:
      buttonReleasedDo(getButtonWest());
      if (buttonHardwareDown(getButtonWest())) {
        buttonReleasedExit();
        buttonStateWest = BUTTON_STATE_CHECK_PRESSED;
        buttonCheckPressedEntry();
      }
      break;
    case BUTTON_STATE_CHECK_PRESSED:
      buttonCheckPressedDo();
      if (buttonHardwareUp(getButtonWest())) {
        buttonCheckPressedExit();
        buttonStateWest = BUTTON_STATE_RELEASED;
        buttonReleasedEntry();
      }
      else if ((buttonHardwareDown(getButtonWest())) && (millis() - buttonPrevious >= BUTTON_INTERVAL)) {
        buttonCheckPressedExit();
        buttonStateWest = BUTTON_STATE_PRESSED;
        buttonPressedEntry();
      }
      break;
    case BUTTON_STATE_PRESSED:
      buttonPressedDo();
      if (buttonHardwareUp(getButtonWest())) {
        buttonPressedExit();
        buttonStateWest = BUTTON_STATE_CHECK_RELEASED;
        buttonCheckReleasedEntry();
      }
      break;
    case BUTTON_STATE_CHECK_RELEASED:
      buttonCheckReleasedDo();
      if (buttonHardwareDown(getButtonWest())) {
        buttonCheckReleasedExit(getButtonWest());
        buttonStateWest = BUTTON_STATE_PRESSED;
        buttonPressedEntry();
      }
      else if ((buttonHardwareUp(getButtonWest())) && (millis() - buttonPrevious >= BUTTON_INTERVAL)) {
        buttonCheckReleasedExit(getButtonWest());
        buttonStateWest = BUTTON_STATE_RELEASED;
        buttonReleasedEntry();
      }
      break;
  }
}

//----- CHECK_PRESSED -----//
void buttonCheckPressedEntry() {
  buttonPrevious = millis();
}
void buttonCheckPressedDo() {}
void buttonCheckPressedExit() {}

//----- PRESSED -----//
void buttonPressedEntry() {}
void buttonPressedDo() {}
void buttonPressedExit() {}

//----- CHECK_RELEASED -----//
void buttonCheckReleasedEntry() {
  buttonPrevious = millis();
}
void buttonCheckReleasedDo() {}
void buttonCheckReleasedExit(int button) {
  //om voorrang te geven aan eerste die geklikt heeft en om zelfde actie te negeren tijdens actie
  if(memoryButton == MEMORYBUTTON_DEFAULT && button != previousMemoryButton){
    memoryButton = button;
  }

  if(button != previousMemoryButton){
    if(button == getButtonNorth() || button == getButtonSouth()){
      if(button == memoryButton){
        if(buttonsPressed[button] == 0){
          buttonsCounter[button]++;
          if(!buttonsDoubleActive[button]){
            buttonDoublePrevious = millis();
            buttonsDoubleActive[button] = 1;
          }
        }
      }
    } else{ //voor EAST en WEST
      buttonsPressed[button] = 1;
    }
  }
}

//----- RELEASED -----//
void buttonReleasedEntry(){}
void buttonReleasedDo(int button){  
  if(button == getButtonNorth() || button == getButtonSouth()){
    if(button != previousMemoryButton){
      if(buttonsCounter[button] == 1 && (millis() - buttonDoublePrevious >= BUTTON_DOUBLE_INTERVAL)){
        buttonsPressed[button] = 1;
        buttonsCounter[button] = 0;
        buttonsDoubleActive[button] = 0;
      }
      else if (buttonsCounter[button] >= 2 && (millis() - buttonDoublePrevious >= BUTTON_DOUBLE_INTERVAL)){
        buttonsPressed[button] = 2;
        buttonsCounter[button] = 0;
        buttonsDoubleActive[button] = 0;
      }
    }
  }
}
void buttonReleasedExit(){}
