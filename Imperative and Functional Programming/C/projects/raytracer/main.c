#include <stdio.h>
#include <math.h>

#include "libs/bmp.c"
#include "libs/vector.c"
#include "libs/rays.c"

#define PI 3.14159265358979323846

#define WIDTH 256
#define HEIGHT 256

#define FOV 90

int main() {
    Image image = make_bmp(WIDTH, HEIGHT);

    // define objects ===========================================

    Vec pos1 = {0, 0, 256};

    // make image ===============================================
    uint8_t *pixelArray = image.imageData + image.headerSize;

    float camera_distance = WIDTH / 2.0 / tan((FOV / 2.0) / 180.0 * PI);

    for (int y = 0; y < image.height; y++){
        unsigned int yOffsettBytes = (image.height - y - 1) * image.rowSize;

        for (int x = 0; x < image.width; x++) {
            unsigned int xOffsettBytes = x * (image.bpp / 8);

            Vec ray = {x - WIDTH / 2, y - HEIGHT / 2, camera_distance};
            normalise(&ray);

            printf("(%d, %d): [%.3f, %.3f, %.3f]\n", x, y, ray.x, ray.y, ray.z);

            float intensity = sphereTest(pos1, 64, normalised((Vec) {1, 0, 0}), ray).intensity;

            *(pixelArray + xOffsettBytes + yOffsettBytes + 2) = intensity * 255; // ((float) x) / WIDTH * 255;
            *(pixelArray + xOffsettBytes + yOffsettBytes + 1) = intensity * 255; // ((float) y) / HEIGHT * 255;
            *(pixelArray + xOffsettBytes + yOffsettBytes + 0) = intensity * 255;
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
