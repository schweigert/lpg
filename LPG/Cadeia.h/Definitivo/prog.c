#include <stdio.h>
#include <stdlib.h>
#include "cadeia.h"

int main(void){

	puts("\tIniciando o teste do Cadeia.h\n");
	char *PrimeiraCadeia = NULL;
	char *SegundaCadeia = NULL;
	char **TerceiraCadeia = NULL;

/*-----*/

	PrimeiraCadeia = malloc(30);
	SegundaCadeia = malloc(30);

	copia_cadeia(PrimeiraCadeia,"Teste de cadeias");
	copia_cadeia(SegundaCadeia," de");
/*-----*/

	TerceiraCadeia = separa_cadeia(PrimeiraCadeia,SegundaCadeia);

/*-----*/
	printf("\n");
	imprime_cadeia(PrimeiraCadeia);
	imprime_cadeia(SegundaCadeia);

/*-----*/

	printf("\n");
	printf("\n");
	free(PrimeiraCadeia);
	free(SegundaCadeia);
	//free(TerceiraCadeia);
	PrimeiraCadeia = NULL;
	SegundaCadeia = NULL;
	//TerceiraCadeia = NULL;

	return 0;
}
