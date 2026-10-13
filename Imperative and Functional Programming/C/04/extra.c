#include <limits.h>
#include <stdio.h>

int bitsum(const unsigned int n);

int main() {
    printf("%d\n", bitsum(132));
}

int bitsum (const unsigned int n) {
    int sum = 0;
    for (int i = 0; i < sizeof(unsigned int)*8; i++) {
        sum += (1 << i & n) >> i;
    }
    return sum;
}