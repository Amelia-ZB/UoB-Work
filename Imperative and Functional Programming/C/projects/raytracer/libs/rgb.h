#ifndef RGB_H
#define RGB_H

#include "vector.h"

#define END   "\033[0m"

#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

typedef struct RGB RGB;

RGB tint(const RGB colour, const float f);
RGB tintVec(const RGB colour, const Vec f);
Vec RGBToVec(const RGB colour);

RGB lerp(const RGB a, const RGB b, const float x);

RGB average_RGB(const RGB* colours, const int n);

void printVec(const char* col, const char* name, const Vec v);
void printRGB(const char* name, const RGB v);




typedef struct VecI VecI;

static void inc_VecI_RGB(VecI *a, const RGB b);
static RGB divide_VecI_int(const VecI a, const int x);

#endif