#ifndef Context_h
#define Context_h

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "RTClib.h"

class Context
{
    public:
        int EncoderPin1;
        int EncoderPin2;
        int ButtonPin;

        Wire *wire;
        Adafruit_SSD1306 *Display;
        RTC_DS1307 *rtc;
};

#endif