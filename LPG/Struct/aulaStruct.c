#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	const char *naipe;
	const char *valor;
} Carta;

void Criar (Carta *p, const char *valores[], const char * naipes[]);
void Embaralhar (Carta * const p);
void Distribuir (const Carta * const p);


int main (void){

	Carta Baralho[52];
	const char *valores[13] = {"Ás", "Dois", "Três", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"};
	const char *naipes[4] = {"Paus", "Copas", "Espadas", "Ouro"};

	srand(time(NULL));


	Criar(Baralho,valores,naipes);
	Embaralhar(Baralho);
	Distribuir(Baralho);	

	return 0;

}

void Criar (Carta *p, const char *valores[], const char * naipes[]){

	int i = 0;
	for (i = 0; i < 52; i++){

		p[i].naipe = naipes[i/13];
		p[i].valor = valores[i%13];

	}

}


void Embaralhar (Carta *const p){

	int i,j;
	Carta temp;
	for (i = 0; i < 52; i++){
	
		j = rand()%52;
		temp = p[i];
		p[i]=p[j];
		p[j] = temp;

	}

}

void Distribuir (const Carta * const p){

	int i = 0;

	for (i = 0; i < 52; i++){
	
		printf ("\t %s de %s\n",p[i].valor,p[i].naipe);
	
	}

}
