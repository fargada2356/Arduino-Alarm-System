#ifndef SOUNDSENSOR_H
#define SOUNSENSOR_H

#include <Arduino.h>

class Sensor {

  private:

      uint8_t _pin;


  public:
  
      Sensor(uint8_t pin) : _pin(pin) {}

      void begin() {
        pinMode(_pin, INPUT);
      }

      bool isSoundDetected() {
        return (digitalRead(_pin) == LOW);
      }


};

#endif