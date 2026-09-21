# 01.1 - Introduction

* gcc not deterministic!
* 5 hrs / week of programming practice self study + 5-6 in labs


## resources

* use provided unit tests for C
* use sample / tutorial code for formative coursework


## exams

* Sumative: 80% exam + 2x 10% mini coursework
* coursework split in half: closed & open ended tasks


## what is C

C is imperative & procedural

Imperative: telling the computer <u>how</u> to do things. using statements to define and change the state of the computer

Procedural: sequences are structures in small reusable chunks called <u>procedures</u>

### Functions

$ f: X,\ Y \rightarrow Z $

$ f(x, y) = x+y $

``` C
int f(int x, int y) {
    return x + y;
}
```

* think: what does it do / achieve?

### procedures

a pure function calculates its result using <u>only</u> its arguments e.g. f

C is procedural; programs are made of procedures

procedures _can_ take arguments and return a result

* think: what is it doing to the state?

### examples:

Within a month: 

``` C
signed char a = 64, b = 8, c = 2, result;
result = (a * b) / c;
printf("%hhi\n", result);
// actually prints 0, why?
```

``` C
int a = -1;
unsigned int b = 1;
if (a > b) printf("a > b");
// actually prints a > b, why?
```

``` C
unsigned short w = 0x00FF;
unsigned char *b = &w;
printf("%hhu,%hhu\n", b[0], b[1]);
// actual output depends on computer model, why?
```

In two months:

``` C
int i = 3, *p = &i, **q = &p;
int *w[] = {p, &i, *q};
int *(*z)[] = &w;
printf("%p %d\n", (*z)[0], *(*z)[0]);
// what does the code snippet print, why?
```

By the end of the course:

``` C
bool r = false;
bool *q = &r;
signal(SIGINT, yourFunctionPointer);
const bool volatile qu = false;
__asm__ ("nop\n" : "=a" (q) : "a" (&qu));
while (!quit) {
raise(SIGINT);
} // does volatile influence execution, why?
```



# 01.2 - Procedures & Programs

Simplest possible program

```C
int main(void) {
    return 0;
}
```

build settings:
```
gcc -std=c11 -Wall *.c -o *.out && ./*.out
```

## compilation

* syntack checked
* semantics _not_ checked e.g. halting problem
* compiled binaries are system specific

### Libraries

in a `#include` call putting angle brackets arround the library tell the compiler to look in the "standard place" (`/usr/include/`) and double quotes tell it to go to a specific path

# 01.3 - Types, Variables, and Scope

variadic functions have a _varied_ number of arguments