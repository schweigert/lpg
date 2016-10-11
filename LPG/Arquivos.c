#include <stdio.h>

int main (void){
	
	char nome[30];
	double saldo = 0;
	int conta = 0;
	
	FILE *arquivo = NULL;
	
	if ((arquivo = fopen ("dados.txt","w"))==NULL){
		printf ("Erro ao criar um arquivo\n");
		return 1;
	}
	
	printf ("Informe a conta, nome e saldo \n");
	
	printf ("Informe EOF para terminar\n");
	
	scanf ("%d %s %lf", &conta, nome, &saldo);
	
	while (!feof(stdin)){
		
		fprintf (arquivo,"%d %s %lf\n",conta, nome, saldo);
		printf ("Outro registro?\t");
		scanf ("%d%s%lf", &conta, nome, &saldo);
	
	}
	
	fclose(arquivo);
	
	return 0;
}
