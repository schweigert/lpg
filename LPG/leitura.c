#include <stdio.h>

int main (void){
	
	char nome[30];
	double saldo = 0;
	int conta = 0;
	char nomedoarquivo[30];
	FILE *arquivo = NULL;
	
	printf ("Qual Arquivo?\t");
	
	fscanf (stdin, "%s", nomedoarquivo);
	
	arquivo = fopen(nomedoarquivo,"r");
	
	if (!arquivo){
		printf ("!Arquivo não encontrado\n");
		return 1;
	}
	
	fscanf (arquivo, "%d%s%lf", &conta,nome,&saldo);
	while (!feof(arquivo)){
		
		printf ("%d %s %lf\n", conta, nome, saldo);
		fscanf (arquivo , "%d%s%lf",&conta, nome, &saldo);
		
	}
	fclose(arquivo);
	return 0;
	
}

