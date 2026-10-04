#ifndef RGB_C
#define RGB_C

#include <stdint.h>

#include "rgb.h"

struct RGB {
    uint8_t r, g, b;
};

RGB tint(RGB c, float f) {
    return (RGB) {c.r * f, c.g * f, c.b * f};
}

RGB lerp(RGB a, RGB b, float x) {
    return (RGB) {a.r * x + b.r * (1 - x),
                  a.g * x + b.g * (1 - x),
                  a.b * x + b.b * (1 - x)};
}



#endif