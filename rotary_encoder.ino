#define CLK 2
#define DT 3
#define SW 4

//for this to make sense, view the timing diagram here: https://howtomechatronics.com/tutorials/arduino/rotary-encoder-works-use-arduino/

int currCLK;
int lastCLK;


void setup() {
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);

  Serial.begin(9600); //starts the serial mointor, the input is the speed of communication
  lastCLK = digitalRead(CLK); 

}

void loop() {
  currCLK = digitalRead(CLK);
  if(currCLK != lastCLK){//if it moved (turned)
    if(currCLK==HIGH){//only operates on the rising edge

      if(digitalRead(DT) != currCLK){
        Serial.println("Clockwise ");
      }
      else{
        Serial.println("CounterClockwise");
      }

    }

  }
  lastCLK = currCLK;

  if(digitalRead(SW)==LOW){
    Serial.println("Clicked");
    delay(300); //so it doesn't register multiple clicks if you accidently hold the button down
    //Note: this unit is in milliseconds
  }



}



  
