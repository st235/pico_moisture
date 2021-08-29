#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/adc.h"

#include "hardware/AnalogPin.h"

int main() {
    stdio_init_all();

    adc_init();

    hardware::AnalogPin* pin = hardware::AnalogPin::from(hardware::AnalogPinId::ADC0);

    while (true) {
        unsigned int value = pin->read();
        printf("value: %u\n", value);
        sleep_ms(500);
    }

    return 0;
}
