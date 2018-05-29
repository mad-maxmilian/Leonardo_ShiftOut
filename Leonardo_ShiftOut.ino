/**
 * 
 *  Test code for 2 digit 7 segment display driven by 
 *  two shift registers (TPIC6C595) in series
 *  
 *  Modification of shiftOut example
 *  
 *  @MadMax
 *  
 */

//Pin connected to ST_CP of 74HC595
byte latchPin = 8;
//Pin connected to SH_CP of 74HC595
byte clockPin = 12;
////Pin connected to DS of 74HC595
byte dataPin = 11;


byte segmentArray[17];


void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  segmentArray[0] = B00111111; //0    DECIMAL
  segmentArray[1] = B00000110; //1    |
  segmentArray[2] = B01011011; //2    |
  segmentArray[3] = B01001111; //3    |
  segmentArray[4] = B01100110; //4    |
  segmentArray[5] = B01101101; //5    |
  segmentArray[6] = B01111101; //6    |
  segmentArray[7] = B00000111; //7    |
  segmentArray[8] = B01111111; //8    |
  segmentArray[9] = B01101111; //9    |
  segmentArray[10] = B01110111; //A   HEXADECIMAL
  segmentArray[11] = B01111100; //b   |
  segmentArray[12] = B00111001; //C   |
  segmentArray[13] = B01011110; //d   |
  segmentArray[14] = B01111001; //E   |
  segmentArray[15] = B01110001; //F   |
  segmentArray[16] = B00000000; //OFF SPECIAL

  //test 2s
  write_digits(0,0);
  delay(500);
  write_digits(16,16);
  delay(500);
  write_digits(0,0);
  delay(500);
  write_digits(16,16);
  delay(500);
}


void loop(){
 for (int i = 0; i < 100; i++){
  write99(i);
  delay(500); 
 }
 write_digits(16,16);
 delay(2500);
}

void write99(byte num){
  byte des = 0;
  byte jed = 0;
 
 if(num >=0 && num < 100){
  des = num/10;
  jed = num - (des*10);
  write_digits(jed,des);
 }
  
}

void write_digits(byte cifh, byte cifl){
    if (cifh < 17  && cifh >= 0){
      if (cifl < 17  && cifl >= 0){
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, MSBFIRST, segmentArray[cifh]);
        shiftOut(dataPin, clockPin, MSBFIRST, segmentArray[cifl]);
        digitalWrite(latchPin, HIGH);
        }
    }    
}
