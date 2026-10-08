#ifndef RAYS_H
#define RAYS_H

#include "vector.h"
#include "rgb.h"
#include "consts.h"

typedef struct Ray Ray;
typedef struct Sphere Sphere;

typedef struct Triangle Triangle;
typedef struct Object Object;

Bool intersection(const Ray ray, const Triangle plane);
RGB bounce(const Ray ray, const Object *objects, const int n, const int TTL);

RGB calculate(const Ray ray, const Vec lightPos, const Sphere *spheres, const int n, const int TTL);
int intersects(const Ray ray, const Sphere* spheres, const int n);

void tab_pad(const int TTL);
int min_float_index(const float *arr, const int n);

#endif