#include <stdlib.h>
#include <stdio.h>

#define NUM_DISCS 3
#define COLOURS 1

void hanoi(int num_discs, int towers[3][NUM_DISCS], int start, int end);
void display(int towers[3][NUM_DISCS]);

int main(void) {
    int towers[3][NUM_DISCS];

    for (int i = 0; i < NUM_DISCS; i++) {
        towers[0][i] = NUM_DISCS - i;
        towers[1][i] = 0;
        towers[2][i] = 0;
    }
    display(towers);
    hanoi(NUM_DISCS, towers, 0, 2);
}

void disc_chars(char string[2*NUM_DISCS + 1], int n) {

    if (n == 0) {
        for (int i = 0; i < NUM_DISCS - 1; i++) {
            *string++ = ' ';
        }
        *string++ = '|';
        for (int i = 0; i < NUM_DISCS; i++) {
            *string++ = ' ';
        }

    } else {
        for (int i = 0; i < NUM_DISCS - n; i++) {
            *string++ = ' ';
        }
        for (int i = 0; i < 2 * n - 1; i++) {
            *string++ = '#';
        }
        for (int i = 0; i < NUM_DISCS - n + 1; i++) {
            *string++ = ' ';
        }
    }
}

void display(int towers[3][NUM_DISCS]) {
    char string[NUM_DISCS*2 + 1];
    string[NUM_DISCS*2] = ' ';

    for (int i = NUM_DISCS - 1; i >= 0; i--) {

        disc_chars(string, towers[0][i]);
        printf("\033[%dm%s\033[0m", (towers[0][i] & COLOURS) ? towers[0][i] + 31 : 0, string);
        disc_chars(string, towers[1][i]);
        printf("\033[%dm%s\033[0m", (towers[1][i] & COLOURS) ? towers[1][i] + 31 : 0, string);
        disc_chars(string, towers[2][i]);
        printf("\033[%dm%s\033[0m\n", (towers[2][i] & COLOURS) ? towers[2][i] + 31 : 0, string);
    }

    printf("\n");
}

void move(int *src, int *dst) {
    // this is realy bad but oh well
    while(*(src+1) > 0) src++;
    while(*(dst) > 0) dst++;
    *dst = *src;
    *src = 0;
}

void hanoi(int num_discs, int towers[3][NUM_DISCS], int start, int end) {
    if (num_discs == 1) {
        move(towers[start], towers[end]);
        display(towers);
        return;
    }

    int unused = 3 - start - end;

    hanoi(num_discs-1, towers, start, unused);
    move(towers[start], towers[end]);
    display(towers);
    hanoi(num_discs-1, towers, unused, end);
}




void hanoi2(int num_discs, int towers[3][NUM_DISCS], int start, int end) {
    if (num_discs == 1) move(towers[start], towers[end]);
    else {
        hanoi2(num_discs-1, towers, start, 3 - start - end); // move other discs out of the way
        move(towers[start], towers[end]);                          // put the target disc on the target post
        hanoi2(num_discs-1, towers, 3 - start - end, end); // move the other discs back on top of it
    }
}