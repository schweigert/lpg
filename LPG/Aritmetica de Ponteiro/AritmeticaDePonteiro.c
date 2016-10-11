#include <stdio.h>

int main (void){

	int a = 10;
	int b = 11;
	int *PTR = NULL;

	PTR = &a;

	a++; a = a+1;

	(PTR)++;

	printf ("%d\n", *(PTR++));
	

return 0;
}
