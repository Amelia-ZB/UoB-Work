#include <stdio.h>
#include <math.h>

#include "libs/bmp.c"
#include "libs/vector.c"
#include "libs/rays.c"

#define PI 3.14159265358979323846

#define WIDTH 128
#define HEIGHT 128

#define FOV 90

int main() {
    Image image = make_bmp(WIDTH, HEIGHT);

    // define objects ===========================================

    Sphere spheres[] = {
        {{-64, 0, 128+64}, {255, 255, 255}, 0.5, 64},
        {{64, 0, 128}, {255, 64, 64}, 0, 64},
    };

    // make image ===============================================
    uint8_t *pixelArray = image.imageData + image.headerSize;

    float camera_distance = WIDTH / 2.0 / tan((FOV / 2.0) / 180.0 * PI);

    for (int y = 0; y < image.height; y++){
        unsigned int yOffsettBytes = (image.height - y - 1) * image.rowSize;

        for (int x = 0; x < image.width; x++) {
            unsigned int xOffsettBytes = x * (image.bpp / 8);

            printf("\n(%d, %d): \n", x, y);

            Vec ray = {x - (float) WIDTH / 2, y - (float) HEIGHT / 2, camera_distance};
            normalise(&ray);
            printf("\tRay: [%f, %f, %f]\n", ray.x, ray.y, ray.z);

            RGB colour = calculate((Ray) {ray, {0, 0, 0}}, normalised((Vec) {1, 0, 0}), spheres, 2, 2);

            *(pixelArray + xOffsettBytes + yOffsettBytes + 2) = colour.r;
            *(pixelArray + xOffsettBytes + yOffsettBytes + 1) = colour.g;
            *(pixelArray + xOffsettBytes + yOffsettBytes + 0) = colour.b;
        }

    }

    // save =======================================================
    FILE *fptr;
    fptr = fopen("test.bmp", "wb");
    fwrite(image.imageData, 1, image.size, fptr);
    fclose(fptr);

    free(image.imageData);

    return  1;
}
