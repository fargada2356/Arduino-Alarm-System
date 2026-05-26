#include <Arduino.h>
#include "button.h"
#include "LCD.h"
#include "LED.h"
#include "soundSensor.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
LCD myLcd(&lcd);

LED myLed(3, 2);
Button myButton(8);
Sensor mySensor(7);

int systemState = 0;
uint32_t previousMillis = 0;
uint16_t interval = 300;

void setup() {
myLcd.begin();
myLed.begin();
myButton.begin();
mySensor.begin();
}


void loop() {

  uint32_t currentMillis = millis();
  
  
  if(myButton.isPressed(currentMillis) && currentMillis - previousMillis >= interval) {
    if(systemState == 0) {
      systemState = 1;
      myLed.bluePinOn();
    }
    else {
      systemState = 0;
    }
    previousMillis = currentMillis;
  }

  if(systemState == 1) {
    if(mySensor.isSoundDetected()) {
      systemState = 2;
      myLed.redPinOn();
    }
  }

  


  myLcd.updateLCD(systemState);
  myLed.update(systemState);

}