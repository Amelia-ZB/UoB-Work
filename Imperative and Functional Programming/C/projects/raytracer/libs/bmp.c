#ifndef BMP_C
#define BMP_C

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdint.h>

#include "bmp.h"
#include "rgb.c"

struct BMPheader {
    uint16_t bfType;      // The header field used to identify the file; it must be BM (the ASCII characters "B" and "M", 0x4D42).
    uint32_t bfSize;      // The size of the BMP file in bytes
    uint16_t bfReserved1; // Reserved; must be zero
    uint16_t bfReserved2; // Reserved; must be zero
    uint32_t bfOffBits;   // The offset, i.e. starting address, of the byte where the bitmap image data (pixel array) can be found.
}__attribute__((__packed__)); // 14 bytes

struct DIBheader {
    uint32_t bcSize;     // The size of this header, in bytes (12)
    uint16_t bcWidth;    // The bitmap width in pixels (unsigned 16-bit)
    uint16_t bcHeight;   // The bitmap height in pixels (unsigned 16-bit)
    uint16_t bcPlanes;   // The number of colour planes (must be 1)
    uint16_t bcBitCount; // The number of bits per pixel
}__attribute__((__packed__)); // 12 bytes

struct Image {
    uint8_t *imageData; // points to start of header

    unsigned int width;
    unsigned int height;

    unsigned int size; // total size in bytes
    unsigned int bpp; // bits per pixel
    unsigned int rowSize; // bytes per row (includes padding)
    unsigned int headerSize; // size of header in bytes
};

Image make_bmp(const unsigned int width, const unsigned int height) {

    // create image struct
    Image image;
    image.width = width;
    image.height = height;
    image.headerSize = sizeof(BMPheader) + sizeof(DIBheader);

    // calculate sizes
    image.bpp = 24; // bits per pixel (R8G8B8)

    image.rowSize = (image.bpp * width + 31) / 32 * 4; // bytes per row (including padding)
    const unsigned int pixelArraySize = image.rowSize * height; // total number of bytes in the pixel array
    image.size = image.headerSize + pixelArraySize; // total number of bytes in the image (including headers)

    // create headers
    BMPheader header1;
    DIBheader header2;

    header1.bfType = 0x4D42; // the ASCII characters "B" and "M"
    header1.bfSize = image.size;
    header1.bfReserved1 = 0;
    header1.bfReserved2 = 0;
    header1.bfOffBits = 14 + 12; // starting offest of pixel array

    header2.bcSize = 12;
    header2.bcWidth = width;
    header2.bcHeight = height;
    header2.bcPlanes = 1;
    header2.bcBitCount = image.bpp;

    // allocate memory
    image.imageData = (uint8_t*) malloc(image.size);

    // copy in data from headers
    memcpy(image.imageData, &header1, sizeof(header1));
    memcpy(image.imageData + sizeof(header1), &header2, sizeof(header2));

    return image;
}

void setPixel(Image *image, const unsigned int x, const unsigned int y, const RGB colour) {
    uint8_t *pixelArray = image->imageData + image->headerSize;

    const unsigned int xOffsettBytes = (image->width - x - 1) * (image->bpp / 8);
    const unsigned int yOffsettBytes = (image->height - y - 1) * image->rowSize;

    *(pixelArray + xOffsettBytes + yOffsettBytes + 0) = colour.r;
    *(pixelArray + xOffsettBytes + yOffsettBytes + 1) = colour.g;
    *(pixelArray + xOffsettBytes + yOffsettBytes + 2) = colour.b;
}

#endif