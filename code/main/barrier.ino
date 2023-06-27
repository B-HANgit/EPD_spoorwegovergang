const int LOW_POSITION = 0;
const int HIGH_POSITION = 90;
const int BARRIER_INTERVAL = 50;
const int BARRIER_STEP = 1;
unsigned long barrierPrevious;

bool barrierOpenStatus;
int barrierCounter;

void barrierSetup(){
  setServoPos(HIGH_POSITION);
  barrierPrevious = millis();
  barrierOpenStatus = true;
  barrierCounter = 0;
}

void barrierOpen() {  
  if (getServoPos() < HIGH_POSITION) {
    if (millis() - barrierPrevious >= BARRIER_INTERVAL) {
      setServoPos(getServoPos() + BARRIER_STEP);
      barrierPrevious = millis();
    }
  } else if(getServoPos() >= HIGH_POSITION){
    barrierOpenStatus = true;
    barrierCounter++;
    Serial.print("barrier counter = ");
    Serial.println(barrierCounter);
  }
}

void barrierClose() {
  if (getServoPos() > LOW_POSITION) {
    if (millis() - barrierPrevious >= BARRIER_INTERVAL) {
      setServoPos(getServoPos() - BARRIER_STEP);
      barrierPrevious = millis();
    }
  } else if(getServoPos() <= LOW_POSITION){
    barrierOpenStatus = false;
  }
}

bool getBarrierOpenStatus(){
  return barrierOpenStatus;
}
