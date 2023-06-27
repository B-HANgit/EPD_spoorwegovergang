const int POTMETER_PIN = A0;
const int MIN_POTMETER_VALUE = 0;
const int MAX_POTMETER_VALUE = 1023;
//min-max voor tijd
const int MIN_VALUE = 500;
const int MAX_VALUE = 2000;

//lage waarde = veel tijd
int getTrainSpeedInterval(){
  int input = analogRead(POTMETER_PIN);
  int trainSpeedInterval = map(input, MIN_POTMETER_VALUE, MAX_POTMETER_VALUE, MAX_VALUE, MIN_VALUE);
  if(DEBUG_MODE){
    Serial.print("snelheidinterval = ");
    Serial.println(trainSpeedInterval);
  }
  return trainSpeedInterval;
}
