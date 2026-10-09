#include <stdio.h>

int main() {
    signed char a = 64, b = 8, c = 2, result;
    result = (a * b) / c; // promoted result 0x100 truncated to 0
    printf("%hhi\n", result); // 0, since result did not fit char
}

