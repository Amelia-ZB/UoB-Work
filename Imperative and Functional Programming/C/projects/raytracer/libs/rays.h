#ifndef RAYS_H
#define RAYS_H

#include "vector.h"
#include "rgb.h"

typedef struct Ray Ray;
typedef struct RayData RayData;
typedef struct Sphere Sphere;

RGB calculate(Ray ray, Vec lightRay, Sphere *spheres, int n, int TTL);

RayData sphereTest(Vec pos, float r, Vec lightRay, Vec ray);



int min_float_index(float *arr, int n);

#endif