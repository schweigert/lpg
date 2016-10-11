#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"


int main (void){
	
	Matriz *A;
	
	A = m_criar(2,5);
	
	m_imprimir(A);
	m_inicializar(A);
	
	puts(" ");
	m_imprimir(A);
	
	
	
	m_destruir(&A);
	
	

	return 0;
}
