#ifndef RAYS_H
#define RAYS_H

#include "vector.h"

typedef struct RayData RayData;

RayData sphereTest(Vec pos, float r, Vec lightRay, Vec ray);

#endif