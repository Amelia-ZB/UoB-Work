/* Copyright (C) 2017 Daniel Page <csdsp@bristol.ac.uk>
 *
 * Use of this source code is restricted per the CC BY-NC-ND license, a copy of 
 * which can be found via http://creativecommons.org (and should be included as 
 * LICENSE.txt within the associated archive or repository).
 */

#ifndef __REP_H
#define __REP_H

#include <stdbool.h>
#include  <stdint.h>
#include   <stdio.h>
#include  <stdlib.h>

#define SIZEOF(x) ( sizeof(x)     )
#define BITSOF(x) ( sizeof(x) * 8 )

int sign( int8_t x );
int8_t neg( int8_t x );
uint8_t mod( uint8_t x, int n );

int int2seq( bool* X, int8_t x );
int8_t seq2int( bool* X, int n );
bool add_seq( bool* R, bool* X, bool* Y, int n );

#endif
