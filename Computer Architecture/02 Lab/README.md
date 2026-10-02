# Notes from the lab

## 1

### b
it will divide the number by $2^i$, or shift the bit pattern to the right by $i$ places

### c
more bits

### .
for loop

write a binary to hex converter

## 2

### a
```C
int sign( int8_t x ) {
    return ((0b10000000 & x) >> 7);
}
```

### b
```C
int8_t neg( int8_t x ) {
    return ~x + 1;
}
```

### c
```C
uint8_t mod( uint8_t x, int n ) {
    unsigned int mask = 0b11111111 >> (8 - n);
    return x & mask;
}
```