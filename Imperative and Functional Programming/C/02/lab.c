#include <stdio.h>

int square(int n);
double interest(double ammount, double interestRate);



int main(void) {
    int n = 0;
    printf("enter a number: ");
    scanf("%d", &n);
    printf("%d squared is %d\n", n, square(n));

    double x, y;
    printf("enter an ammount of money: £");
    scanf("%lf", &x);
    printf("enter an interest rate in percent: ");
    scanf("%lf", &y);
    printf("the new ammount is £%.2f\n", interest(x, y / 100));
    // dont need %lf, floats are automaticaly promoted to doubles in a variadic printf function

    return 0;
}

int square(int n) {
    return n*n;
}

double interest(double ammount, double interestRate) {
    return ammount * (1 + interestRate);
}