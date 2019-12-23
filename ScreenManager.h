#ifndef ScreenManager_h
#define ScreenManager_h

#include "Screens.h"
#include "Context.h"
#include "CurrentStatusScreen.h"
#include "SetCurrentTimeScreen.h"
#include "SetRampUpTimeScreen.h"
#include "SetRampUpDurationScreen.h"
#include "SetRampDownTimeScreen.h"
#include "SetRampDownDurationScreen.h"

class Context;

class ScreenManager
{
    private:
        Context *context;

        CurrentStatusScreen *currentStatusScreen;
        SetCurrentTimeScreen *setCurrentTimeScreen;
        SetRampUpTimeScreen *setRampUpTimeScreen;
        SetRampUpDurationScreen *setRampUpDurationScreen;
        SetRampDownTimeScreen *setRampDownTimeScreen;
        SetRampDownDurationScreen *setRampDownDurationScreen;

    public:
        int CurrentScreenCode;

        ScreenManager(Context *context);
        Screen *GetCurrentScreen();
};

#endif
