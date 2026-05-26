#ifndef LED_H
#define LED_H

#include <Arduino.h>

class LED{

  private:

      uint8_t _pin[2];
      uint16_t interval = 200;
      uint32_t previousMillis = 0;


  public:
  
      LED(uint8_t bluePin, uint8_t redPin) {
        _pin[0] = bluePin;
        _pin[1] = redPin;
      } 

      void begin() {
        pinMode(_pin[0], OUTPUT);
        pinMode(_pin[1], OUTPUT);
      }

      void update(int systemState) {
        if(systemState == 2) {
          uint32_t currentMillis = millis();
          if(currentMillis - previousMillis >= interval) {
            previousMillis = currentMillis;
            digitalWrite(_pin[0], !digitalRead(_pin[0]));
            digitalWrite(_pin[1], !digitalRead(_pin[1]));
          }
        }
        else {
          digitalWrite(_pin[0], LOW);
          digitalWrite(_pin[1], LOW);
        }
    }

      void bluePinOn() {
        digitalWrite(_pin[0], HIGH);
      }
      void bluePinOff() {
        digitalWrite(_pin[0], LOW);
      }
      void redPinOn() {
        digitalWrite(_pin[1], HIGH);
      }
      void redPinOff() {
        digitalWrite(_pin[1], LOW);
      }



};

#endif