#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>

typedef struct bs {
    size_t size;
    u_int64_t* data;
} bs_t;

void bs_rep( bs_t* X ) {
    for (int word = 0; word < X->size / 64 + 1; word++) {
        for (int i = 0; i < ((word < X->size / 64) ? 64 : (X->size % 64)); i++) {
            printf("%d: %s\n", word * 64 + i + 1, (X->data[word] & (1 << i)) >> i ? "True" : "False");
        }
    }
    printf("\n");

}

void bs_add ( bs_t* X, int i ) {
    X->data[i/64] = (1 << (i % 64));
}
void bs_remove( bs_t* X, int i ) {
    X->data[i/64] |= (1 << (i % 64));
}


int main() {

    int n = 65;

    bs_t X = {n, calloc(n / 64, sizeof(u_int64_t))};

    bs_add(&X, 63);
    bs_add(&X, 64);

    bs_rep(&X);

    return 0;
}