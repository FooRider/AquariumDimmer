#ifndef DimmerConfiguration_h
#define DimmerConfiguration_h

#include <Wire.h>
#include <inttypes.h>

class DimmerConfiguration
{
    private:
        uint8_t ds1307Address;

    public:
        DimmerConfiguration(uint8_t ds1307Address);

        unsigned int TurnOnTimeMinutes;
        unsigned short RampUpDurationMinutes;
        unsigned int TurnOffTimeMinutes;
        unsigned short RampDownDurationMinutes;
        unsigned short MaximumIntensity;

        void Load();
        void Save();
};

#endif
