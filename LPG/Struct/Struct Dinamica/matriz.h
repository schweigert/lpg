#ifndef matriz_h
#define matriz_h

typedef struct {
	int **dados;
	int linhas;
	int colunas;
}Matriz;

Matriz *m_criar (int linhas, int colunas);
void m_imprimir (Matriz *m);
void m_destruir(Matriz **m);
void m_inicializar (Matriz *m);
Matriz *m_multiplicar (Matriz *A, Matriz *B);

#endif
