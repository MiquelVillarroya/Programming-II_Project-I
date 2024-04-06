#include<stdio.h>

int A = 17;
int B = 3;
int quo = 0;
int rem = 0;

int main() {
	int i;

	if (B == 0) {
		return (-1);
	}

	for (i = A; i >= B; i -= B) {
		quo++;
	}
	rem = i;

	printf("Quotient: %d Residue: %d\n", quo, rem);

	return(0);
}