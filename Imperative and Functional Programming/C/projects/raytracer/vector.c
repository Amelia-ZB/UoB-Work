#include <math.h>

#include "vector.h"

struct Vec {
    float x, y, z;
};

struct Mat {
    Vec x, y, z;
};


//MARK: misc
Vec dotp(const Vec a, const Vec b) {
    const Vec c = {a.x * b.x,
                    a.y * b.y,
                    a.z * b.z};
    return c;
}

Vec crossp(const Vec a, const Vec b) {
    const Vec c = {a.y * b.z - a.z * b.y,
                    a.z * b.x - a.x * b.z,
                    a.x * b.y - a.y * b.x};
    return c;
}

float magnitude(const Vec a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}
float magnitudeSquared(const Vec a) {
    return (a.x * a.x + a.y * a.y + a.z * a.z);
}

Vec normalised(const Vec a) {
    return divide_vec_float(a, magnitude(a));
}
void normalise(Vec *a) {
    *a = divide_vec_float(*a, magnitude(*a));
}

float determenant(const Mat a){
    return a.x.x * (a.y.y * a.z.z - a.y.z * a.z.y) -
           a.x.y * (a.y.x * a.z.z - a.y.z * a.z.x) +
           a.x.z * (a.y.x * a.z.y - a.y.y * a.z.x);
}
Mat inverse(const Mat a){
    const float invDet = 1 / determenant(a);
    return multiply(a, invDet);

}




//MARK: addition
static Vec add_vec_vec(const Vec a, const Vec b) {
    const Vec c = {a.x + b.x,
                    a.y + b.y,
                    a.z + b.z};
    return c;
}
static Vec add_vec_float(const Vec a, const float b) {
    const Vec c = {a.x + b,
                    a.y + b,
                    a.z + b};
    return c;
}
static Vec add_float_vec(const float a, const Vec b) {
    const Vec c = {a + b.x,
                    a + b.y,
                    a + b.z};
    return c;
}
static Vec add_vec_int(const Vec a, const int b) {
    const Vec c = {a.x + b,
                    a.y + b,
                    a.z + b};
    return c;
}
static Vec add_int_vec(const int a, const Vec b) {
    const Vec c = {a + b.x,
                    a + b.y,
                    a + b.z};
    return c;
}

static Mat add_mat_mat(const Mat a, const Mat b) {
    Vec t1 = a.x;
    Vec t2 = b.x;
    Vec t3 = add(t1, t2);

    const Mat c = {add(a.x, b.x),
                   add(a.y, b.y),
                   add(a.z, b.z)};
    return c;
}
static Mat add_mat_float(const Mat a, const float b) {
    const Mat c = {add(a.x, b),
                   add(a.y, b),
                   add(a.z, b)};
    return c;
}
static Mat add_float_mat(const float a, const Mat b) {
    const Mat c = {a + b.x,
                    a + b.y,
                    a + b.z};
    return c;
}
static Mat add_mat_int(const Mat a, const int b) {
    const Mat c = {a.x + b,
                    a.y + b,
                    a.z + b};
    return c;
}
static Mat add_int_mat(const int a, const Mat b) {
    const Mat c = {a + b.x,
                    a + b.y,
                    a + b.z};
    return c;
}



//MARK: subtraction
static Vec subtract_vec_vec(const Vec a, const Vec b) {
    const Vec c = {a.x - b.x,
                    a.y - b.y,
                    a.z - b.z};
    return c;
}
static Vec subtract_vec_float(const Vec a, const float b) {
    const Vec c = {a.x - b,
                    a.y - b,
                    a.z - b};
    return c;
}
static Vec subtract_float_vec(const float a, const Vec b) {
    const Vec c = {a - b.x,
                    a - b.y,
                    a - b.z};
    return c;
}
static Vec subtract_vec_int(const Vec a, const int b) {
    const Vec c = {a.x - b,
                    a.y - b,
                    a.z - b};
    return c;
}
static Vec subtract_int_vec(const int a, const Vec b) {
    const Vec c = {a - b.x,
                    a - b.y,
                    a - b.z};
    return c;
}


//MARK: multiplication
static Vec multiply_vec_float(const Vec a, const float b) {
    const Vec c = {a.x * b,
                    a.y * b,
                    a.z * b};
    return c;
}
static Vec multiply_float_vec(const float a, const Vec b) {
    const Vec c = {a * b.x,
                    a * b.y,
                    a * b.z};
    return c;
}
static Vec multiply_vec_int(const Vec a, const int b) {
    const Vec c = {a.x * b,
                    a.y * b,
                    a.z * b};
    return c;
}
static Vec multiply_int_vec(const int a, const Vec b) {
    const Vec c = {a * b.x,
                    a * b.y,
                    a * b.z};
    return c;
}


//MARK: division
static Vec divide_vec_float(const Vec a, const float b) {
    const Vec c = {a.x / b,
                    a.y / b,
                    a.z / b};
    return c;
}
static Vec divide_float_vec(const float a, const Vec b) {
    const Vec c = {a / b.x,
                    a / b.y,
                    a / b.z};
    return c;
}
static Vec divide_vec_int(const Vec a, const int b) {
    const Vec c = {a.x / b,
                    a.y / b,
                    a.z / b};
    return c;
}
static Vec divide_int_vec(const int a, const Vec b) {
    const Vec c = {a / b.x,
                    a / b.y,
                    a / b.z};
    return c;
}
