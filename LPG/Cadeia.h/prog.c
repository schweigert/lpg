#include <stdio.h>
#include <stdlib.h>
#include "cadeia.h"

int main(void){

 puts("\tIniciando o teste do Cadeia.h\n");
 char *PrimeiraCadeia = NULL;
 PrimeiraCadeia = malloc(30);
 printf ("%s", PrimeiraCadeia);
 copia_cadeia(PrimeiraCadeia,"Teste");
 printf ("%s", PrimeiraCadeia);

 
 imprime_cadeia(PrimeiraCadeia);
return 0;
}
