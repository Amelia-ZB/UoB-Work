#include <stdio.h>

int area(int length, int width, int height);


int main(int argc, char *argv[]) {
    int length = 0;
    printf("length: ");
    scanf("%d", &length);
    int width = 0;
    printf("width: ");
    scanf("%d", &width);
    int height = 0;
    printf("height: ");
    scanf("%d", &height);

    int total = area(length, width, height);
    printf("area: %d", total);

}

int area(int length, int width, int height) {

    return 2 * (length + width) * height + length * width;

}

