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

RGB tint(const RGB colour, const float x);

RGB lerp(const RGB a, const RGB b, const float x);

void printVec(const char* col, const char* name, const Vec v);
void printRGB(const char* name, const RGB v);

#endif