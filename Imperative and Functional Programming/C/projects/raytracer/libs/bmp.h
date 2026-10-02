#ifndef BMP_H
#define BMP_H

typedef struct RGB RGB;

typedef struct BMPheader BMPheader; // 14 bytes
typedef struct DIBheader DIBheader; // 12 bytes
typedef struct Image Image;


Image make_bmp(const unsigned int width, const unsigned int height);

void setPixel(Image *image, const unsigned int x, const unsigned int y, const RGB colour);



#endif