#include "MathUtils.h"

namespace utils {

unsigned int min(unsigned int a, unsigned int b) {
    if (a < b) {
        return a;
    }

    return b;
}

unsigned int max(unsigned int a, unsigned int b) {
    if (a > b) {
        return a;
    }

    return b;
}

unsigned int clamp(unsigned int value, unsigned int min_value, unsigned int max_value) {
    return max(min(value, max_value), min_value);
}

}
