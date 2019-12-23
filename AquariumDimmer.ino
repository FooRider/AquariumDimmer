#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#ifndef RTClib_h
#define RTClib_h
#include "RTClib.h"
#endif

#include "Screen.h"
#include "Context.h"
#include "ScreenManager.h"
#include "DimmerConfiguration.h"
#include "CurrentStatusScreen.h"

#define DS1307_ADDRESS 0x68

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1

#define ENCODERPIN1 2
#define ENCODERPIN2 3
#define BUTTONPIN 4

Context context;

void setup() {
  context.Display = new Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

  if (!context.Display->begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.begin(9600);
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  if (!context.rtc.isrunning())
    context.rtc.adjust(DateTime(__DATE__, __TIME__));

  {
    Wire.beginTransmission(DS1307_ADDRESS);
    Wire.write(0x08);
    Wire.endTransmission(0);

    context.Configuration = new DimmerConfiguration(DS1307_ADDRESS);
    context.Configuration->Load();
  }

  pinMode(ENCODERPIN1, INPUT_PULLUP);
  pinMode(ENCODERPIN2, INPUT_PULLUP);
  pinMode(BUTTONPIN, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(ENCODERPIN1), onEncoderPulse, CHANGE);

  context.ScreenManager = new ScreenManager(&context);
}

void onEncoderPulse()
{
  if (digitalRead(ENCODERPIN1) == LOW)
  {
    if (digitalRead(ENCODERPIN2) == LOW)
      context.lastEncoderActivity = -1;
    else
      context.lastEncoderActivity = +1;
  }
  else
  {
    if (digitalRead(ENCODERPIN2) == LOW)
    {
      if (context.lastEncoderActivity == +1)
        context.encoderSteps++;
    }
    else
    {
      if (context.lastEncoderActivity == -1)
        context.encoderSteps--;
    }
    context.lastEncoderActivity = 0;
  }
}

void loop() 
{
  context.ScreenManager->GetCurrentScreen()->Loop();
}
