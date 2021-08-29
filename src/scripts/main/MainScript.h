#ifndef SRC_SCRIPTS_MAIN_MAINSCRIPT_H
#define SRC_SCRIPTS_MAIN_MAINSCRIPT_H

#include "../../hardware/AnalogPin.h"
#include "../../hardware/context/ContextScript.h"

namespace scripts {

class MainScript: public hardware::ContextScript {
private:
    hardware::AnalogPin* _moisture_pin;

public:
    MainScript();

    unsigned int getId() override;

    void onInit(hardware::ExecutionContext* context) override;
    void onUpdate(hardware::ExecutionContext* context) override;
};

}

#endif
