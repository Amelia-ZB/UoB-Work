#include <stdio.h>

int stupid_comments() {
    puts("Hello world");
    asm("/*");
    /* Nested comment */
    for (int i = 0; i < 10; i++) puts("I LIKE PANCAKES!");
    asm("*/");
puts("Goodbye world");
}

int assume_optimisations() {
    static int i;
    if (++i > 10) return 0;
    printf("hello cruel world %d\n", i);
    [[gnu::assume(0.99999999999999999 < 1)]]; // tells the compiler that something is true - for optimisation
}

int unicode_variables() {
    int 𝟧 = 4;
    printf("5 = %d\n", 𝟧);
}

#define puts(x...) puts(%:x)

int main() {
    puts(Hello, world!);
}