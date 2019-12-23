#include "DimmerConfiguration.h"

DimmerConfiguration::DimmerConfiguration(uint8_t ds1307Address)
{
    this->ds1307Address = ds1307Address;
}

void DimmerConfiguration::Load()
{
    Wire.requestFrom(this->ds1307Address, 7);
    this->TurnOnTimeMinutes = (Wire.read() << 8) | Wire.read();
    this->RampUpDurationMinutes = Wire.read();
    this->TurnOffTimeMinutes = (Wire.read() << 8) | Wire.read();
    this->RampDownDurationMinutes = Wire.read();
    this->MaximumIntensity = Wire.read();
}

void DimmerConfiguration::Save()
{
    Wire.beginTransmission(this->ds1307Address);
    Wire.write(0x08);
    Wire.write(this->TurnOnTimeMinutes >> 8);
    Wire.write(this->TurnOnTimeMinutes & 0xFF);
    Wire.write(this->RampUpDurationMinutes);
    Wire.write(this->TurnOffTimeMinutes >> 8);
    Wire.write(this->TurnOffTimeMinutes & 0xFF);
    Wire.write(this->RampDownDurationMinutes);
    Wire.write(this->MaximumIntensity);

    Wire.endTransmission(0);
}
