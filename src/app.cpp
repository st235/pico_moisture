#include <stdio.h>

#include "hardware/context/ExecutionContext.h"
#include "scripts/main/MainScript.h"

int main() {
    hardware::ExecutionContext context;

    context.addScript(new scripts::MainScript());
    context.start();

    return 0;
}
