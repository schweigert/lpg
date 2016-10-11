#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimir (int **m, int linhas, int colunas);
void completar (int **m, int linha, int coluna);
int **criar_matriz(int linha, int coluna);
void destruir_matriz(int ***m, int linhas, int colunas);



int main(int argc, char **argv)
{
	int l = 0;
	int c = 0;
	int **m = NULL;
	srand (time(NULL));
	
	printf ("INFORME O NUMERO DE LINHAS E COLUNAS: \t");
	scanf ("%d %d", &l, &c);
	
	m = criar_matriz(l,c);
	completar(m,l,c);
	imprimir(m,l,c);
	destruir_matriz(&m,l,c);
	
	return 0;
}

void imprimir (int **m, int linhas, int colunas){
	
	int x=0,y=0;
	for (x = 0;x < linhas; x++){
		for (y = 0; y < colunas; y++){ 
			printf ("%d\t",m[x][y]);
		}
		puts("");
	}
	
}


void completar (int **m, int linhas, int colunas){
	
	int x=0,y=0;
	for (x = 0;x < linhas; x++){
		for (y = 0; y < colunas; y++){ 
			m[x][y] = rand()%50;
		}
	}
	
}	
	
	

int **criar_matriz(int linha, int coluna){
	/* MODO ANTIGO
		int **ret = NULL;
		int i;
		ret = (int**)malloc(sizeof(int*)*linha);
		
		if (!ret){
			 printf ("ERROR");
			exit(EXIT_FAILURE);
		}
		
		for (i=0; i<linha;i++){
			
			ret[i]=(int*)malloc(sizeof(int)*coluna);
			
			if (!ret[i]){
				printf ("ERROR");
				exit(EXIT_FAILURE);
			}
			
		}
		
		return ret;
		* 
		*/
		
		int **ret = NULL;
		int *dados = NULL;
		int i = 0;
		
		if (!(ret=(int**)malloc(sizeof(int*)*linha)))exit(EXIT_FAILURE);
		if (!(dados=(int*)malloc(sizeof(int)*coluna)))exit(EXIT_FAILURE);
		
		for (i = 0; i<linha;i++){
			ret[i] = dados+i*coluna;
		}
	
	return ret;
	
}


void destruir_matriz(int ***m, int linhas, int colunas){
	/* MODO NOVO
	int i = 0;
	for (i=0;i<linhas;i++){
		
		free((*m)[i]);
		(*m)[i]=NULL;
		
	}
	free(*m);
	*m = NULL;
	*/
	
	free (*m);
	*m = NULL;
	
	
	
}
