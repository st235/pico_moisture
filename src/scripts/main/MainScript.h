#ifndef SRC_SCRIPTS_MAIN_MAINSCRIPT_H
#define SRC_SCRIPTS_MAIN_MAINSCRIPT_H

#include "../../domain/moisture/MoistureSensor.h"
#include "../../hardware/context/ContextScript.h"

namespace scripts {

class MainScript: public hardware::ContextScript {
private:
    domain::MoistureSensor* _moisture_sensor;

public:
    MainScript();

    unsigned int getId() override;

    void onInit(hardware::ExecutionContext* context) override;
    void onUpdate(hardware::ExecutionContext* context) override;
};

}

#endif
