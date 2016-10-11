#ifndef _CADEIA_H
#define _CADEIA_H

void imprime_cadeia(char* cadeia);
/* Observações:
 * O trabalho deve ser realizado em duplas (no máximo).
 * O objetivo deste trabalho é avaliar a manipulação de memória usando as funções de alocação.

 * Todas as cadeias devem ter o tamanho exato correspondente aos seus caracteres.
 * Todas as cadeias terminam com '\0'
 * A primeira posição das cadeias é 0
 * Não use string.h
 */

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//

/* tamanho_cadeia.
 * Descrição: 
 * 		Retorna o tamanho da cadeia, ou seja, a distância entre o ponteiro até um caractere antes do '\0'.
 * 
 * Parâmetros:
 * 		char* cadeia - o ponteiro para a cadeia.
 * 
 * Retorno:
 * 		int - um inteiro representando o tamanho da cadeia.
 */
int tamanho_cadeia(char* cadeia);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//

/* compara_cadeias.
 * Descrição: 
 * 		Compara os caracteres individualmente entre dois blocos de memória. A comparação é baseada na tabela ASCII, então por exemplo: a<b, b<c z>x, A<a, aa<ab.
 * 		A comparação deve retornar na primeira diferença de caracteres ou quando as duas cadeias acabarem.
 * 
 * Parâmetros:
 * 		char* cadeia1 - O ponteiro para o primeiro bloco de memória.
 * 		char* cadeia2 - O ponteiro para o segundo bloco de memória.
 * 
 * Retorno:
 * 		int - inteiro indicando as seguintes situações:
 * 		menor que 0 - Quando cadeia1<cadeia2
 * 		igual a 0 - Quando cadeia1==cadeia2
 * 		maior que 0 - Quando cadeia1>cadeia2
 */
int compara_cadeias(char* cadeia1, char* cadeia2);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//

/* clona_cadeia.
 * Descrição: 
 * 		Cria uma nova cadeia e copia o conteudo da fonte, retornando o ponteiro da nova cadeia.
 * 
 * Parâmetros:
 * 		char* fonte - O ponteiro para a cadeia fonte.
 * 
 * Retorno:
 * 		char* - A nova cadeia.
 */
char* clona_cadeia (char* fonte);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//

/* copia_cadeia.
 * Descrição: 
 * 		Copia a cadeia fonte para a cadeia de destino.
 * 
 * Parâmetros:
 * 		char* destino - O ponteiro para a cadeia de destino.
 * 		char* fonte - O ponteiro para a cadeia fonte.
 * 
 * Retorno:
 * 		int - A quantidade de caracteres copiados
 */
int copia_cadeia(char* destino, char* fonte);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//

/* altera_caracteres_cadeia.
 * Descrição: 
 * 		Altera os primeiros N caracteres da cadeia de destino para um único caractere.
 * 
 * Parâmetros:
 * 		char* destino - A cadeia de destino que será alterada.
 * 		char caractere - O caractere alvo.
 * 		int n - Os primeiros N caracteres da cadeia que serão alterados.
 * 
 * Retorno:
 * 		int - A quantidade de caracteres alterados.
 */
int altera_caracteres_cadeia(char* destino, char caractere, int n);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//

/* concatena_cadeia.
 * Descrição: 
 * 		Concatena a cadeia fonte no final da cadeia destino.
 * 		A cadeia fonte deve começar na posição do '\0' na cadeia destino.
 * 		E o '\0' da cadeia fonte deve ser copiado.
 * 
 * Parâmetros:
 * 		char* destino - O ponteiro para a cadeia de destino.
 * 		char* fonte - O ponteiro para a cadeia fonte.
 * 
 * Retorno:
 * 		int - O tamanho total da nova cadeia.
 */
int concatena_cadeia (char* destino, char* fonte);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//

/* concatena_caracteres_cadeia.
 * Descrição: 
 * 		Concatena os primeiros N caracteres da cadeia fonte para a cadeia destino.
 * 		Se a cadeia fonte for menor que N, a concatenação deve acabar após copiar o '\0'.
 * 
 * Parâmetros:
 * 		char* destino - O ponteiro para a cadeia de destino.
 * 		char* fonte - O ponteiro para a cadeia fonte.
 * 		int n - A quantidade de caracteres a serem copiados.
 * 
 * Retorno:
 * 		int - O novo tamanho da cadeia destino.
 */
int concatena_caracteres_cadeia (char* destino, char* fonte, int n);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//

/* busca_caracteres_cadeia.
 * Descrição: 
 * 		Busca na cadeia as ocorrência do caractere.
 * 
 * Parâmetros:
 * 		char* cadeia - O ponteiro para a cadeia a ser pesquisada.
 * 		char caractere - O caractere a ser pesquisado.
 * 
 * Retorno:
 * 		int* - vetor de inteiros tendo todas as posições que o caractere foi encontrado 
 * 		a última posição do vetor deve ter um -1
 * 
 * Exemplo:
 * 		cadeia = Linguagem de Programacao, Caractere = a
 * 		retorno:
 * 		int[0] = 5
 * 		int[1] = 18
 * 		int[2] = 20
 * 		int[3] = 22
 * 		int[4] = -1
 */
int* busca_caracteres_cadeia(char* cadeia,char caractere);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//

/* quantidade_caracteres_presentes.
 * Descrição: 
 * 		Calcula a quantidade de caracteres da cadeia1 que pertencem a cadeia2.
 * 		Então se a cadeia1 = GCC e cadeia2 = C, deve retornar 2.
 * 
 * Parâmetros:
 * 		char* cadeia1 - O ponteiro para a cadeia1.
 * 		char* cadeia2 - O ponteiro para a cadeia2.
 * 
 * Retorno:
 * 		int - A quantidade de caracteres da cadeia1 que pertencem a cadeia2.
 */
int quantidade_caracteres_presentes(char* cadeia1, char* cadeia2);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//

/* busca_sub_cadeia.
 * Descrição: 
 * 		Busca as ocorrências completas da subcadeia (sem o '\0') na cadeia.
* 		O retorno deve ser um vetor de ponteiros, cada ponteiro deve apontar para 
 * 		para o inicio da subcadeia, e o ultimo ponteiro deve ser NULL.
 * 		Exemplo: fonte = "Aula de Linguagem de Programação" subcadeia = "de"
 * 		Deve retornar um vetor de ponteiros de 4 posições sendo:
 * 		Retorno[0] = Ponteiro para o inicio do primeiro de
 * 		Retorno[1] = Ponteiro para o inicio do segundo de
 * 		Retorno[2] = NULL
 * 
 * Parâmetros:
 * 		char* cadeia - O ponteiro para a cadeia.
 * 		char* subcadeia - O ponteiro para a subcadeia.
 * 
 * Retorno:
 * 		char** - O vetor de ponteiros das subcadeias.
 */
char** busca_sub_cadeia(char* cadeia, char* subcadeia);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//

/* separa_cadeia.
 * Descrição: 
 * 		Retorna as cadeias da divisão da cadeia fonte pela cadeia dividor.
 * 		O retorno deve ser um vetor de ponteiros, cada ponteiro deve apontar para 
 * 		uma divisão da cadeia, e o último ponteiro deve ser NULL.
 * 		Exemplo: fonte = "Aula de Linguagem de Programação" divisor = "de"
 * 		Deve retornar um vetor de ponteiros de 4 posições sendo:
 * 		Retorno[0] = "Aula "
 * 		Retorno[1] = " Linguagem "
 * 		Retorno[2] = " Programação"
 * 		Retorno[3] = NULL
 * 
 * Parâmetros:
 * 		char* cadeia1 - O ponteiro para a cadeia original.
 * 		char* divisor - O ponteiro para o divisor.
 *      	char* cadeia2 - A segunda parte da cadeia após a ocorrência completa do divisor.
 * 
 * Retorno:
 * 		char** o vetor de ponteiros que em cada posição deve ter uma sub cadeia.
 */
char** separa_cadeia(char* fonte, char* divisor);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//

/* converte_para_maiusculo.
 * Descrição: 
 * 		Converte todos os caracteres da cadeia para caracteres maiúsculos.
 * 
 * Parâmetros:
 * 		char* cadeia - O ponteiro para a cadeia.
 * 
 * Retorno:
 * 		int - O número de caracteres convertidos.
 */
int converte_para_maiusculo(char* cadeia);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//

/* converte_para_minusculo.
 * Descrição: 
 * 		Converte todos os caracteres da cadeia para caracteres minúsculos.
 * 
 * Parâmetros:
 * 		char* cadeia - O ponteiro para a cadeia.
 * 
 * Retorno:
 * 		int - o número de caracteres convertidos.
 */
int converte_para_minusculo(char* cadeia);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//

/* inverte_cadeia.
 * Descrição: 
 * 		Inverte todos os caracteres da cadeia. Por exemplo: abcde será invertido para edcba e deve retornar 5.
 * 
 * Parâmetros:
 * 		char* cadeia - O ponteiro para a cadeia.
 * 
 * Retorno:
 * 		int - o número de caracteres intervidos.
 */
int inverte_cadeia(char* cadeia);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//

#endif /* _CADEIA_H */
