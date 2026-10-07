#ifndef RAYS_H
#define RAYS_H

#include "vector.h"
#include "rgb.h"

typedef struct Ray Ray;
typedef struct Sphere Sphere;

RGB calculate(const Ray ray, const Vec lightPos, const Sphere *spheres, const int n, const int TTL);
int intersects(const Ray ray, const Sphere* spheres, const int n);

void tab_pad(const int TTL);
int min_float_index(const float *arr, const int n);

#endif