#ifndef BUTTON_H
#define BUTTON_H
#include <Arduino.h>

class Button {

  private:

      uint8_t _pin;
      uint16_t interval = 20;
      uint8_t previousMillis = 0;


  public:
  
      Button(uint8_t pin) : _pin(pin) {}

      void begin() {
        pinMode(_pin, INPUT_PULLUP);
      }

      bool isPressed(uint32_t currentMillis) {
      if(digitalRead(_pin) == LOW) {
        if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        return true;
      }
    }
    return false;
  }



};


#endif