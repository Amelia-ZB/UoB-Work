#include <stdio.h>

int main(void) {
    printf(" 42 + 1 = %d\n", -~42);          /* Right worm (+ 1)          */
    printf(" 42 - 1 = %d\n", ~-42);          /* Left worm (- 1)           */
    printf(" 42 + 3 = %d\n", -~-~-~42);      /* Triple right worm (+ 3)   */
    printf(" 42 - 5 = %d\n", ~-~-~-~-~-42);  /* Quintiple left worm (- 5) */

#define 🪱 -~
#define 🐍 ~-

    printf(" 42 - 3 + 2 = %d\n", 🪱 🪱 🐍 🐍 🐍 42);

    /* Works with negative numbers too! */
    printf("-42 + 5 = %d\n", 🪱 🪱 🪱 🪱 🪱 -42);
}