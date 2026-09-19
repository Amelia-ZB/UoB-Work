#include <stdio.h>

int returnSum(int iNum1, int iNum2);

int main(int argc, char **argv) {
	int i,j,k;
	j = atoi(argv[1]);
	k = atoi(argv[2]);

	i = returnSum(j,k);
	printf("The sum of %d and %d is %d\n",j, k, i);
	return 0;
}

int returnSum(int iNum1, int iNum2) {
	int i;
	i = iNum1 + iNum2;
	return i;
}
