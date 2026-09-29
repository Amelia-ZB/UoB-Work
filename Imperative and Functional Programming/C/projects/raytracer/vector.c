#include <math.h>

#include "vector.h"

struct Vec3 {
    float x, y, z;
};




//MARK: misc
Vec3 dotp(const Vec3 a, const Vec3 b) {
    const Vec3 c = {a.x * b.x,
                    a.y * b.y,
                    a.z * b.z};
    return c;
}

Vec3 crossp(const Vec3 a, const Vec3 b) {
    const Vec3 c = {a.y * b.z - a.z * b.y,
                    a.z * b.x - a.x * b.z,
                    a.x * b.y - a.y * b.x};
    return c;
}

float magnitude(const Vec3 a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}
float magnitudeSquared(const Vec3 a) {
    return (a.x * a.x + a.y * a.y + a.z * a.z);
}

Vec3 normalised(const Vec3 a) {
    return divide_vec_float(a, magnitude(a));
}
void normalise(Vec3 *a) {
    *a = divide_vec_float(*a, magnitude(*a));
}




//MARK: addition
static Vec3 add_vec_vec(const Vec3 a, const Vec3 b) {
    const Vec3 c = {a.x + b.x,
                    a.y + b.y,
                    a.z + b.z};
    return c;
}
static Vec3 add_vec_float(const Vec3 a, const float b) {
    const Vec3 c = {a.x + b,
                    a.y + b,
                    a.z + b};
    return c;
}
static Vec3 add_float_vec(const float a, const Vec3 b) {
    const Vec3 c = {a + b.x,
                    a + b.y,
                    a + b.z};
    return c;
}
static Vec3 add_vec_int(const Vec3 a, const int b) {
    const Vec3 c = {a.x + b,
                    a.y + b,
                    a.z + b};
    return c;
}
static Vec3 add_int_vec(const int a, const Vec3 b) {
    const Vec3 c = {a + b.x,
                    a + b.y,
                    a + b.z};
    return c;
}


//MARK: subtraction
static Vec3 subtract_vec_vec(const Vec3 a, const Vec3 b) {
    const Vec3 c = {a.x - b.x,
                    a.y - b.y,
                    a.z - b.z};
    return c;
}
static Vec3 subtract_vec_float(const Vec3 a, const float b) {
    const Vec3 c = {a.x - b,
                    a.y - b,
                    a.z - b};
    return c;
}
static Vec3 subtract_float_vec(const float a, const Vec3 b) {
    const Vec3 c = {a - b.x,
                    a - b.y,
                    a - b.z};
    return c;
}
static Vec3 subtract_vec_int(const Vec3 a, const int b) {
    const Vec3 c = {a.x - b,
                    a.y - b,
                    a.z - b};
    return c;
}
static Vec3 subtract_int_vec(const int a, const Vec3 b) {
    const Vec3 c = {a - b.x,
                    a - b.y,
                    a - b.z};
    return c;
}


//MARK: multiplication
static Vec3 multiply_vec_float(const Vec3 a, const float b) {
    const Vec3 c = {a.x * b,
                    a.y * b,
                    a.z * b};
    return c;
}
static Vec3 multiply_float_vec(const float a, const Vec3 b) {
    const Vec3 c = {a * b.x,
                    a * b.y,
                    a * b.z};
    return c;
}
static Vec3 multiply_vec_int(const Vec3 a, const int b) {
    const Vec3 c = {a.x * b,
                    a.y * b,
                    a.z * b};
    return c;
}
static Vec3 multiply_int_vec(const int a, const Vec3 b) {
    const Vec3 c = {a * b.x,
                    a * b.y,
                    a * b.z};
    return c;
}


//MARK: division
static Vec3 divide_vec_float(const Vec3 a, const float b) {
    const Vec3 c = {a.x / b,
                    a.y / b,
                    a.z / b};
    return c;
}
static Vec3 divide_float_vec(const float a, const Vec3 b) {
    const Vec3 c = {a / b.x,
                    a / b.y,
                    a / b.z};
    return c;
}
static Vec3 divide_vec_int(const Vec3 a, const int b) {
    const Vec3 c = {a.x / b,
                    a.y / b,
                    a.z / b};
    return c;
}
static Vec3 divide_int_vec(const int a, const Vec3 b) {
    const Vec3 c = {a / b.x,
                    a / b.y,
                    a / b.z};
    return c;
}
