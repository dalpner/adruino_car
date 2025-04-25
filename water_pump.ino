#include <IRremote.h>

const int IR_RECEIVE_PIN = 12 ;  // Define the pin number for the IR Sensor

const int A_1B = 5;
const int A_1A = 6;
const int S_4 = 4;

int speed = 150;
bool pump_state = false;

void setup() {
  Serial.begin(9600);

  //motor
  pinMode(A_1B, OUTPUT);
  pinMode(A_1A, OUTPUT);
  pinMode(S_4, OUTPUT);

  //IR remote
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the IR receiver // Start the receiver
  Serial.println("REMOTE CONTROL START");
  analogWrite(S_4, 100);
  delay(500);
  analogWrite(S_4, 0);

  //Start Sound
  analogWrite(S_4, 255);
  delay(250);
  analogWrite(S_4, 0);
  
  //reset pump
  analogWrite(A_1A, 0);
  analogWrite(A_1B, 0);
}

void loop() {

  analogWrite(A_1A, 255);
  //pump();
  //delay(5000);
  if (IrReceiver.decode()) {
    //    Serial.println(results.value,HEX);
    String key = decodeKeyValue(IrReceiver.decodedIRData.command);
    if (key != "ERROR") {
      Serial.println(key);

      if (key == "MUTE") {
        honk();
      } else if (key == "POWER") {
        pump();
        delay(1000);
      }

      if (speed >= 195) {
        speed = 195;
      }
      if (speed <= 0) {
        speed = 0;
      }
    }

    IrReceiver.resume();  // Enable receiving of the next value
  }
}

void honk() {
  analogWrite(S_4, 255);
  delay(500);
  analogWrite(S_4, 0);
}

void pump() {
  if (pump_state){
    analogWrite(A_1A, 255);
    analogWrite(S_4, 255);
    pump_state = false;
  }else{
    analogWrite(A_1A, 0);
    analogWrite(S_4, 0);
    pump_state = true;
  }
}


String decodeKeyValue(long result)
{
  switch(result){
    case 0x16:
      return "0";
    case 0xC:
      return "1"; 
    case 0x18:
      return "2"; 
    case 0x5E:
      return "3"; 
    case 0x8:
      return "4"; 
    case 0x1C:
      return "5"; 
    case 0x5A:
      return "6"; 
    case 0x42:
      return "7"; 
    case 0x52:
      return "8"; 
    case 0x4A:
      return "9"; 
    case 0x9:
      return "+"; 
    case 0x15:
      return "-"; 
    case 0x7:
      return "EQ"; 
    case 0xD:
      return "U/SD";
    case 0x19:
      return "CYCLE";         
    case 0x44:
      return "PLAY/PAUSE";   
    case 0x43:
      return "FORWARD";   
    case 0x40:
      return "BACKWARD";   
    case 0x45:
      return "POWER";   
    case 0x47:
      return "MUTE";   
    case 0x46:
      return "MODE";       
    case 0x0:
      return "ERROR";   
    default :
      return "ERROR";
    }
}