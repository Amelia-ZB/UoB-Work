#include <stdio.h>

#include "bmp.c"
#include "vector.c"

int main() {
    Image image = make_bmp(3, 3);

    setPixel(&image, 0, 0, 255, 0, 0);
    setPixel(&image, 1, 0, 0, 255, 0);
    setPixel(&image, 2, 0, 0, 0, 255);

    setPixel(&image, 0, 1, 128, 0, 0);
    setPixel(&image, 1, 1, 0, 128, 0);
    setPixel(&image, 2, 1, 0, 0, 128);

    FILE *fptr;
    fptr = fopen("test.bmp", "wb");
    fwrite(image.imageData, 1, image.size, fptr);
    fclose(fptr);

    Vec a = {1, 2, 3};
    Vec b = {4, 5, 6};

    Vec c = add(a, b);

    return  1;
}