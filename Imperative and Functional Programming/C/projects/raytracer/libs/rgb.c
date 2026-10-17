#ifndef RGB_C
#define RGB_C

#include <stdint.h>
#include <stdio.h>

#include "rgb.h"
#include "vector.c"

struct RGB {
    uint8_t r, g, b;
};

RGB tint(const RGB colour, const float f) {
    return (RGB) {colour.r * f, colour.g * f, colour.b * f};
}

RGB tintVec(const RGB colour, const Vec f) {
    return (RGB) {colour.r * f.x, colour.g * f.y, colour.b * f.z};
}

Vec RGBToVec(const RGB colour) {
    return (Vec) {(float) colour.r / 255, (float) colour.g / 255, (float) colour.b / 255};
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

RGB clamp_add_RGB(const RGB c1, const RGB c2) {
    int r = c1.r + c2.r;
    int g = c1.g + c2.g;
    int b = c1.b + c2.b;

    r = r > 255 ? 255 : r;
    g = g > 255 ? 255 : g;
    b = b > 255 ? 255 : b;

    return (RGB) {r, g, b};
}


void printVec(const char* col, const char* name, const Vec v) {
    printf("%s%s\033[0m: [%s%f %f %f\033[0m]\n", col, name, CYAN, v.x, v.y, v.z);
}
void printRGB(const char* name, const RGB c) {
    printf("%s", name);
    printf("\033[48;2;%d;%d;%dm     %s ", c.r, c.g, c.b, END);
    printf("(\033[38;2;255;0;0m%d\033[0m, \033[38;2;0;255;0m%d\033[0m, \033[38;2;0;0;255m%d\033[0m)\n", c.r, c.g, c.b);

}







struct VecI {
    int x, y, z;
};

static RGB divide_VecI_int(const VecI a, const int f) {
    return (RGB) {a.x / f, a.y / f, a.z / f};
}

VecI add_VecI_RGB(VecI a, const RGB b) {
    return (VecI) {
        a.x + b.r,
        a.y + b.g,
        a.z + b.b
    };
}

#endif