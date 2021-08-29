#ifndef SRC_HARDWARE_CONTEXT_EXECUTIONCONTEXT_H
#define SRC_HARDWARE_CONTEXT_EXECUTIONCONTEXT_H

#include <unordered_map>

#include "ContextScript.h"

namespace hardware {

class ExecutionContext {
private:
    bool _is_analog_enabled = false;
    std::unordered_map<unsigned int, ContextScript*> _scripts;

public:
    explicit ExecutionContext();

    void addScript(ContextScript* script);
    void removeScript(unsigned int script_id);

    void start();

    void enableAnalog();
    void suspend(unsigned int ms_time);
};

}

#endif
