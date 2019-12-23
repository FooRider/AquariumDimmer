#ifndef CurrentStatusScreen_h
#define CurrentStatusScreen_h

#include "Screen.h"
#include "Context.h"

class CurrentStatusScreen : public Screen
{
    public:
        CurrentStatusScreen(Context *context);
        virtual void OnButtonClick();
        virtual void OnEncoderRotate(int steps);
        virtual void Loop();
    
    private:
        Context *context;
};

#endif
