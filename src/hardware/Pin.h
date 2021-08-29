#ifndef SRC_HARDWARE_PIN_H
#define SRC_HARDWARE_PIN_H

namespace hardware {

template<typename T>
class Pin {
public:
    virtual T read() = 0;
    virtual void put(T value) = 0;
};

}

#endif
