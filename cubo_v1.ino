	

    //Test an 8x8x8 LED cube
     
    int dataPin = 11;     
    int latchPin = 10;
    int clockPin = 13;

     
    byte pinVals[8];
     int zLayer = 0;
     int xc = 0;
     int yc = 0;
     
    void setup(){
        //layer pins
      for(int i = 2; i < 10; i++)
      {
        pinMode(i, OUTPUT);
        digitalWrite(i, LOW);
      }
     
      pinMode(latchPin, OUTPUT);
      pinMode(clockPin, OUTPUT);
      pinMode(dataPin, OUTPUT);
     
      digitalWrite(latchPin,LOW);
      digitalWrite(dataPin,LOW);
      digitalWrite(clockPin,LOW);
     
      bitSet(pinVals[0], 0);
      digitalWrite(zLayer + 2, HIGH);
    }
     
    void loop(){
      digitalWrite(latchPin, LOW);
      for(int i = 0; i < 8; i++){
       shiftOut(dataPin, clockPin, MSBFIRST, pinVals[i]);
      }
      digitalWrite(latchPin, HIGH);
     
      //Increase for slower effect
      delay(50);
     
      //Set the display bits
      bitClear(pinVals[yc], xc);
      xc++;
      if(xc == 8){
        xc = 0;
        yc++;
        if(yc == 8){
          yc = 0;
          //next z layer
            digitalWrite(zLayer + 2, LOW);
            zLayer++;
            if(zLayer >= 8){
              zLayer = 0;
            }
            digitalWrite(zLayer + 2, HIGH);
        }
      }
      bitSet(pinVals[yc], xc);
    }
