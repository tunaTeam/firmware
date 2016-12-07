#include <SoftwareSerial.h>
#define RXD PIN_PD0
#define TXD PIN_PD1
#define greenLedR PIN_PC2
#define greenLedL PIN_PB2
#define yellowLedR PIN_PC1
#define yellowLedL PIN_PB1
#define redLedR PIN_PC0
#define redLedL PIN_PB0

#define rightBTN PIN_PC3
#define leftBTN PIN_PB3

int right,left;
int time = 25;
char status = 'n';

void setup()
{
  pinMode(yellowLedR, OUTPUT);
  pinMode(yellowLedL, OUTPUT);
  pinMode(greenLedR, OUTPUT);
  pinMode(greenLedL, OUTPUT);
  pinMode(redLedR, OUTPUT);
  pinMode(redLedL, OUTPUT);
  pinMode(rightBTN, INPUT_PULLUP);
  pinMode(leftBTN, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.write("start");
  
}
void button_right() {
  right = digitalRead(rightBTN);
  if(right == LOW) {
     digitalWrite(yellowLedR, HIGH);
     Serial.write('r');
   } else {
     digitalWrite(yellowLedR, LOW); 
   }
}
void button_left() {
  left = digitalRead(leftBTN);
   if(left == LOW) {
    digitalWrite(yellowLedL, HIGH);
    Serial.write('l');
   } else {
    digitalWrite(yellowLedL, LOW);
   }
}
void loop()
{
   
   if(Serial.available() > 0) {
     status = Serial.read(); 
   }
   
   
   if(status == 's') {
    button_right();
    button_left();
   }
   
   if(status == 'd') {
    button_right();
    button_left();
    digitalWrite(redLedR, HIGH);
    digitalWrite(redLedL, HIGH);
   } else {
    digitalWrite(redLedR, LOW);
    digitalWrite(redLedL, LOW);
   }

   if(status == 'p') {
    button_right();
    button_left();
    digitalWrite(greenLedR, HIGH);
    digitalWrite(greenLedL, HIGH);
   } else {
    digitalWrite(greenLedR, LOW);
    digitalWrite(greenLedL, LOW);
   }
   
   delay(time);
  
}
