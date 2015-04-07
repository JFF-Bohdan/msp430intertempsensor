/*
  Library for MSP430 internal temperature sensor
  https://github.com/JFF-Bohdan/msp430intertempsensor

  The MIT License (MIT)
  
  Copyright (c) 2015 JFF-Bohdan
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#ifndef INTERNALTEMPSENSOR_H
#define INTERNALTEMPSENSOR_H

#define DEFAULT_MEASUREMENTS_QTY 4
#include "Energia.h"

/*!
 * \brief The InternalTempSensor class allows to read temperature from MSP430
 * internal temperature sensor
 */
class InternalTempSensor
{
public:
    InternalTempSensor();

    ~InternalTempSensor();
    
    /*!
     * \brief update updates measurements (average value) and returns last value
     * \param onlyIntegerPart when true will return (and save in buffer) only
     *  integer part, otherwise (when false) returns in this way:     *
     *   23.5 C will be returned as "235" integer value
     *   54.3 C will be returned as "543" integer value*
     *
     * \return last average value
     */
    int32_t update(const boolean onlyIntegerPart = false, const int measurementsQty = DEFAULT_MEASUREMENTS_QTY);
    
    //! returns current temperature as integer value
    int32_t temperature(const boolean onlyIntegerPart = false) const;
    
    //! returns temperature as float value
    float temperatureFloat() const;   
    
private:
    int32_t     m_Average;    
};

extern InternalTempSensor MSPTemp;

#endif //INTERNALTEMPSENSOR_H
