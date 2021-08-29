#include "ExecutionContext.h"

#include "pico/stdlib.h"
#include "hardware/adc.h"

namespace hardware {

ExecutionContext::ExecutionContext(): _scripts() {
}

void ExecutionContext::addScript(ContextScript* script) {
    _scripts[script->getId()] = script;
}

void ExecutionContext::removeScript(unsigned int id) {
    _scripts.erase(id);
}

void ExecutionContext::start() {
    stdio_init_all();

    for (auto const& entry: _scripts) {
        auto* script = entry.second;

        script->onInit(this);
    }

    while (true) {
        for (auto const& entry: _scripts) {
            auto* script = entry.second;
            script->onUpdate(this);
        }
    }
}

void ExecutionContext::enableAnalog() {
    if (!this->_is_analog_enabled) {
        adc_init();
        this->_is_analog_enabled = true;
    }
}

void ExecutionContext::suspend(unsigned int ms_time) {
    sleep_ms(ms_time);
}

}
