#include <stdio.h>
#include "bubble.h"
#define tam 19

int main (void){

	int v[tam]={
	7,8,5,3,2,1,9,4,6,
	12,13,15,10,11,23,22,21,20,19
	
};
	bubble_sort(v,tam);
	imprimir(v,tam);
	
	return 0;
}
