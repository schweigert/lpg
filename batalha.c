///////////////////////////////
// CRIADO POR MARLON HENRY   //
// E CHRISTOPHER RENKAVIESKI //
// REVISADO DIA 19/10/1015   //
// CRIADO EM 2014.2          //
///////////////////////////////

/////////////////////////
/// PROF GUILHERME K. ///
/////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// DEFINIÇÕES
#define TAM_NOME 256
#define DEBUG	0


typedef struct{
	int 	linha;				// POSIÇÃO DA LINHA DELE
	int 	coluna;				// POSIÇÃO DA COLUNA DELE
	int 	tam_barco;			// TAMANHO DO BARCO
	int 	orientacao;			// POR DEFINIÇÃO, 0 - VERTICAL, 1 - HORIZONTAL. INICIA EM ZERO!
	char 	*condicoes_barco;	// POR DEFINIÇÃO, 'X' - ACERTOU, 'B' - IT'S OK.
}Barco;



typedef struct{
	char 	**mapa;					// POR DEFINIÇÃO, 'O' - OCEANO, 'X' - BARCO
	char 	nome_jogador[TAM_NOME];	// NOME DO JOGADOR
	int		qtd_linhas;				// LINHAS DO MAPA
	int		qtd_colunas;			// COLUNAS DO MAPA
	int		numero_tiros;			// NUMERO DE TIROS NO JOGO
	int		numero_barcos;			// NUMERO DE BARCOS NO JOGO
	Barco	**barcos;				// TODOS OS BARCOS NO JOGO
	int		barcos_atingidos;		// Quantos barcos foram atingidos
	int 	barcos_destruidos;		// Quantos barcos foram destruídos
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
void	FLEYHE_Exibir_Barcos 	(Jogo jogo);
void CHRIS_posiciona_barco (Jogo *jogo, int indice);
void CHRIS_remove_barco (Jogo *jogo, int indice);

int main (void){
	// VARIAVEIS INICIAIS
	int linhas, colunas,barcos,tiros;
	
	// LER DADOS
	scanf ("%d %d %d %d",&linhas,&colunas,&barcos,&tiros);
	
	// CRIAR JOGO
	Jogo *jogo;
	// INICIAR JOGO
	jogo = cria_jogo(linhas,colunas,barcos,tiros);
	if (DEBUG) puts ("\n\n\tQual o nome do jogador?");
	if (DEBUG)scanf ("%s", jogo->nome_jogador);

	// INICIANDO JOGO
	while (jogo->numero_tiros--){
		
		turno (jogo);

	}
	
	printf ("Quantidade de barcos atingidos: %d\n",jogo->barcos_atingidos);
	printf ("Quantidade de barcos destruídos: %d\n",jogo->barcos_destruidos);
	if (jogo->numero_barcos)puts("Tente novamente…!");
	else puts ("Vitória!");

	
	destroi_jogo(&jogo);
	
	return 0;
}

Jogo *cria_jogo	(int linhas, int colunas, int tanbarcos, int tiros){
	
	// Seta a semente do RNG
	srand(time(NULL));
	
	// CRIAR JOGO
	Jogo *jogo = (Jogo*)malloc (sizeof(Jogo));
	
	// ATRIBUIR DADOS
	jogo->qtd_linhas = linhas;
	jogo->qtd_colunas = colunas;
	jogo->barcos = (Barco**)malloc(sizeof(Barco*)*tanbarcos);
	jogo->numero_tiros = tiros;
	jogo->numero_barcos = tanbarcos;
	jogo->barcos_atingidos=0;
	jogo->barcos_destruidos=0;
	
	
	// CRIAR MATRIZ DO MAPA
	char **ret = NULL;
	char *dados = NULL;
	int i = 0;
	
	if (!(ret=(char**)malloc(sizeof(char*)*linhas)))exit(EXIT_FAILURE);
	if (!(dados=(char*)malloc(sizeof(char)*linhas*colunas)))exit(EXIT_FAILURE);
	
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
	
	//Inicializa o vetor **barcos
	for(x=0;x<tanbarcos;x++){
		jogo->barcos[x]=NULL;
	}
	
	i=0;
	for (x = 0; x < tanbarcos; x++){
		CHRIS_posiciona_barco(jogo, i);
		if(jogo->barcos[i]!=NULL){
			i++;
			FLEYHE_Atualizar_Mapa(jogo);
		}
		else{
			(jogo->numero_barcos)--;
		}
	}
	Barco **tmp=NULL;
	if(i<tanbarcos){
		tmp=(Barco**)realloc(jogo->barcos, sizeof(Barco*)*i);
		if(!tmp){
			exit(EXIT_FAILURE);
		}
		else{
			jogo->barcos=tmp;
		}
	}
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
	barco->condicoes_barco = malloc(sizeof(char)*(tam_barco+1));
	barco->condicoes_barco[tam_barco] = '\0';
	barco->orientacao = 1;
	int x;
	
	for (x = 0; x < tam_barco; x++){
		barco->condicoes_barco[x] = 'B';
	}
	
	return barco;
	
}

void altera_orientacao_barco	(Jogo *jogo){
	int i, j;
	int n_vira;
	
	for(i=0;i<jogo->numero_barcos;i++){
		n_vira=0;
		if(jogo->barcos[i]->orientacao){ //Se valer 1, orientacao=horizontal; testa se pode virar pra cima
			if(jogo->barcos[i]->linha - jogo->barcos[i]->tam_barco + 1 >= 0){
				for(j=1;(j<jogo->barcos[i]->tam_barco)&&(!n_vira);j++){
					if(jogo->mapa[jogo->barcos[i]->linha-j][jogo->barcos[i]->coluna]!='O'){
						n_vira=1;
					}
				}
			}
			else{
				n_vira=1;
			}
		}
		else{ //Se nao, orientacao=vertical; testa se pode virar pra direita
			if(jogo->barcos[i]->coluna + jogo->barcos[i]->tam_barco <= jogo->qtd_colunas){
				for(j=1;(j<jogo->barcos[i]->tam_barco)&&(!n_vira);j++){
					if(jogo->mapa[jogo->barcos[i]->linha][jogo->barcos[i]->coluna+j]!='O'){
						n_vira=1;
					}
				}
			}
			else{
				n_vira=1;
			}
		}
		if(!n_vira){
			if(jogo->barcos[i]->orientacao){ //muda pra vertical
				jogo->barcos[i]->orientacao=0;
			}
			else{//muda pra horizontal
				jogo->barcos[i]->orientacao=1;
			}
			FLEYHE_Atualizar_Mapa (jogo);
		}
	}
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

	for (x = 0; (x < jogo->numero_barcos)&&(jogo->barcos[x]!=NULL); x++){
		for (i = 0; i < jogo->barcos[x]->tam_barco; i++){
			if (jogo->barcos[x]->orientacao){
				jogo->mapa[jogo->barcos[x]->linha][jogo->barcos[x]->coluna+i] = 'X';
			}else{
				jogo->mapa[jogo->barcos[x]->linha-i][jogo->barcos[x]->coluna] = 'X';
			}
		}
	}
}



void CHRIS_posiciona_barco (Jogo *jogo, int indice){
	int l, c, tam;
	int tentativa, criou=0;
	int i;
	
	for(tentativa=0;(tentativa<5)&&(!criou);tentativa++){ //5 tentativas pra colocar o barco
		if (DEBUG) printf("Barco %d, tentativa %d\n", indice, tentativa);
		l=FLEYHE_Randomico(jogo->qtd_linhas);
		c=FLEYHE_Randomico(jogo->qtd_colunas);
		tam=1+FLEYHE_Randomico(3);
		i=0;
		if(c+tam<=jogo->qtd_colunas){
			for(i=0;i<tam;i++){
				if(jogo->mapa[l][c+i]!='O'){
					break;
				}
			}
		}
		if(i==tam){
			criou=1;
		}
	}
	if(criou){
		jogo->barcos[indice]=cria_barco(l, c, tam);
		if (DEBUG) printf("Criando barco de tamanho %d em (%d,%d)\n", tam, l, c);
	}
	else{
		if (DEBUG) printf("Nao foi possivel criar barco\n");
	}
}
void FLEYHE_Exibir_Barcos (Jogo jogo){
	
	int x = 0;
	
	for (x = 0; x < jogo.numero_barcos; x ++){
		printf ("Barco #%d\t(%d)%s\t(%d,%d) - %d\n",x,jogo.barcos[x]->tam_barco,jogo.barcos[x]->condicoes_barco,jogo.barcos[x]->linha,jogo.barcos[x]->coluna,jogo.barcos[x]->orientacao);
	}
	
	
}

void CHRIS_remove_barco (Jogo *jogo, int indice){
	Barco *tmp=NULL;
	Barco **realoca=NULL;
	
	tmp=jogo->barcos[indice];
	jogo->barcos[indice]=jogo->barcos[jogo->numero_barcos-1];
	jogo->barcos[jogo->numero_barcos-1]=tmp;
	
	destroi_barco(&(jogo->barcos[jogo->numero_barcos-1]));
	
	(jogo->numero_barcos)--;
	if (jogo->numero_barcos != 0){
		realoca=(Barco**)realloc(jogo->barcos, sizeof(Barco*)*(jogo->numero_barcos));
		if(!realoca){
			printf("Erro ao remover barco\n");
			exit(EXIT_FAILURE);
		}
		else{
			jogo->barcos=realoca;
			
		}
	}
	jogo->barcos_destruidos++;
}

void destroi_jogo (Jogo **jogo){
	int i;
	
	for(i=(*jogo)->numero_barcos-1;i>=0;i--){
		destroi_barco(&((*jogo)->barcos[i]));
	}
	free((*jogo)->barcos);
	free(*jogo);
	*jogo=NULL;
}

void turno (Jogo *jogo){
	int b_atingido, destruiu;
	int i, p;
	Barco **tmp=NULL;
	
	p=1+FLEYHE_Randomico(100);
	FLEYHE_Atualizar_Mapa(jogo);
	if(p<=25){
		if (DEBUG) printf("Tentando criar novo barco\n");
		tmp=(Barco**)realloc(jogo->barcos, sizeof(Barco*)*((jogo->numero_barcos)+1));
		if(!tmp){
			printf("Erro ao criar novo barco\n");
			exit(EXIT_FAILURE);
		}
		jogo->barcos=tmp;
		jogo->barcos[jogo->numero_barcos]=NULL;
		CHRIS_posiciona_barco(jogo, jogo->numero_barcos);
		if(jogo->barcos[jogo->numero_barcos]!=NULL){
			(jogo->numero_barcos)++;
			FLEYHE_Atualizar_Mapa(jogo);
		}
		
		else{
			tmp=NULL;
			tmp=(Barco**)realloc(jogo->barcos, sizeof(Barco*)*(jogo->numero_barcos));
			if(!tmp){
				if (DEBUG) printf("Erro ao realocar vetor de barcos\n");
				exit(EXIT_FAILURE);
			}
			jogo->barcos=tmp;
		}
	}
	if (DEBUG) FLEYHE_Exibir_Mapa(*jogo);
	if (DEBUG) FLEYHE_Exibir_Barcos(*jogo);
	if (DEBUG) puts ("Onde deseja atirar?");
	int x,y;
	scanf ("%d %d", &x,&y);
	b_atingido=atira (x,y,jogo);
	if(b_atingido!=-1){
		//Verifica se destruiu o barco, caso ele tenha sido atingido
		destruiu=1;
		for(i=0;(i<jogo->barcos[b_atingido]->tam_barco)&&(destruiu);i++){
			if(jogo->barcos[b_atingido]->condicoes_barco[i]=='B'){
				destruiu=0;
			}
		}
		if(destruiu){
			CHRIS_remove_barco(jogo, b_atingido);
		}
	}
	
	
	altera_orientacao_barco (jogo);
	

}

int atira (int lin, int col, Jogo *jogo){

	int x = 0, i, flag = 1;

	if(jogo->mapa[lin][col]=='X'){
		// Passar em todos os barcos para descobrir qual foi atingido
		for(x=0;x<jogo->numero_barcos;x++){
			if(jogo->barcos[x]->orientacao){
				if((jogo->barcos[x]->linha==lin)&&(col>=jogo->barcos[x]->coluna)&&(col<(jogo->barcos[x]->coluna+jogo->barcos[x]->tam_barco))){
					for(i=0;jogo->barcos[x]->condicoes_barco[i]!='\0';i++){
						if (jogo->barcos[x]->condicoes_barco[i]=='X'){
							flag = 0;
							break;	
						}
					}
					if (flag) jogo->barcos_atingidos++;
					jogo->barcos[x]->condicoes_barco[col - jogo->barcos[x]->coluna] = 'X';
					if (DEBUG) printf ("Acertou o barco %d, na posicao %d\n",x,col - jogo->barcos[x]->coluna);
					return x;
				}
			}
			else{
				if((jogo->barcos[x]->coluna==col)&&(lin<=jogo->barcos[x]->linha)&&(lin>(jogo->barcos[x]->linha-jogo->barcos[x]->tam_barco))){
					for(i=0;jogo->barcos[x]->condicoes_barco[i]!='\0';i++){
						if (jogo->barcos[x]->condicoes_barco[i]=='X'){
							flag = 0;
							break;	
						}
					}
					if (flag) jogo->barcos_atingidos++;
					
					jogo->barcos[x]->condicoes_barco[jogo->barcos[x]->linha - lin] = 'X';
					if (DEBUG) printf ("Acertou o barco %d, na posicao %d\n",x,jogo->barcos[x]->linha - lin);
					return x;
				}
			}
		}
	}


//Retorno caso nenhum barco tenha sido atingido
return -1;

}

void destroi_barco (Barco **barco){
	free((*barco)->condicoes_barco);
	free(*barco);
	*barco=NULL;
}
