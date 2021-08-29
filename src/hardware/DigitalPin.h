#ifndef SRC_HARDWARE_DIGITALPIN_H
#define SRC_HARDWARE_DIGITALPIN_H

#include "./Pin.h"

namespace hardware {

enum class DigitalPinId: unsigned int {
    GP0 = 0,
    GP1 = 1,
    GP2 = 2,
    GP3 = 3,
    GP4 = 4,
    GP5 = 5,
    GP6 = 6,
    GP7 = 7,
    GP8 = 8,
    GP9 = 9,
    GP10 = 10,
    GP11 = 11,
    GP12 = 12,
    GP13 = 13,
    GP14 = 14,
    GP15 = 15,
    GP16 = 16,
    GP17 = 17,
    GP18 = 18,
    GP19 = 19,
    GP20 = 20,
    GP21 = 21,
    GP22 = 22,
    GP23 = 23,
    GP24 = 24,
    GP25 = 25,
    GP26 = 26,
    GP27 = 27,
    GP28 = 28
};

enum class DigitalValue {
    LOW,
    HIGH
};

class DigitalPin: public Pin<DigitalValue> {
private:
    unsigned int _raw_id;

    DigitalPin(unsigned int raw_id);

public:
    DigitalValue read() override;
    void put(DigitalValue value) override;

    static DigitalPin fromId(DigitalPinId id);
};

}

#endif
