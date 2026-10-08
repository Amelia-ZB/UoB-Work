#ifndef RGB_C
#define RGB_C

#include <stdint.h>
#include <stdio.h>

#include "rgb.h"
#include "vector.c"

struct RGB {
    uint8_t r, g, b;
};

RGB tint(const RGB c, const float f) {
    return (RGB) {c.r * f, c.g * f, c.b * f};
}

RGB lerp(const RGB a, const RGB b, const float x) {
    return (RGB) {a.r * x + b.r * (1 - x),
                  a.g * x + b.g * (1 - x),
                  a.b * x + b.b * (1 - x)};
}

RGB average_RGB(const RGB* colours, const int n) {
    int r = 0, g = 0, b = 0;
    for (int i = 0; i < n; i++) {
        r += colours[i].r;
        g += colours[i].g;
        b += colours[i].b;
    }

    return (RGB) {r/n, g/n, b/n};
}


void printVec(const char* col, const char* name, const Vec v) {
    printf("%s%s\033[0m: [%s%f %f %f\033[0m]\n", col, name, CYAN, v.x, v.y, v.z);
}
void printRGB(const char* name, const RGB c) {
    printf("%s", name);
    printf("\033[48;2;%d;%d;%dm     %s ", c.r, c.g, c.b, END);
    printf("(\033[38;2;255;0;0m%d\033[0m, \033[38;2;0;255;0m%d\033[0m, \033[38;2;0;0;255m%d\033[0m)\n", c.r, c.g, c.b);

}


#endif