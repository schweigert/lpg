#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bubble.h"

#define tam 30

int descrescente (int *a, int *b){
	
	if (*a > *b) return 0;
	return 1;
	
}

int crescente (int *a, int *b){
	
	if (*b < *a) return 0;
	return 1;
}


int main (void){

	int v[tam]={ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
	

	bubble_sort(v,tam);
	imprimir(v,tam);
	bubble_sort_Comp(v,tam,descrescente);
	imprimir(v,tam);
	return 0;
}
