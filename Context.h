#ifndef Context_h
#define Context_h

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#ifndef RTClib_h
#define RTClib_h
#include "RTClib.h"
#endif

class Context
{
    public:
        int EncoderPin1;
        int EncoderPin2;
        int ButtonPin;

        volatile int lastEncoderActivity = 0;
        volatile int encoderSteps = 0;
        byte nvTest;

        //Wire *wire;
        Adafruit_SSD1306 *Display;
        RTC_DS1307 rtc;
};

#endif