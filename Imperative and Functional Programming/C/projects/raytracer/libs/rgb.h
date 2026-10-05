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

RGB tint(RGB colour, float x);

RGB lerp(RGB a, RGB b, float x);

void printVec(char* col, char* name, Vec v);
void printRGB(char* name, RGB v);

#endif