#include <stdio.h>

void imprimir (int *v, int t){
	int i;
	for ( i = 0; i < t; i++){
	
		printf ("*v(%d) = %d\n", i ,*(v+i) );
	
	}

}

void bubble_sort (int *v, int t){
  	
void troca (int *, int *);
	int i, j;

	
  for (i = t-1 ; i > 0; i--){
    for (j=0; j < i; j++){
	if (*(v+j) > *(v+j+1)){
		
		troca ((v+j),(v+j+1));
	}
    }
  }

}

void bubble_sort_Comp (int *v, int t,int (*Comparador)(int*,int*) ){
  	
void troca (int *, int *);


	int i, j;
	
	
  for (i = t-1 ; i > 0; i--){
    for (j=0; j < i; j++){
	if (Comparador((v+j),(v+j+1))){
		
		troca ((v+j),(v+j+1));
		}
    }
  }

}



void troca (int *e1, int *e2){
	int aux;
	aux = *e1;
	*e1 = *e2;
	*e2 = aux;
}

