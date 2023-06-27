const bool DEBUG_MODE = 1;
//const bool DEBUG_MODE = 0;

void setup() {
  Serial.begin(9600);
  buttonHardwareSetup();
  buttonControlSetup();
  ledControlSetup();
  servoSetup();
  barrierSetup();
  shiftRegisterSetup();
  displaySetup();
  buzzerSetup();
  if(DEBUG_MODE){Serial.println("-----SYSTEM_READY-----");}
}

void loop() {
  crossingLoop();
  buttonLoop();

  if(DEBUG_MODE){
  Serial.print(getButtonPressed(0));
  Serial.print(getButtonPressed(1));
  Serial.print(getButtonPressed(2));
  Serial.print(getButtonPressed(3));
  Serial.print("  ");
  Serial.print(getMemoryButton());
  Serial.print("  ");
  Serial.print(getPreviousMemoryButton());
  Serial.println(""); 
  }
}
