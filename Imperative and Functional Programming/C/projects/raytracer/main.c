#include <stdio.h>
#include <math.h>

#include "libs/bmp.c"
#include "libs/vector.c"
#include "libs/rays.c"
#include "libs/rgb.h"

#define WIDTH 512
#define HEIGHT 512

#define FOV 90

int main() {
    Image image = make_bmp(WIDTH, HEIGHT);

    // define objects ===========================================
    int num = 3;
    Sphere spheres[] = {
//       position       colour           reflectivity   radius
        // {{0, 2048 + 128, 512}, {255, 255, 255}, 0, 2048},
        // {{0, 0, 512}, {0, 128, 255}, 0, 64},
        {{64, 0, 128},  {255, 64, 64},   0,             64},
        {{-64, 0, 192}, {255, 255, 255}, 0.5,           64},
        {{0, -96, 160}, {0, 255, 0},     0.5,             32},
    };

    Vec light = {-64, 64, 64};

    // make image ===============================================
    uint8_t *pixelArray = image.imageData + image.headerSize;

    float camera_distance = WIDTH / 2.0 / tan((FOV / 2.0) / 180.0 * 3.1415926);

    for (int y = 0; y < image.height; y++){
        unsigned int yOffsettBytes = (image.height - y - 1) * image.rowSize;

        printf("%d / %d\n", y, HEIGHT);

        for (int x = 0; x < image.width; x++) {
            unsigned int xOffsettBytes = x * (image.bpp / 8);

            printf("\n(%d, %d): \n", x, y);

            Vec ray = {x - (float) WIDTH / 2, y - (float) HEIGHT / 2, camera_distance};
            normalise(&ray);
            printVec(MAGENTA, "\tRay", ray);

            RGB colour = calculate((Ray) {ray, {0, 0, 0}, -1}, light, spheres, num, MAX_BOUNCES + 1);
            printRGB("\tcolour: " , colour);

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
