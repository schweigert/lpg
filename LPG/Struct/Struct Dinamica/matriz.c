#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"


Matriz *m_multiplicar (Matriz *A, Matriz *B){
	
	if (A->colunas != B->linhas){
		puts("Não é possível multiplicar a Matriz");
		return NULL;
	}
	
	Matriz *Retorno = NULL;
	Retorno = malloc(sizeof(Matriz));
	Retorno = m_criar(A->linhas,B->colunas);
	
	int i = 0;
	int j = 0;
	int c = 0;
	
	int sun = 0;
	

	for (i = 0; i < A->linhas;i++){
		for (j = 0; j < B->colunas; j++){
		sun = 0;
		for (c = 0; c < A->colunas; c++){
			sun += A->dados[i][c]*B->dados[c][j];
		}	
		(*Retorno).dados[i][j] = sun;
		}
	} 

	return Retorno;
}


void m_inicializar (Matriz *m){
	
	srand(time(NULL));
	
	int i, j;
	
	for ( i=0 ; i < m->linhas; i++){
		for (j = 0; j < m->colunas; j++){
			m->dados[i][j] = rand()%100;
		}
	}
	
}


void m_destruir(Matriz **m){
	
	free((*m)->dados);
	(*m)->dados = NULL;
	(*m)->linhas = 0;
	(*m)->colunas = 0;
	
}

void m_imprimir (Matriz *m){
	
	int i, j;
	
	for ( i=0 ; i < m->linhas; i++){
		for (j = 0; j < m->colunas; j++){
			printf ("%d \t",m->dados[i][j]);
		}
		puts(" ");
	} 
	
}

Matriz *m_criar (int l, int c){
	
	Matriz *retorno;
	
	if(!(retorno = (Matriz*)malloc (sizeof(Matriz)))){
		printf ("Erro alocando memória!\n");
		exit(EXIT_FAILURE);
	}
	
	retorno->linhas = l;
	retorno->colunas = c;
	
	int x = 0;
	
	int *vet1 = malloc(sizeof(int)*l*c);
	int **vet2 = malloc(sizeof(int*)*l);
	
	for(x = 0; x < l; x++){
		vet2[x] = &vet1[x*c];
	}
	
	retorno->dados = vet2;
	
	
	return retorno;
	
}


