#ifndef RAYS_C
#define RAYS_C

#include "rays.h"
#include "rgb.h"
#include "vector.c"
#include "rgb.c"
#include <math.h>
#include <stdio.h>

#define MAX_BOUNCES 1

struct Ray {
    Vec direction;
    Vec origin;
    int exclude;
};

struct Sphere {
    Vec pos;
    RGB colour;
    float specularity;

    float r;
};


RGB calculate(Ray ray, Vec lightRay, Sphere *spheres, int n, int TTL) {

    if (TTL == 0) return (RGB) {0, 0, 0};

    tab_pad(TTL + 1);
    printf("\t%siteration %d\033[0m:\n", YELLOW, MAX_BOUNCES + 2 - TTL);

    tab_pad(TTL);
    printVec(MAGENTA, "\tray: \033[0m\tpos", ray.origin);
    tab_pad(TTL);
    printVec(MAGENTA, "\t\033[0m\tdir", ray.direction);
    
    float surfaceDistances[n];

    for (int i = 0; i < n; i++) {

        if (i == ray.exclude) {
            surfaceDistances[i] = INFINITY;
            continue;
        }

        //// printf("%d: \n", i);
        Sphere sphere = spheres[i];

        // shortest vector from point to ray
        Vec distanceVec = subtract_vec_vec(subtract_vec_vec(ray.origin, sphere.pos), multiply_float_vec(dotp(subtract_vec_vec(ray.origin, sphere.pos), ray.direction), ray.direction));
        // shortest distance from point to ray
        float distance = magnitude(distanceVec);
        //// printf("\tdistance: %f\n", distance);

        if (distance > sphere.r) {
            surfaceDistances[i] = INFINITY;
        } else {
            // point of closest approach
            Vec closestPoint = add_vec_vec(sphere.pos, distanceVec);

            // point on surface of sphere that the ray hit
            Vec intersectionPoint = subtract_vec_vec(closestPoint, multiply_vec_float(ray.direction, sqrt(sphere.r*sphere.r - distance * distance)));

            float distanceToHit = magnitude(subtract_vec_vec(intersectionPoint, ray.origin));

            surfaceDistances[i] = distanceToHit;
        }

        
    }

    int index = min_float_index(surfaceDistances, n);

    tab_pad(TTL);
    printf("\t%sdistances%s: [", GREEN, END);
    for (int i = 0; i < n; i++) printf("%s%f%s, ", CYAN, surfaceDistances[i], END);
    printf("]\n");

    tab_pad(TTL);

    if (surfaceDistances[index] == INFINITY) {
        printf("\tclosest: none!\n");
        return (RGB) {0, 0, 0};
    }

    printf("\t%sclosest%s: %s%d%s\n", GREEN, END, GREEN, index, END);
    tab_pad(TTL);
    printf("\n");

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
    Vec normal = normalised(subtract_vec_vec(intersectionPoint, sphere.pos)); // correct
    // direction of the reflected ray
    Vec reflectedDirection = normalised(subtract_vec_vec(ray.direction, multiply_float_vec(2 * dotp(ray.direction, normal), normal)));
    
    Ray reflectedRay = {reflectedDirection, intersectionPoint, index};

    tab_pad(TTL);
    printVec(BLUE, "\tradial", normal);
    
    tab_pad(TTL);
    printVec(MAGENTA, "\tr-ray: \033[0m\tpos", ray.origin);
    tab_pad(TTL);
    printVec(MAGENTA, "\t\033[0m\tdir", ray.direction);
    tab_pad(TTL);
    printf("\n");
    
    // diffuse
    float brightness = dotp(lightRay, minus_vec(normal));
    RGB diffuseColour;

    if (brightness < 0) { // fully in shadow
        diffuseColour = (RGB) {0, 0, 0};
    } else { // visible
        diffuseColour = tint(sphere.colour, brightness);
    }

    // specular
    RGB specularColour = calculate(reflectedRay, lightRay, spheres, n, TTL - 1);
    
    // combine
    RGB colour = lerp(specularColour, diffuseColour, sphere.specularity);

    tab_pad(TTL);
    printRGB("\tdiffuse:  ", diffuseColour);
    tab_pad(TTL);
    printRGB("\tspecular: ", specularColour);
    tab_pad(TTL);
    printRGB("\ttotal:    ", colour);

    tab_pad(TTL + 1);
    printf("\n");



    return colour;
    


}

void tab_pad(int TTL) {
    for (int i = 0; i < MAX_BOUNCES + 2 - TTL; i++) {
        printf("\t%s|%s", YELLOW, END);
    }
}

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