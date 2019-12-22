#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "RTClib.h"

#define DS1307_ADDRESS 0x68

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1

#define ENCODERPIN1 2
#define ENCODERPIN2 3
#define BUTTONPIN 4

volatile int lastEncoderActivity = 0;
volatile int encoderSteps = 0;

byte nvTest = 0;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
RTC_DS1307 rtc;

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.begin(9600);
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  if (!rtc.isrunning())
    rtc.adjust(DateTime(__DATE__, __TIME__));

  {
    Wire.beginTransmission(DS1307_ADDRESS);
    Wire.write(0x08);
    Wire.endTransmission(0);
  
    Wire.requestFrom(DS1307_ADDRESS, 1);
    nvTest = Wire.read() + 1; 

    Wire.beginTransmission(DS1307_ADDRESS);
    Wire.write(0x08);
    Wire.write(nvTest);
    Wire.write(0);
    Wire.endTransmission(0);
  }

  pinMode(ENCODERPIN1, INPUT_PULLUP);
  pinMode(ENCODERPIN2, INPUT_PULLUP);
  pinMode(BUTTONPIN, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(ENCODERPIN1), onEncoderPulse, CHANGE);
}

void onEncoderPulse()
{
  if (digitalRead(ENCODERPIN1) == LOW)
  {
    if (digitalRead(ENCODERPIN2) == LOW)
      lastEncoderActivity = -1;
    else
      lastEncoderActivity = +1;
  }
  else
  {
    if (digitalRead(ENCODERPIN2) == LOW)
    {
      if (lastEncoderActivity == +1)
        encoderSteps++;
    }
    else
    {
      if (lastEncoderActivity == -1)
        encoderSteps--;
    }
    lastEncoderActivity = 0;
  }
}

void loop() {
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.cp437(true);

  display.println(encoderSteps);

  DateTime now = rtc.now();
  display.print(now.year(), DEC);
  display.write('/');
  display.print(now.month(), DEC);
  display.write('/');
  display.print(now.day(), DEC);
  display.write(' ');
  display.print(now.hour(), DEC);
  display.write(':');
  display.print(now.minute(), DEC);
  display.write(':');
  display.print(now.second(), DEC);

  display.println();
  display.print(nvTest, HEX);

  /*int value = encoderSteps;
  if (value >= 0)
    display.write('+');
  else {
    display.write('-');
    value = -encoderSteps;
  }
  
  display.write('0' + ((value / 10000) % 10));
  display.write('0' + ((value / 1000) % 10));
  display.write('0' + ((value / 100) % 10));
  display.write('0' + ((value / 10) % 10));
  display.write('0' + ((value / 1) % 10));*/

  display.display();
}
