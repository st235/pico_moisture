#include "MainScript.h"

#include <stdio.h>

#include "../../hardware/AnalogPin.h"
#include "../../hardware/context/ExecutionContext.h"

namespace scripts {

MainScript::MainScript(): _moisture_sensor(nullptr) {
}

unsigned int MainScript::getId() {
    return 0;
}

void MainScript::onInit(hardware::ExecutionContext* context) {
    context->enableAnalog();

    this->_moisture_sensor = new domain::MoistureSensor(
        hardware::AnalogPin::from(hardware::AnalogPinId::ADC0),
        1400U /* min current */,
        3500U /* max current */
    );
}

void MainScript::onUpdate(hardware::ExecutionContext* context) {
    double value = this->_moisture_sensor->normalisedValue();
    printf("value: %.2f\n", value);
    context->suspend(500);
}

}
