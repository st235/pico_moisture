#ifndef SRC_DOMAIN_MOISTURE_MOISTURESENSOR_H
#define SRC_DOMAIN_MOISTURE_MOISTURESENSOR_H

#include "../../hardware/AnalogPin.h"

namespace domain {

class MoistureSensor {
private:
    hardware::AnalogPin* const _pin; 

    unsigned int const _min_current;
    unsigned int const _max_current;

public:
    MoistureSensor(hardware::AnalogPin* pin,
                   unsigned int min_current,
                   unsigned int max_current);

    MoistureSensor(MoistureSensor const& sensor) = delete;
    MoistureSensor& operator=(MoistureSensor const& sensor) = delete;

    double normalisedValue() const;
};

}

#endif
