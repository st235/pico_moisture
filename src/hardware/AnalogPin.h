#ifndef SRC_HARDWARE_ANALOGPIN_H
#define SRC_HARDWARE_ANALOGPIN_H

#include "Pin.h"

namespace hardware {

enum class AnalogPinId: unsigned int {
    ADC0 = 26,
    ADC1 = 27,
    ADC2 = 28
};

class AnalogPin: public Pin<unsigned int> {
private:
    unsigned int _raw_id;
    unsigned int _genuine_pin_id;

    explicit AnalogPin(unsigned int raw_id);

public:
    unsigned int read() override;
    void put(unsigned int value) override;

    void select();

    static AnalogPin* from(AnalogPinId id);
};

}

#endif
