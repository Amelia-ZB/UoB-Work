#include <stdio.h>

int main(int argc, char *argv[]) {
    short a = 0;
    short* pointer_to_a = &a;
    char* char_pointer_to_a = (char *) pointer_to_a;

    (*(char_pointer_to_a + 1))++;

    printf("%d", a);
}