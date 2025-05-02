#include "Chapter6.h"

int fact(int val) {
    return val > 1 ? val * fact(val - 1) : 1;
}