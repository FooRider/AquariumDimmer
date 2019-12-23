#ifndef CurrentStatusScreen_h
#define CurrentStatusScreen_h

#include "Screen.h"

class CurrentStatusScreen : public Screen
{
    public:
        virtual void OnButtonClick();
        virtual void OnEncoderRotate(int steps);
        virtual void Loop();
};

#endif