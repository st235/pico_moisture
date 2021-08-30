#include "AnalogPin.h"

#include "hardware/adc.h"

namespace {

unsigned int GetGenuinePinIdFromRawId(unsigned int raw_id) {
    switch (raw_id) {
        case 26: return 0;
        case 27: return 1;
        case 28: return 2;
        default: return 0;
    }
}

} // namespace

namespace hardware {

AnalogPin::AnalogPin(unsigned int raw_id): _raw_id(raw_id) {
    this->_genuine_pin_id = GetGenuinePinIdFromRawId(_raw_id);

    adc_gpio_init(_raw_id);
}

unsigned int AnalogPin::read() {
    select();
    return adc_read();
}

void AnalogPin::put(unsigned int value) {
    // empty on purpose
}

void AnalogPin::select() {
    adc_select_input(_genuine_pin_id);
}

AnalogPin* AnalogPin::from(AnalogPinId id) {
    return new AnalogPin((unsigned int)id);
}

} // namespace hardware



