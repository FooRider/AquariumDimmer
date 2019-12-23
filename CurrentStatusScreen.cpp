#include "CurrentStatusScreen.h"

CurrentStatusScreen::CurrentStatusScreen(Context *context)
{
    this->context = context;
}

void CurrentStatusScreen::OnButtonClick()
{

}

void CurrentStatusScreen::OnEncoderRotate(int steps)
{

}

void CurrentStatusScreen::Loop()
{
    context->Display->clearDisplay();

    context->Display->setTextSize(1);
    context->Display->setTextColor(WHITE);
    context->Display->setCursor(0, 0);
    context->Display->cp437(true);

    context->Display->println(this->context->encoderSteps);

    DateTime now = context->rtc.now();
    context->Display->print(now.year(), DEC);
    context->Display->write('/');
    context->Display->print(now.month(), DEC);
    context->Display->write('/');
    context->Display->print(now.day(), DEC);
    context->Display->write(' ');
    context->Display->print(now.hour(), DEC);
    context->Display->write(':');
    context->Display->print(now.minute(), DEC);
    context->Display->write(':');
    context->Display->print(now.second(), DEC);

    context->Display->println();
    context->Display->print(context->nvTest, HEX);

    context->Display->display();
}
