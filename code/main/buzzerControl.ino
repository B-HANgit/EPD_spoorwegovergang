const int BUZZER_PIN = 6;
const int FREQ = 2000;
const int BUZZER_SINGLE_INTERVAL = 250;
const int BUZZER_TRIPPLE_INTERVAL = 100;
const int BUZZER_PAUSE_INTERVAL = 400;

int buzzerCounter;
unsigned long buzzerPrevious;

bool buzzerOnState;

void buzzerSetup(){
  pinMode(BUZZER_PIN, OUTPUT);
  buzzerCounter = 0;
  buzzerOnState = false;
  noTone(BUZZER_PIN);
}

void buzzerOn(){
  tone(BUZZER_PIN,FREQ);
  buzzerOnState = true;
}

void buzzerOff(){
  noTone(BUZZER_PIN);
  buzzerOnState = false;
}

void buzzerStop(){
  buzzerOff();
  buzzerCounter = 0;
}

void buzzerSingle(){
  if(millis() - buzzerPrevious >= BUZZER_SINGLE_INTERVAL){
    buzzerPrevious = millis();
    if(!buzzerOnState){
      buzzerOn();
    } else if(buzzerOnState){
      buzzerOff();
    }
  }
}

void buzzerTripple(){
  if(buzzerCounter < 3 && millis() - buzzerPrevious >= BUZZER_TRIPPLE_INTERVAL){
    buzzerPrevious = millis();
    if(!buzzerOnState){
      buzzerOn();
      buzzerCounter++;
    } else if(buzzerOnState){
      buzzerOff();
    }
  } else if(buzzerCounter == 3 && millis() - buzzerPrevious >= BUZZER_TRIPPLE_INTERVAL){ //om 3e buzz stil te krijgen tijdens pauze
    buzzerOff();
  }
  if(buzzerCounter == 3 && millis() - buzzerPrevious >= BUZZER_PAUSE_INTERVAL && !buzzerOnState){
    buzzerPrevious = millis();
    buzzerCounter = 0;
  }
}
