#include <stdio.h>
#include <stdlib.h>

#define ROOT_MAX 31623
#define MAX 1000000000

int main(int argc, char *argv[]) {
    bool *primes;
    primes = calloc(MAX, sizeof(bool));
    
    primes[0] = true;
    primes[1] = true;

    for (int i = 0; i < ROOT_MAX; i++) {
        if (! primes[i]) {
            for (int j = 2*i; j < MAX; j+= i) {
                primes[j] = true;
            }
        }

    }

    int count = 0;
    int max_prime = 0;

    for (int i = 0; i < MAX; i++) {
        if (! primes[i]) {
            count ++;
            //printf("%d\n", i);
            max_prime = i;
        }
    }

    free(primes);

    printf("found %d primes less than %d\n", count, MAX);
    printf("the largest was: %d\n", max_prime);

}