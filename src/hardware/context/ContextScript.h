#ifndef SRC_HARDWARE_CONTEXT_CONTEXTSCRIPT_H
#define SRC_HARDWARE_CONTEXT_CONTEXTSCRIPT_H

namespace hardware {

class ExecutionContext;

class ContextScript {
public:
    virtual unsigned int getId() = 0;

    virtual void onInit(ExecutionContext* context) = 0;
    virtual void onUpdate(ExecutionContext* context) = 0;
};

}

#endif
