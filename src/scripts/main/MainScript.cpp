#include "MainScript.h"

#include <stdio.h>
#include "../../hardware/context/ExecutionContext.h"

namespace scripts {

MainScript::MainScript(): _moisture_pin(nullptr) {
}

unsigned int MainScript::getId() {
    return 0;
}

void MainScript::onInit(hardware::ExecutionContext* context) {
    context->enableAnalog();

    this->_moisture_pin = hardware::AnalogPin::from(hardware::AnalogPinId::ADC0);
}

void MainScript::onUpdate(hardware::ExecutionContext* context) {
    unsigned int value = this->_moisture_pin->read();
    printf("value: %u\n", value);
    context->suspend(500);
}

}
