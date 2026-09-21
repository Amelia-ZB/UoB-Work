#include <stdio.h>

int main(int argc, char **argv) {
	char *input = argv[1];

	while (*input != 0) {
		if (*input >= 97 && *input <= 122) {
			*input -= 32;
		}
		putchar((char) *input);
		input++;
	}
	putchar('\n');
}
