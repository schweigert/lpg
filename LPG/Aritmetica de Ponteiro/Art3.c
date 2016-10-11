#include <stdio.h>

int main (void){

	int v[10] = {1,3,4,5,2,7,9,8,0,9};

	int i;
	int *p = NULL;

	p = &v[0];

	printf (
	"Imprimindo o Vetor\n"
	"\tCom Subscrito e"
	" Deslocamento\n"
	);
	
	for (i = 0; i < 10; i++){

	printf ("v[%d] = %d\n", i,v[i]);
	printf ("*(v+%d) = %d\n",i,*(v+i));	

	}
	
	printf (
	"\tCom o Ponteiro\n"
	);
	
	for (i = 0; i < 10; i++){

		printf ("p[%d] = %d\n", i, p[i]);
		printf ("*(p+%d) = %d\n", i, *(p+i));

	}

	return 0;

}
