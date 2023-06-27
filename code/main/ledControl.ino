const int NROFLEDS = 6;
const int LEDPINS[NROFLEDS] = {2, 3, 4, 7, 12, 13};

void ledControlSetup() {
 for (int ledNumber = 0; ledNumber < NROFLEDS; ledNumber++) {
   pinMode(LEDPINS[ledNumber], OUTPUT); 
 } 
}

void ledControlLedOn(int ledNumber){
  ledNumber = constrain(ledNumber, 0, NROFLEDS-1);
  digitalWrite(LEDPINS[ledNumber], HIGH);
}

void ledControlLedOff(int ledNumber){
  ledNumber = constrain(ledNumber, 0, NROFLEDS-1);
  digitalWrite(LEDPINS[ledNumber], LOW); 
}
