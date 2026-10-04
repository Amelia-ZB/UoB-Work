#ifndef RAYS_C
#define RAYS_C

#include "rays.h"
#include "vector.c"
#include "vector.h"
#include "rgb.c"
#include <math.h>
#include <stdio.h>

struct Ray {
    Vec direction;
    Vec origin;
};

struct RayData {
    float intensity;
    Vec newRay;
};

struct Sphere {
    Vec pos;
    RGB colour;
    float specularity;

    float r;
};


RGB calculate(Ray ray, Vec lightRay, Sphere *spheres, int n, int TTL) {

    if (TTL == 0) return (RGB) {0, 0, 0};

    printf("\titteration: %d\n", 3 - TTL);

    float surfaceDistances[n];

    for (int i = 0; i < n; i++) {
        //printf("%d: \n", i);
        Sphere sphere = spheres[i];

        // shortest vector from point to ray
        Vec distanceVec = subtract_vec_vec(subtract_vec_vec(ray.origin, sphere.pos), multiply_float_vec(dotp(subtract_vec_vec(ray.origin, sphere.pos), ray.direction), ray.direction));
        // shortest distance from point to ray
        float distance = magnitude(distanceVec);
        //printf("\tdistance: %f\n", distance);

        if (distance > sphere.r) {
            surfaceDistances[i] = INFINITY;
            //printf("\ttoo far!\n");
        } else {
            // point of closest approach
            Vec closestPoint = add_vec_vec(sphere.pos, distanceVec);

            // point on surface of sphere that the ray hit
            Vec intersectionPoint = subtract_vec_vec(closestPoint, multiply_vec_float(ray.direction, sqrt(sphere.r*sphere.r - distance * distance)));

            float distanceToHit = magnitude(subtract_vec_vec(intersectionPoint, ray.origin));

            //printf("\thit: [%f, %f, %f] ", intersectionPoint.x, intersectionPoint.y, intersectionPoint.z);
            //printf("(%f)\n", distanceToHit);

            surfaceDistances[i] = distanceToHit;
        }

        
    }
    //printf("[%f, %f] - ", surfaceDistances[0], surfaceDistances[1]);

    //int index = min_float_index(surfaceDistances, n);
    int index = (surfaceDistances[0] < surfaceDistances[1]) ? 0 : 1;

    if (surfaceDistances[index] == INFINITY) {
        printf("\t%d: closest sphere: none!\n", 3 - TTL);
        return (RGB) {0, 0, 0};
    }

    printf("\t%d: closest sphere: %d\n", 3 - TTL, index);

    Sphere sphere = spheres[index];

    // shortest vector from point to ray
    Vec distanceVec = subtract_vec_vec(subtract_vec_vec(ray.origin, sphere.pos), multiply_float_vec(dotp(subtract_vec_vec(ray.origin, sphere.pos), ray.direction), ray.direction));
    // shortest distance from point to ray
    float distance = magnitude(distanceVec); // correct

    if (distance > sphere.r) return (RGB) {0, 0, 0}; // too far away

    // point of closest approach
    Vec closestPoint = add_vec_vec(sphere.pos, distanceVec);
    // point on surface of sphere that the ray hit
    Vec intersectionPoint = subtract_vec_vec(closestPoint, multiply_vec_float(ray.direction, sqrt(sphere.r*sphere.r - distance * distance)));

    // normal vector at surface where the ray hit
    Vec normal = normalised(subtract_vec_vec(intersectionPoint, sphere.pos)); // corredt
    // direction of the reflected ray
    Vec reflectedDirection = normalised(subtract_vec_vec(ray.direction, multiply_float_vec(2 * dotp(ray.direction, normal), normal)));
    
    Ray reflectedRay = {reflectedDirection, intersectionPoint};

    
    // diffuse
    float brightness = dotp(lightRay, minus_vec(normal)) / magnitude(normal);
    RGB diffuseColour;

    if (brightness < 0) { // fully in shadow
        diffuseColour = (RGB) {0, 0, 0};
    } else { // visible
        diffuseColour = tint(sphere.colour, brightness);
    }

    // specular
    RGB specularColour = calculate(reflectedRay, lightRay, spheres, n, TTL - 1);

    printf("\t%d: diffuse: (%d, %d, %d)\n", 3 - TTL, diffuseColour.r, diffuseColour.g, diffuseColour.b);
    printf("\t%d: specular: (%d, %d, %d)\n", 3 - TTL, specularColour.r, specularColour.g, specularColour.b);

    return lerp(specularColour, diffuseColour, sphere.specularity);
    


}

RayData sphereTest(Vec pos, float r, Vec lightRay, Vec ray) {

    



    Vec distanceVec = subtract_vec_vec(multiply_float_vec(dotp(pos, ray), ray), pos);
    float distance = magnitude(distanceVec); // correct

    if (distance > r) return (RayData) {0, ray}; // too far away

    Vec closestPoint = add_vec_vec(pos, distanceVec);
    Vec intersectionPoint = subtract_vec_vec(closestPoint, multiply_vec_float(ray, sqrt(r*r - distance * distance)));

    Vec radialRay = normalised(subtract_vec_vec(intersectionPoint, pos)); // corredt
    Vec reflectedRay = normalised(subtract_vec_vec(ray, multiply_float_vec(2 * dotp(ray, radialRay), radialRay)));

    // find angle between -reflected ray and 
    float brightness = dotp(lightRay, minus_vec(radialRay)) / magnitude(radialRay);

    if (brightness < 0) return (RayData) {0, reflectedRay}; // fully in shadow

    printf("%f ", distance);
    printf("rad[%.3f, %.3f, %.3f]  \t", radialRay.x, radialRay.y, radialRay.z);
    printf("ref[%.3f, %.3f, %.3f]  \t", reflectedRay.x, reflectedRay.y, reflectedRay.z);

    float theta = acos(brightness) / 3.1415 * 180;

    return (RayData) {brightness, reflectedRay};
};

int min_float_index(float *arr, int n) {
    int index = 0;
    float min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            index = i;
        }
    }

    return index;
}

#endif