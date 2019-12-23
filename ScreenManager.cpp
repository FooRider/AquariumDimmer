#include "ScreenManager.h"

ScreenManager::ScreenManager(Context *context)
{
    this->context = context;

    this->currentStatusScreen = new CurrentStatusScreen(this->context);

    this->CurrentScreenCode = SCR_CURRENTSTATUS;
}

Screen *ScreenManager::GetCurrentScreen()
{
    switch (this->CurrentScreenCode)
    {
        case SCR_CURRENTSTATUS: return this->currentStatusScreen;
        case SCR_SETCURRENTTIME: return this->setCurrentTimeScreen;
        case SCR_SETRAMPUPTIME: return this->setRampUpTimeScreen;
        case SCR_SETRAMPUPDURATION: return this->setRampUpDurationScreen;
        case SCR_SETRAMPDOWNTIME: return this->setRampDownTimeScreen;
        case SCR_SETRAMPDOWNDURATION: return this->setRampDownDurationScreen;
        
        default: return nullptr;
    }
}