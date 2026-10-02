#ifndef RAYS_C
#define RAYS_C

#include "rays.h"
#include "vector.c"
#include "vector.h"

struct RayData {
    float intensity;
};


RayData sphereTest(Vec pos, float r, Vec lightRay, Vec ray) {

    float distance = magnitude(subtract_vec_vec(multiply_float_vec(dotp(pos, ray), ray), pos));

    if (distance > r) return (RayData) {0};

    Vec radialRay = subtract_vec_vec(multiply_vec_float(ray, distance), pos);
    Vec reflectedRay = subtract_vec_vec(ray, multiply_float_vec(2 * dotp(ray, radialRay), radialRay));

    float intensity = dotp(lightRay, minus_vec(reflectedRay)) / magnitude(reflectedRay);

    float temp = acos(intensity) / 3.1415 * 180;

    return (RayData) {intensity};
};


#endif