#include <stdio.h>
#include <math.h>

#define FOUR_THIRDS (4.0 / 3.0)

int main(void){ 

}



int cube(int n) {
    return n*n*n;
}

double sphere(double r) {
    return FOUR_THIRDS * M_PI * r*r;
}

int is_odd(int n){
    return (n%2 == 1);
}
int is_even(int n){
    return (n%2 == 0);
}

int remainder2(int x, int y) {
    return x % y;
}

int factorial(int n) {
    return (n == 1) ? 1 : n * factorial(n - 1);
}

int collatz(int n) {
    int count = 0;
    while (n > 1) {
        count ++;
        printf("%d\n", n);
        n = (n%2 == 0) ? n/2 : 3*n - 1;
    }
    return  count;
}

void collatz_r(int n){
    printf("%d\n", n);
    if (n == 1) return;
    collatz((n%2 == 0) ? n/2 : 3*n - 1);
}