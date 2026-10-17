#ifndef RAYS_C
#define RAYS_C

#include "rays.h"
#include "rgb.h"
#include "vector.c"
#include "rgb.c"
#include "consts.h"

#include <math.h>
#include <stdio.h>
#include <float.h>
#include <stdlib.h>

struct Ray {
    Vec direction;
    Vec origin;
    int exclude;
};

struct Sphere {
    Vec pos;
    RGB colour;
    float specularity;
    Bool emissive;

    float r;
};

RGB calculate_sphere(const Ray ray, const Vec lightPos, const Sphere *const spheres, const int n, const int TTL) {

    if (TTL == 0) return BACKGROUND;

    #ifdef DEBUG
    tab_pad(TTL + 1);
    printf("\t%siteration %d\033[0m:\n", YELLOW, MAX_BOUNCES + 2 - TTL);

    tab_pad(TTL);
    printVec(MAGENTA, "\tray: \033[0m\tpos", ray.origin);
    tab_pad(TTL);
    printVec(MAGENTA, "\t\033[0m\tdir", ray.direction);


    tab_pad(TTL);
    printf("\t%sLambdas:\033[0m\n", BLUE);
    #endif

    float surfaceDistances[n];

    for (int i = 0; i < n; i++) {

        if (i == ray.exclude) {
            surfaceDistances[i] = INFINITY;
            continue;
        }

        // printf("%d: \n", i);
        Sphere sphere = spheres[i];

        // lambda at closest approach
        float lambda = dotp(subtract_vec_vec(ray.origin, sphere.pos), ray.direction);

        #ifdef DEBUG
        tab_pad(TTL);
        printf("\t\t%d\033[0m: %s%f\n", i, CYAN, lambda);
        #endif

        if (lambda > 0) {
            surfaceDistances[i] = INFINITY;
        } else {

            // shortest vector from point to ray
            Vec distanceVec = subtract_vec_vec(subtract_vec_vec(ray.origin, sphere.pos), multiply_float_vec(lambda, ray.direction));
            // shortest distance from point to ray
            float distance = magnitude(distanceVec);
            // printf("\tdistance: %f\n", distance);

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
    }

    int sphereIndex = min_float_index(surfaceDistances, n);

    #ifdef DEBUG
    tab_pad(TTL);
    printf("\t%sdistances%s: [%s", GREEN, END, CYAN);
    for (int i = 0; i < n; i++) printf("%f ", surfaceDistances[i]);
    printf("%s]\n", END);

    tab_pad(TTL);
    #endif

    if (surfaceDistances[sphereIndex] == INFINITY) {
        #ifdef DEBUG
        printf("\tclosest: none!\n");
        #endif
        return BACKGROUND;
    }

    #ifdef DEBUG
    printf("\t%sclosest%s: %s%d%s\n", GREEN, END, GREEN, sphereIndex, END);
    tab_pad(TTL);
    printf("\n");
    #endif

    Sphere sphere = spheres[sphereIndex];

    // shortest vector from point to ray
    Vec distanceVec = subtract_vec_vec(subtract_vec_vec(ray.origin, sphere.pos), multiply_float_vec(dotp(subtract_vec_vec(ray.origin, sphere.pos), ray.direction), ray.direction));
    // shortest distance from point to ray
    float distance = magnitude(distanceVec); // correct

    if (distance > sphere.r) return BACKGROUND; // too far away

    // point of closest approach
    Vec closestPoint = add_vec_vec(sphere.pos, distanceVec);
    // point on surface of sphere that the ray hit
    Vec intersectionPoint = subtract_vec_vec(closestPoint, multiply_vec_float(ray.direction, sqrt(sphere.r*sphere.r - distance * distance)));

    // normal vector at surface where the ray hit
    Vec normal = normalised(subtract_vec_vec(intersectionPoint, sphere.pos)); // correct
    // direction of the reflected ray
    Vec reflectedDirection = normalised(subtract_vec_vec(ray.direction, multiply_float_vec(2 * dotp(ray.direction, normal), normal)));

    Ray reflectedRay = {reflectedDirection, intersectionPoint, sphereIndex};

    #ifdef DEBUG
    tab_pad(TTL);
    printVec(BLUE, "\tradial", normal);

    tab_pad(TTL);
    printVec(MAGENTA, "\tr-ray: \033[0m\tpos", ray.origin);
    tab_pad(TTL);
    printVec(MAGENTA, "\t\033[0m\tdir", ray.direction);
    tab_pad(TTL);
    printf("\n");
    #endif

    // specular
    // RGB specularColour;
    // if (sphere.specularity > 0) {

    //     RGB samples[SAMPLES];

    //     specularColour = calculate_sphere(reflectedRay, lightPos, spheres, n, TTL - 1);

    //     #ifdef DEBUG
    //     tab_pad(TTL);
    //     printf("\n");
    //     #endif

    // } else {
    //     specularColour = BACKGROUND;
    // }



    Ray lightRay = {subtract_vec_vec(lightPos, intersectionPoint), intersectionPoint, sphereIndex};

    RGB directLightColour;
    if (intersects(lightRay, spheres, n)) {
        // in shadow
        directLightColour = BACKGROUND;
    } else {
        float brightness = dotp(normalised(lightRay.direction), normal);

        if (brightness < 0) { // on the back half of the sphere from the light
            directLightColour = BACKGROUND;
        } else { // visible
            directLightColour = (RGB) {255*brightness, 255*brightness, 255*brightness};
        }
    }


    RGB lightColour;
    if (TTL == 1) { // cheating
        lightColour = directLightColour;

    } else if (sphere.specularity == 1) {
        lightColour = calculate_sphere(reflectedRay, lightPos, spheres, n, TTL - 1);
    } else {
        int diffuseSamples = SAMPLES * (1.0f - sphere.specularity);
        //printf("%f: %d\n", sphere.specularity, diffuseSamples);

        VecI lightSamples = {0};
        for (int i = 0; i < diffuseSamples; i++) {
            Ray sampleRay = {
                randomDirection(normal, ray.direction),
                reflectedRay.origin,
                reflectedRay.exclude
            };

            RGB sampleLightColour = calculate_sphere(sampleRay, lightPos, spheres, n, TTL - 1); // Problem here!!!!
            // printf("\t[%f, %f, %f]\n", sampleRay.direction.x, sampleRay.direction.y, sampleRay.direction.z);

            lightSamples = add_VecI_RGB(lightSamples, sampleLightColour);
        }
        // printf("%d, %d, %d\n", lightSamples.x, lightSamples.y, lightSamples.z);
        lightColour = divide_VecI_int(lightSamples, diffuseSamples);
        lightColour = clamp_add_RGB(lightColour, directLightColour);

        if (sphere.specularity > 0) {
            RGB specularColour = calculate_sphere(reflectedRay, lightPos, spheres, n, TTL - 1);
            lightColour = lerp(lightColour, specularColour, (float) diffuseSamples / SAMPLES);
        }

    }

    // diffuse

    // if (intersects(lightRay, spheres, n)) {
    //     // in shadow
    //     diffuseColour = BACKGROUND;

    // } else {
    //     float brightness = dotp(normalised(lightRay.direction), normal);

    //     #ifdef DEBUG
    //     tab_pad(TTL);
    //     printVec(GREEN, "\tl-ray\033[0m: \tpos", lightRay.origin);
    //     tab_pad(TTL);
    //     printVec(GREEN, "\t     \033[0m  \tdir", lightRay.direction);

    //     tab_pad(TTL);
    //     printf("\t%sbrightness\033[0m: %s%f\033[0m\n", GREEN, BLUE, brightness);
    //     #endif


    //     if (brightness < 0) { // on the back half of the sphere from the light
    //         diffuseColour = BACKGROUND;
    //     } else { // visible
    //         diffuseColour = sphere.colour;
    //     }
    // }


    // combine
    RGB colour = tintVec(sphere.colour, RGBToVec(lightColour));
    // RGB colour = {
    //     (diffuseColour.r + lightColour.r) / 2,
    //     (diffuseColour.g + lightColour.g) / 2,
    //     (diffuseColour.b + lightColour.b) / 2,
    // };
    // RGB colour = lightColour;

    #ifdef DEBUG
    tab_pad(TTL);
    printRGB("\tdiffuse:  ", diffuseColour);
    tab_pad(TTL);
    printRGB("\tspecular: ", specularColour);
    tab_pad(TTL);
    printRGB("\ttotal:    ", colour);

    tab_pad(TTL + 1);
    printf("\n");
    #endif

    return colour;


}

Vec randomDirection(const Vec normal, const Vec helper) {
    // find 2 tangents
    Vec tang1 = normalised(crossp(normal, helper));
    Vec tang2 = normalised(crossp(normal, tang1));

    // printf("tangent1: [%f, %f, %f]\n", tang1.x, tang1.y, tang1.z);
    // printf("tangent2: [%f, %f, %f]\n", tang2.x, tang2.y, tang2.z);

    // generate random values
    float sin_theta = sqrt((float)rand()/(float)RAND_MAX);
    float cos_theta = sqrt(1-sin_theta*sin_theta);

    // printf("sin: %f\n", sin_theta);
    // printf("cos: %f\n", cos_theta);

    // random in plane angle
    float psi = (float)rand()/(float)RAND_MAX * 2.0f * M_PI;

    // three vector components
    float a = sin_theta*cos(psi);
    float b = sin_theta*sin(psi);
    float c = cos_theta;

    // multiply by corresponding directions
    Vec v1 = multiply_vec_float(tang1, a);
    Vec v2 = multiply_vec_float(tang2, b);
    Vec v3 = multiply_vec_float(normal, c);


    // add up to get velocity, vel=v1+v2+v3
    Vec vel = {
        v1.x + v2.x + v3.x,
        v1.y + v2.y + v3.y,
        v1.z + v2.z + v3.z,
    };

    return vel;
}

int intersects(const Ray ray, const Sphere* spheres, const int n) {

    _Bool intersect = 0;

    for (int i = 0; i < n && !intersect; i++) {

        if (i != ray.exclude) {
            Sphere sphere = spheres[i];

            // lambda at closest approach
            float lambda = dotp(subtract_vec_vec(ray.origin, sphere.pos), normalised(ray.direction));

            if (lambda < 0) {

                // shortest vector from point to ray
                Vec distanceVec = subtract_vec_vec(subtract_vec_vec(ray.origin, sphere.pos), multiply_float_vec(lambda, normalised(ray.direction)));
                // shortest distance from point to ray
                float distance = magnitude(distanceVec);
                // printf("\tdistance: %f\n", distance);

                if (distance <= sphere.r) {

                    // point of closest approach
                    Vec closestPoint = add_vec_vec(sphere.pos, distanceVec);

                    // point on surface of sphere that the ray hit
                    Vec intersectionPoint = subtract_vec_vec(closestPoint, multiply_vec_float(normalised(ray.direction), sqrt(sphere.r*sphere.r - distance * distance)));

                    float distanceToHit = magnitude(subtract_vec_vec(intersectionPoint, ray.origin));

                    intersect = distanceToHit < magnitude(ray.direction);
                }
            }
        }
    }

    return intersect;
}




float randomfloat(void) {
    float r = (float) rand() / (float) RAND_MAX;
    return r;
}



void tab_pad(const int TTL) {
    for (int i = 0; i < MAX_BOUNCES + 2 - TTL; i++) {
        printf("\t%s|%s", YELLOW, END);
    }
}

int min_float_index(const float *arr, const int n) {
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