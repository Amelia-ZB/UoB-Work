#ifndef RAYS_H
#define RAYS_H

#include "vector.h"
#include "rgb.h"

typedef struct Ray Ray;
typedef struct Sphere Sphere;

typedef struct Plane Plane;
typedef struct Object Object;
int /*bool*/ intersection(const Ray ray, const Object object);
RGB bounce(const Ray ray, const Object objects[], const int n, const int TTL);

RGB calculate(const Ray ray, const Vec lightPos, const Sphere *spheres, const int n, const int TTL);
int intersects(const Ray ray, const Sphere* spheres, const int n);

void tab_pad(const int TTL);
int min_float_index(const float *arr, const int n);

#endif