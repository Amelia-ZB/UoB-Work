#ifndef RGB_H
#define RGB_H


typedef struct RGB RGB;

RGB tint(RGB colour, float x);

RGB lerp(RGB a, RGB b, float x);


#endif