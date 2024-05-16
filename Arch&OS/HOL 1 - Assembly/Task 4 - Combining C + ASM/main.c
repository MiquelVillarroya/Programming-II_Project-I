#include <stdio.h>

// Inform the compiler this function exists
// (defined and programmed in the ASM module)
int asmAVG();

// Inform the compiler theses vars exist
// (declared in the ASM module)
extern int vector[];

//Global variable
int avg = 0;

int main() {
	printf("Starting the C program...\n");

	avg = asmAVG();
	printf("The array with the component(s) ");
	int i = 0;
	for (i = 0; vector[i] != 0; ++i) {
		printf("%d, ", vector[i]);
	}
	printf("%d ", vector[i]); // We can delete this line of code if we do not consider the "0" as part of the array
	printf("has an average of [%d]\n", avg);

	return (0);
}