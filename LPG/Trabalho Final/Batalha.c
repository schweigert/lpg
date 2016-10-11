// CRIADO POR MARLON HENRY

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// DEFINIÇÕES
#define TAM_NOME 256
#define DEBUG	1


typedef struct{
	int 	linha;				// POSIÇÃO DA LINHA DELE
	int 	coluna;				// POSIÇÃO DA COLUNA DELE
	int 	tam_barco;			// TAMANHO DO BARCO
	int 	orientacao;			// POR DEFINIÇÃO, 0 - VERTICAL, 1 - HORIZONTAL. INICIA EM ZERO!
	char 	*condicoes_barco;	// POR DEFINIÇÃO, 'X' - ACERTOU, 'B' - IT'S OK.
}Barco;



typedef struct{
	char 	**mapa;					// POR DEFINIÇÃO, 'O' - OCEANO, 'B' - BARCO
//	char 	nome_jogador[TAM_NOME];	// NOME DO JOGADOR
	int		qtd_linhas;				// LINHAS DO MAPA
	int		qtd_colunas;			// COLUNAS DO MAPA
	int		numero_tiros;			// NUMERO DE TIROS NO JOGO
	int		numero_barcos;			// NUMERO DE BARCOS NO JOGO
	Barco	*barcos;				// TODOS OS BARCOS NO JOGO
}Jogo;

// PROTÓTIPO DE FUNÇÕES


// FUNÇÕES PRINCIPAIS

Jogo 	*cria_jogo				(int qtd_linhas, int qtd_colunas, int qtd_barcos, int qtd_tiros);
Barco 	*cria_barco				(int linha, int coluna, int tam_barco);
void 	altera_orientacao_barco	(Jogo *jogo);
void 	turno					(Jogo *jogo);
int 	atira					(int linha, int coluna, Jogo *jogo);
void 	destroi_barco 			(Barco **barco);
void 	destroi_jogo 			(Jogo **jogo);

// FUNÇÕES AUXILIARES
void 	FLEYHE_Exibir_Mapa		(Jogo jogo);
int		FLEYHE_Randomico		(int Tamanho);
void	FLEYHE_Atualizar_Mapa	(Jogo *jogo);

int main (void){
	// VARIAVEIS INICIAIS
	int linhas, colunas,barcos,tiros;
	
	// LER DADOS
	scanf ("%d %d %d %d",&linhas,&colunas,&barcos,&tiros);
	
	// CRIAR JOGO
	Jogo *jogo;
	// INICIAR JOGO
	jogo = cria_jogo(linhas,colunas,barcos,tiros);
	
	// INICIANDO JOGO
	while (jogo->numero_tiros--){
		if (DEBUG)	FLEYHE_Exibir_Mapa (*jogo);

		
	}
	
	return 0;
}

Jogo *cria_jogo	(int linhas, int colunas, int tanbarcos, int tiros){
	
	// CRIAR JOGO
	Jogo *jogo = malloc (sizeof(Jogo));
	
	// ATRIBUIR DADOS
	jogo->qtd_linhas = linhas;
	jogo->qtd_colunas = colunas;
	jogo->barcos = malloc(sizeof(Barco)*tanbarcos);
	jogo->numero_tiros = tiros;
	jogo->numero_barcos = tanbarcos;
	
	
	
	// CRIAR MATRIZ DO MAPA
	char **ret = NULL;
	char *dados = NULL;
	int i = 0;
	
	if (!(ret=(char**)malloc(sizeof(char*)*linhas)))exit(EXIT_FAILURE);
	if (!(dados=(char*)malloc(sizeof(char)*colunas)))exit(EXIT_FAILURE);
	
	for (i = 0; i<linhas;i++){
		ret[i] = dados+i*colunas;
	}
		
	// INICIALIZAR A MATRIZ DO MAPA
	int j;
	for (i = 0; i < linhas; i++){
		for (j = 0; j < colunas; j++){
			ret[i][j] = 'O';
		}
	}
	
	jogo->mapa = ret;
	

	int x = 0;
	
	for (x = 0; x < tanbarcos; x++){
		Create_Tobata:
		jogo->barcos[x] = *(cria_barco(FLEYHE_Randomico(jogo->qtd_linhas),FLEYHE_Randomico(jogo->qtd_colunas),FLEYHE_Randomico(3)+1));
		if (jogo->barcos[x].coluna + jogo->barcos[x].tam_barco > jogo->qtd_colunas){
				goto Create_Tobata;
		}
	}
	FLEYHE_Atualizar_Mapa(jogo);
	// RETORNAR JOGO
	return jogo;
}

Barco *cria_barco (int linha, int coluna, int tam_barco){
	
	// CRIAR BARCO
	Barco *barco = NULL;
	if (!(barco = malloc(sizeof(Barco))))exit(EXIT_FAILURE);
	
	barco->linha = linha;
	barco->coluna = coluna;
	barco->tam_barco = tam_barco;
	barco->condicoes_barco = malloc(sizeof(char)*tam_barco);
	barco->orientacao = 0;
	int x;
	
	for (x = 0; x < tam_barco; x++){
		barco->condicoes_barco[x] = 'B';
	}
	
	return barco;
	
}

void FLEYHE_Exibir_Mapa (Jogo jogo){
	int i = jogo.qtd_linhas;
	int j = jogo.qtd_colunas;
	
	int x,y;
	puts ("");
	for (x = 0; x < i; x++){
		for (y = 0; y < j; y++){
			printf ("%c ",jogo.mapa[x][y]);
		}
		puts("");
	}
	puts("");
	
}

int FLEYHE_Randomico (int tamanho){
	srand(time(NULL));
	return rand()%tamanho;
}

void FLEYHE_Atualizar_Mapa (Jogo *jogo){
	int x = 0;
	int i, j;
	for (i = 0; i < jogo->qtd_linhas; i++){
		for (j = 0; j < jogo->qtd_colunas; j++){
			jogo->mapa[i][j] = 'O';
		}
	}

	for (x = 0; x < jogo->numero_barcos; x++){
		for (i = 0; i < jogo->barcos[x].tam_barco; i++){
			if (jogo->barcos[x].orientacao){
				jogo->mapa[jogo->barcos[x].linha][jogo->barcos[x].coluna+i] = 'X';
			}else{
				jogo->mapa[jogo->barcos[x].linha+i][jogo->barcos[x].coluna] = 'X';
			}
		}
	}
}
