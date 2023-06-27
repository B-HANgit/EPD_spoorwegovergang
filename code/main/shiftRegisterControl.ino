// de draden met hun bijhorende pin nummer
const int SH_CP = 10; //verzending draad
const int DS    = 8;  //data / bit draad
const int ST_CP = 9;  //klok draad
const int NROFDISPLAYLEDS = 8;

void shiftRegisterSetup(){
  pinMode(SH_CP, OUTPUT);
  pinMode(DS, OUTPUT);
  pinMode(ST_CP, OUTPUT);
}

void clearShiftRegister(){
digitalWrite(ST_CP, LOW);
  for(int i = 0; i<NROFDISPLAYLEDS; i++){
    digitalWrite(SH_CP,LOW);
    digitalWrite(DS,LOW);   //mag ook voor de for loop want blijft toch 0
    digitalWrite(SH_CP,HIGH);
  }
 digitalWrite(ST_CP,HIGH);
 digitalWrite(ST_CP,LOW);
}

void setShiftRegister(byte pattern){ //B11000110
  digitalWrite(ST_CP, LOW);
  for(int i = 0; i<NROFDISPLAYLEDS; i++){
    digitalWrite(SH_CP,LOW);

    byte editedByte = pattern << i;
    editedByte = editedByte >> (NROFDISPLAYLEDS-1);
    if(editedByte == 1){
       digitalWrite(DS,HIGH);
    } else if(editedByte == 0){
        digitalWrite(DS,LOW);
    }
    digitalWrite(SH_CP,HIGH);
  }
 digitalWrite(ST_CP,HIGH);
 digitalWrite(ST_CP,LOW);
}
