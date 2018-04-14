#include <TM1637Display.h>
#define CLK 9 //can be any digital pin
#define DIO 8 //can be any digital pin

TM1637Display display(CLK, DIO);

int potPin = A0;    // select the input pin for the potentiometer
int potVal = 0;
int oldPotVal;
int printVal;
int oldPrintVal;


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  display.setBrightness(5);
}

void loop() {
  potVal = analogRead(potPin);
  if (potVal < (oldPotVal - 4) || potVal > (oldPotVal + 4)) {
    oldPotVal = potVal;
    printVal = map(oldPotVal,1023, 0, 0, 1000);
    if (printVal != oldPrintVal){
      Serial.println(potVal);
      display.showNumberDec(printVal, false);
      oldPrintVal = printVal;
    }
  }
}

