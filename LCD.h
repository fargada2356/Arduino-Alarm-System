#ifndef LCD_H
#define LCD_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class LCD {

  private:

      LiquidCrystal_I2C* _lcd;


   public:
   
      LCD(LiquidCrystal_I2C* lcd) : _lcd(lcd) {}


      void begin() {
        _lcd->init();
        _lcd->backlight();
      }

      void updateLCD(int currentState) {
        const int STATE_DISARMED = 0;
        const int STATE_ARMED = 1;
        const int STATE_TRIGGERED = 2;
        static int lastState = -1;

        if(currentState == lastState) {
          return; 
        }

        lastState = currentState;
        _lcd->clear();

        switch (currentState) {
          case STATE_DISARMED:
          _lcd->setCursor(0, 0);
          _lcd->print("SYSTEM: DISARMED");
          break;

          case STATE_ARMED:
          _lcd->setCursor(0, 0);
          _lcd->print("SYSTEM: ARMED");
          break;

          case STATE_TRIGGERED:
          _lcd->setCursor(0, 0);
          _lcd->print("INTRUDER!!!");
          break;

        }
      }

      void clear() {
        _lcd->clear();
      }

};


#endif