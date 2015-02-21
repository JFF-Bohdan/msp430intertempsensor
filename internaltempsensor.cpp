#include "internaltempsensor.h"

InternalTempSensor::InternalTempSensor(const boolean initialize):
    m_Average(0)
{    
    if(initialize)
        init();
}

InternalTempSensor::~InternalTempSensor()
{
    //
}

void InternalTempSensor::init()
{
    analogReference(INTERNAL1V5);
    pinMode(TEMPSENSOR, INPUT);

    //first measuring contains wrong data
    analogRead(TEMPSENSOR);
}

int32_t InternalTempSensor::update(const boolean onlyIntegerPart, const int measurementsQty)
{
    int i = 0;

    m_Average = 0;
    for(i=0; i<measurementsQty; ++i) {
        // Formula: http://www.43oh.com/forum/viewtopic.php?p=18248#p18248
        m_Average += ((int32_t)analogRead(TEMPSENSOR)*27069 - 18169625) *10 >> 16;
    }

    m_Average = (m_Average / measurementsQty);

    return temperature(onlyIntegerPart);
}

int32_t InternalTempSensor::temperature(const boolean onlyIntegerPart) const
{
    if(onlyIntegerPart)
        return m_Average / 10;

    return m_Average;
}

float InternalTempSensor::temperatureFloat() const
{
    return (float)((m_Average/10)) + (m_Average%10)/10.0;
}

