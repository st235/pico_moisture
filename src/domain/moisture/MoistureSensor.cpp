#include "MoistureSensor.h"

#include "../../utils/MathUtils.h"

namespace domain {

MoistureSensor::MoistureSensor(hardware::AnalogPin* pin,
                               unsigned int min_current,
                               unsigned int max_current): _pin(pin), _min_current(min_current), _max_current(max_current) {
}

double MoistureSensor::normalisedValue() const {
    unsigned int intervalLength = _max_current - _min_current;
    unsigned int rawValue = _pin->read();
    unsigned int clampedValue = utils::clamp(rawValue, _min_current, _max_current);
    unsigned int unbiasedValue = clampedValue - _min_current;
    /**
     * we need to inverse value here as max current means less moisture
     * and is supposed to mean open air
     */
    return 1.0 - ((double) unbiasedValue) / ((double) intervalLength);
}

}
