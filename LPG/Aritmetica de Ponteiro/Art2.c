#include <stdio.h>

int main (void){


	int v[5] = {0};
	int i = 10;
	int *vptr = NULL;
	vptr = v;

	for (i = 0; i < 5; i++){
	
		(*(vptr+i))++;
		printf ("%d",*(vptr+i));
	}

	return 0;
}
