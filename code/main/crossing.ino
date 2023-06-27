//states
const int SETUP = 0;
const int REST = 1;

const int CAR_NORTH = 2;
const int CAR_SOUTH = 3;
const int WALK_NORTH = 4;
const int WALK_SOUTH = 5;

const int NORTH_LEFT = 6;
const int SOUTH_LEFT = 7;

const int TRAIN_DETECTION_REST = 8;
const int TRAIN_DETECTION_NORTH = 9;
const int TRAIN_DETECTION_SOUTH = 10;

const int TRAIN_COMING_NORTH = 11;
const int TRAIN_COMING_SOUTH = 12;

const int TRAIN_CLOSE_CROSSING = 13;
const int TRAIN = 14;
const int TRAIN_OPEN_CROSSING = 15;
const int TRAIN_WAIT = 16;

const int EVACUATION = 17;

int crossingState = SETUP;

//direction
const int NORTH = 0;
const int SOUTH = 1;
const int EAST = 2;
const int WEST = 3;
//const int NONE = 4;
int direction;

const int CAR_INTERVAL = 2000;
const int WALK_INTERVAL = 4000;
const int YELLOW_INTERVAL = 1000;
const int EVACUATION_INTERVAL = 1000;

unsigned long crossingPrevious;

void crossingLoop(){
  switch(crossingState){
    
    case SETUP:
      //crossingSetupEntry();
      crossingSetupDo();
      if(1 == 1){
        crossingSetupExit();
        crossingState = REST;
        crossingRestEntry();
      }
    break;
    
    case REST: 
      crossingRestDo();
      if(getButtonPressed(getButtonEast()) == 1){
        crossingRestExit();
        crossingState = TRAIN_DETECTION_REST;
        direction = EAST;
        crossingTrainDetectionRestEntry();
        break;
      } else if(getButtonPressed(getButtonWest()) == 1){
        crossingRestExit();
        crossingState = TRAIN_DETECTION_REST;
        direction = WEST;
        crossingTrainDetectionRestEntry();
        break;    
      } else if(getMemoryButton() == getButtonNorth()){
        if(getButtonPressed(getButtonNorth()) == 1){
          crossingRestExit();
          crossingState = CAR_NORTH;
          direction = NORTH;
          crossingNorthEntry();
          break;
        } else if(getButtonPressed(getButtonNorth()) == 2){
          crossingRestExit();
          crossingState = WALK_NORTH;
          direction = NORTH;
          crossingNorthEntry();
          break;
         }
      } else if(getMemoryButton() == getButtonSouth()){
        if(getButtonPressed(getButtonSouth()) == 1){
          crossingRestExit();
          crossingState = CAR_SOUTH;
          direction = SOUTH;
          crossingSouthEntry();
          break;
        } else if(getButtonPressed(getButtonSouth()) == 2){
          crossingRestExit();
          crossingState = WALK_SOUTH;
          direction = SOUTH;
          crossingSouthEntry();
          break;
        }
      }
    break;
    
    case CAR_NORTH:
      crossingNorthDo();
      if(millis() - crossingPrevious >= CAR_INTERVAL){
        crossingNorthExit();
        crossingState = NORTH_LEFT;
        crossingNorthLeftEntry();
        break;
      } else if (getButtonPressed(getButtonWest()) == 1){
        crossingNorthExit();
        crossingState = TRAIN_DETECTION_NORTH;
        direction = WEST;
        crossingTrainDetectionNorthEntry();
        break;
       } else if (getButtonPressed(getButtonEast()) == 1){
        crossingNorthExit();
        crossingState = TRAIN_DETECTION_NORTH;
        direction = EAST;
        crossingTrainDetectionNorthEntry();
        break;
      }
    break;
    case CAR_SOUTH:
      crossingSouthDo();
      if(millis() - crossingPrevious >= CAR_INTERVAL){
        crossingSouthExit();
        crossingState = SOUTH_LEFT;
        crossingSouthLeftEntry();
        break;
      } else if (getButtonPressed(getButtonWest()) == 1){
        crossingSouthExit();
        crossingState = TRAIN_DETECTION_SOUTH;
        direction = WEST;
        crossingTrainDetectionSouthEntry();
        break;
      } else if (getButtonPressed(getButtonEast()) == 1){
        crossingSouthExit();
        crossingState = TRAIN_DETECTION_SOUTH;
        direction = EAST;
        crossingTrainDetectionSouthEntry();
        break;
      }
    break;
    
    case WALK_NORTH:
      crossingNorthDo();
      if(millis() - crossingPrevious >= WALK_INTERVAL){
        crossingNorthExit();
        crossingState = NORTH_LEFT;
        crossingNorthLeftEntry();
        break;
      } else if (getButtonPressed(getButtonWest()) == 1){
        crossingNorthExit();
        crossingState = TRAIN_DETECTION_NORTH;
        direction = WEST;
        crossingTrainDetectionNorthEntry();
        break;
       } else if (getButtonPressed(getButtonEast()) == 1){
        crossingNorthExit();
        crossingState = TRAIN_DETECTION_NORTH;
        direction = EAST;
        crossingTrainDetectionNorthEntry();
        break;
      }
    break;
    case WALK_SOUTH:
      crossingSouthDo();
      if(millis() - crossingPrevious >= WALK_INTERVAL){
        crossingSouthExit();
        crossingState = SOUTH_LEFT;
        crossingSouthLeftEntry();
        break;
      } else if (getButtonPressed(getButtonWest()) == 1){
        crossingSouthExit();
        crossingState = TRAIN_DETECTION_SOUTH;
        direction = WEST;
        crossingTrainDetectionSouthEntry();
        break;
      } else if (getButtonPressed(getButtonEast()) == 1){
        crossingSouthExit();
        crossingState = TRAIN_DETECTION_SOUTH;
        direction = EAST;
        crossingTrainDetectionSouthEntry();
        break;
      }
    break;

    case NORTH_LEFT:
     crossingNorthLeftDo();
      if(millis() - crossingPrevious >= YELLOW_INTERVAL){
        if(getButtonPressed(getButtonEast()) == 1){
          crossingNorthLeftExit();
          crossingState = TRAIN_CLOSE_CROSSING;
          direction = EAST;
          crossingTrainCloseCrossingEntry();
          break;
        } else if(getButtonPressed(getButtonWest()) == 1){
          crossingNorthLeftExit();
          crossingState = TRAIN_CLOSE_CROSSING;
          direction = WEST;
          crossingTrainCloseCrossingEntry();
          break;
        } else{
          crossingNorthLeftExit();
          crossingState = EVACUATION;
          //direction = NONE
          crossingEvacuationEntry();
          break;
        }
        break;
      }
    break;
    case SOUTH_LEFT:
      crossingSouthLeftDo();
      if(millis() - crossingPrevious >= YELLOW_INTERVAL){
        if(getButtonPressed(getButtonEast()) == 1){
          crossingSouthLeftExit();
          crossingState = TRAIN_CLOSE_CROSSING;
          direction = EAST;
          crossingTrainCloseCrossingEntry();
          break;
        } else if(getButtonPressed(getButtonWest()) == 1){
          crossingSouthLeftExit();
          crossingState = TRAIN_CLOSE_CROSSING;
          direction = WEST;
          crossingTrainCloseCrossingEntry();
          break;
        } else{
          crossingSouthLeftExit();
          crossingState = EVACUATION;
          //direction = NONE
          crossingEvacuationEntry();
          break;
        }
        break;
      }
    break;

    case EVACUATION:
      crossingEvacuationDo();
      if(millis() - crossingPrevious >= EVACUATION_INTERVAL){
        crossingEvacuationExit();
        crossingState = REST;
        crossingRestEntry();
        break;
      }
    break;

    case TRAIN_DETECTION_REST:
      crossingTrainDetectionRestDo();
      if(millis() - crossingPrevious >= getTrainSpeedInterval()){
        crossingTrainDetectionRestExit();
        crossingState = TRAIN_CLOSE_CROSSING;
        crossingTrainCloseCrossingEntry();
        break;
      }
    break;
    case TRAIN_DETECTION_NORTH:
      crossingTrainDetectionNorthDo();
      if(millis() - crossingPrevious >= getTrainSpeedInterval()){
        crossingTrainDetectionNorthExit();
        crossingState = TRAIN_COMING_NORTH;
        crossingTrainComingNorthEntry();
        break;
      }
    break;
    case TRAIN_DETECTION_SOUTH:
      crossingTrainDetectionSouthDo();
      if(millis() - crossingPrevious >= getTrainSpeedInterval()){
        crossingTrainDetectionSouthExit();
        crossingState = TRAIN_COMING_SOUTH;
        crossingTrainComingSouthEntry();
        break;
      }
    break;

    case TRAIN_COMING_NORTH:
      crossingTrainComingNorthDo();
      if(millis() - crossingPrevious >= YELLOW_INTERVAL){
        crossingTrainComingNorthExit();
        crossingState = TRAIN_CLOSE_CROSSING;
        crossingTrainCloseCrossingEntry();
        break;
      }
    break;
    case TRAIN_COMING_SOUTH:
      crossingTrainComingSouthDo();
      if(millis() - crossingPrevious >= YELLOW_INTERVAL){
        crossingTrainComingSouthExit();
        crossingState = TRAIN_CLOSE_CROSSING;
        crossingTrainCloseCrossingEntry();
        break;
      }
    break;

    case TRAIN_CLOSE_CROSSING:
      crossingTrainCloseCrossingDo();
      if(!getBarrierOpenStatus()){
        crossingTrainCloseCrossingExit();
        crossingState = TRAIN;
        crossingTrainEntry();
        break;
      }
    break;
    case TRAIN:
      crossingTrainDo();
      if(direction == EAST){
        if(getButtonPressed(getButtonWest()) == 1){
          crossingTrainExit();
          crossingState = TRAIN_OPEN_CROSSING;
          direction = WEST;
          crossingTrainOpenCrossingEntry();
          break;
        }
        break;
      } else if(direction == WEST){
        if(getButtonPressed(getButtonEast()) == 1){
          crossingTrainExit();
          crossingState = TRAIN_OPEN_CROSSING;
          direction = EAST;
          crossingTrainOpenCrossingEntry();
          break;
        }
        break;
      }
    break;
    case TRAIN_OPEN_CROSSING:
      crossingTrainOpenCrossingDo();
      if(getBarrierOpenStatus()){
        crossingTrainOpenCrossingExit();
        crossingState = TRAIN_WAIT;
        crossingTrainWaitEntry();
        break;
      }
    break;    
    case TRAIN_WAIT:
      crossingTrainWaitDo();
      if(getDisplayDoneStatus()){
        crossingTrainWaitExit();
        crossingState = REST;
        crossingRestEntry();
        break;
      }
    break;
  }
}

//----- SETUP -----//
void crossingSetupEntry(){}
void crossingSetupDo(){}
void crossingSetupExit(){}

//----- REST -----//
void crossingRestEntry(){
  if(DEBUG_MODE){Serial.println("REST");}
  setRedLightsOn();
  //setPreviousMemoryButtonReset();
  crossingPrevious = millis();
}
void crossingRestDo(){}
void crossingRestExit(){}

//----- NORTH -----//
void crossingNorthEntry(){
  if(DEBUG_MODE){Serial.println("NORTH");}
  setRedLightNorthOff();
  setButtonReset(getButtonNorth());
  setGreenLightNorthOn();
  crossingPrevious = millis();
}
void crossingNorthDo(){}
void crossingNorthExit(){
  setGreenLightNorthOff();
}

//----- NORTH_LEFT -----//
void crossingNorthLeftEntry(){
  if(DEBUG_MODE){Serial.println("NORTH LEFT");}
  setYellowLightNorthOn();
  crossingPrevious = millis();
}
void crossingNorthLeftDo(){}
void crossingNorthLeftExit(){
  setYellowLightNorthOff();
}

//----- SOUTH -----//
void crossingSouthEntry(){
  if(DEBUG_MODE){Serial.println("SOUTH");}
  setRedLightSouthOff();
  setButtonReset(getButtonSouth());
  setGreenLightSouthOn();
  crossingPrevious = millis();
}
void crossingSouthDo(){}
void crossingSouthExit(){
  setGreenLightSouthOff();
}

//----- SOUTH_LEFT -----//
void crossingSouthLeftEntry(){
  if(DEBUG_MODE){Serial.println("SOUTH LEFT");}
  setYellowLightSouthOn();
  crossingPrevious = millis();
}
void crossingSouthLeftDo(){}
void crossingSouthLeftExit(){
  setYellowLightSouthOff();
}

//----- EVACUATION -----//
void crossingEvacuationEntry(){
  if(DEBUG_MODE){Serial.println("EVACUATION");}
  setRedLightsOn();
  setPreviousMemoryButtonReset();
  crossingPrevious = millis();
}
void crossingEvacuationDo(){}
void crossingEvacuationExit(){}

//----- TRAIN_DETECTION_NORTH -----//
void crossingTrainDetectionNorthEntry(){
  if(DEBUG_MODE){Serial.println("DETECT NORTH");}
  setGreenLightNorthOn();
  if(direction == EAST){
    setButtonReset(getButtonEast());
  } else if(direction == WEST){
    setButtonReset(getButtonWest());
  }
  crossingPrevious = millis();
}
void crossingTrainDetectionNorthDo(){}
void crossingTrainDetectionNorthExit(){
  setGreenLightNorthOff();
}

//----- TRAIN_DETECTION_SOUTH -----//
void crossingTrainDetectionSouthEntry(){
  if(DEBUG_MODE){Serial.println("DETECT SOUTH");}
  setGreenLightSouthOn();
  if(direction == EAST){
    setButtonReset(getButtonEast());
  } else if(direction == WEST){
    setButtonReset(getButtonWest());
  }
  crossingPrevious = millis();
}
void crossingTrainDetectionSouthDo(){}
void crossingTrainDetectionSouthExit(){
  setGreenLightSouthOff();
}

//----- TRAIN_DETECTION_REST -----//
void crossingTrainDetectionRestEntry(){
  if(DEBUG_MODE){Serial.println("DETECT REST");}
  setRedLightsOn();
  if(direction == EAST){
    setButtonReset(getButtonEast());
  } else if(direction == WEST){
    setButtonReset(getButtonWest());
  }
  crossingPrevious = millis();
}
void crossingTrainDetectionRestDo(){}
void crossingTrainDetectionRestExit(){
  setRedLightsOff();
}

//----- TRAIN_COMING_NORTH -----//
void crossingTrainComingNorthEntry(){
  if(DEBUG_MODE){Serial.println("TRAIN COMING NORTH");}
  setYellowLightNorthOn();
  crossingPrevious = millis();
}
void crossingTrainComingNorthDo(){}
void crossingTrainComingNorthExit(){
  setYellowLightNorthOff();
}

//----- TRAIN_COMING_SOUTH -----//
void crossingTrainComingSouthEntry(){
  if(DEBUG_MODE){Serial.println("TRAIN COMING SOUTH");}
  setYellowLightSouthOn();
  crossingPrevious = millis();
}
void crossingTrainComingSouthDo(){}
void crossingTrainComingSouthExit(){
  setYellowLightSouthOff();
}

//----- TRAIN_CLOSE_CROSSING -----//
void crossingTrainCloseCrossingEntry(){
  if(DEBUG_MODE){Serial.println("TRAIN CLOSE CROSSING");}
  if(direction == EAST){
    setButtonReset(getButtonEast());
  } else if(direction == WEST){
    setButtonReset(getButtonWest());
  }
  setRedLightsOn();
}
void crossingTrainCloseCrossingDo(){
  setYellowLightsBlink();
  barrierClose();
  buzzerSingle();
}
void crossingTrainCloseCrossingExit(){
  buzzerStop();
}

//----- TRAIN -----//
void crossingTrainEntry(){
  if(DEBUG_MODE){Serial.println("TRAIN");}
}
void crossingTrainDo(){
  setYellowLightsBlink();
}
void crossingTrainExit(){}

//----- TRAIN_OPEN_CROSSING -----//
void crossingTrainOpenCrossingEntry(){
  if(DEBUG_MODE){Serial.println("TRAIN OPEN CROSSING");}
  if(direction == EAST){
    setButtonReset(getButtonEast());
  } else if(direction == WEST){
    setButtonReset(getButtonWest());
  }
}
void crossingTrainOpenCrossingDo(){
  setYellowLightsBlink();
  barrierOpen();
  buzzerSingle();
}
void crossingTrainOpenCrossingExit(){
  buzzerStop();
}

//----- TRAIN_WAIT -----//
void crossingTrainWaitEntry(){
  if(DEBUG_MODE){Serial.println("TRAIN WAIT");}
}
void crossingTrainWaitDo(){
  setYellowLightsBlink();
  displayCounter5To0();
  buzzerTripple();
}
void crossingTrainWaitExit(){
  displayCounterReset();
  buzzerStop();
  setYellowLightsOff();
}
