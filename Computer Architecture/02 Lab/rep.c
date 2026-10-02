/* Copyright (C) 2017 Daniel Page <csdsp@bristol.ac.uk>
 *
 * Use of this source code is restricted per the CC BY-NC-ND license, a copy of 
 * which can be found via http://creativecommons.org (and should be included as 
 * LICENSE.txt within the associated archive or repository).
 */

#include "rep.h"
#include <stddef.h>
#include <stdio.h>

/** This function prints the binary representation of the integer x: iterating
    * over 0 <= i < n where n = |x|, i.e., the number of bits in said x, in each 
    * iteration it extracts then prints the i-th bit of x.
    */

void rep( int16_t x ) {
    printf( "%4d_{(10)} = ", x );

    for( int i = ( BITSOF( x ) - 1 ); i >= 0; i-- ) {
        printf( "%d", ( x >> i ) & 1 );
    }

    printf( "_{(2)}\n" );
}

/** The main function, acting as an entry point for the program: 
    * it attempts to test each function defined above, invoking it using a set of 
    * test cases.
    */

size_t max(size_t a, size_t b) {
    return (a > b) ? a : b;
}

int main( int argc, char* argv[] ) {
    int8_t t;

    t =        0; rep( t );
    t =     +1; rep( t );
    t =     -1; rep( t );
    t = +127; rep( t );
    t = -128; rep( t );

    // Q2
    printf("%d is %d\n", 20, sign(20));
    printf("%d is %d\n\n", -20, sign(-20));

    printf("negative %d is %d\n", 20, neg(20));
    printf("negative %d is %d\n\n", -20, neg(-20));

    for (int pow = 0; pow < 8; pow++) {
        printf("%d mod %d = %d (%d)\n", 107, 1 << pow, mod(107, pow), 107 % (1 << pow));
    }
    
    // Q3
    uint8_t x = 23;
    uint8_t y = 75;

    int size = max(sizeof(x), sizeof(y)) * 8;

    bool X[size], Y[size], R[size];

    int2seq(X, x);
    int2seq(Y, y);
    add_seq(R, X, Y, size);

    printf("%d + %d = %d\n", seq2int(X, size), seq2int(Y, size), seq2int(R, size));

    // Q6

}

// Q2
int sign( int8_t x ) {
    return (0b10000000 & x) >> 7;
}

int8_t neg( int8_t x ) {
    return ~x + 1;
}

uint8_t mod( uint8_t x, int n ) {
    unsigned int mask = 0b11111111 >> (8 - n);
    return x & mask;
}

// Q3
int int2seq( bool* X, int8_t x ) {
    int count = 0;
    for (int i = 0; i < sizeof(x) * 8; i++) {
        bool bitSet = (x & (1 << i)) != 0;
        X[i] = bitSet;
        count += bitSet;
    }
    return  count;
}

int8_t seq2int( bool* X, int n ) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += X[i] << i;
    }
    return sum;
}

bool add_seq( bool* R, bool* X, bool* Y, int n ) {
    bool carry = false;
    for (int i = 0; i < n; i++) {
        R[i] = X[i] != Y[i] != carry;
        carry = (X[i] && Y[i]) || ((X[i] != Y[i]) && carry);
    }

    return carry;
}

// Q6
