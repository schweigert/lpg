#include <stdio.h>
#include <stdlib.h>


int tamanho_cadeia(char* cadeia){

	int x = 0;
	int y = 0;

	for (x = 0; cadeia[x] != '\0'; x++){

		y++;

	}

	return y;

}

// ========================================================================================== //
// ========================================================================================== //
void imprime_cadeia(char* cadeia){

	int x;
	int y = tamanho_cadeia(cadeia);
	for (x = 0; x < y; x++){

		printf ("%c", cadeia[x]);

	}
	printf ("\n");
}

// ========================================================================================== //
// ========================================================================================== //

int compara_cadeias(char* cadeia1, char* cadeia2){

	while (*cadeia1 != 0 && *cadeia2 != 0){

		if (*cadeia1 != *cadeia2) return *cadeia1 - *cadeia2;

		cadeia1++; cadeia2++;
	}
	return tamanho_cadeia(cadeia1)-tamanho_cadeia(cadeia2);

}

// ========================================================================================== //
// ========================================================================================== //

char* clona_cadeia (char* fonte){

	char *c;
	c = (char*)malloc(sizeof(char)*(tamanho_cadeia(fonte)+1));

	int x;

	for (x = 0; x < tamanho_cadeia(fonte); x++){

		c[x] = fonte[x];

	}
	c[x] = '\0';

	return c;

}

// ========================================================================================== //
// ========================================================================================== //

int copia_cadeia(char* destino, char* origem){

 while (*origem)
        {
        *destino=*origem;
        origem++;
        destino++;
        }
*destino='\0';

	return 0;

}

// ========================================================================================== //
// ========================================================================================== //

int altera_caracteres_cadeia(char* destino, char caractere, int n){


	int x = 0;
	for (x = 0; x < n && x < tamanho_cadeia(destino); x++){

		destino[x] = caractere;

	}

	return x-1;


}

// ========================================================================================== //
// ========================================================================================== //

int concatena_cadeia (char* destino, char* fonte){

	int x = tamanho_cadeia(destino);
	int y = x;
	int tam = tamanho_cadeia(destino) + tamanho_cadeia(fonte)+1;
	destino = realloc(destino, tam);
	destino[tam-1] = '\0';

	for ( ; x < tam; x++){

		destino[x] = fonte[x-y];

	}

	return tamanho_cadeia(destino);

}


// ========================================================================================== //
// ========================================================================================== //

int concatena_caracteres_cadeia (char* destino, char* fonte, int n){

	char *c;
	int x,y;
	if(tamanho_cadeia(fonte) < n){

		y = tamanho_cadeia(fonte);

	} else {

		y = n;

	}

	c = (char*)malloc(sizeof(char)*(y+1));

	for (x = 0; x < y; x++){

		c[x] = fonte[x];

	}

	c[x] = '\0';

	concatena_cadeia(destino,c);

	return tamanho_cadeia(destino);
}

// ========================================================================================== //
// ========================================================================================== //

char** separa_cadeia(char* fonte, char* divisor){

	return NULL;
}

// ========================================================================================== //
// ========================================================================================== //

int converte_para_maiusculo(char* cadeia){

	int tam = tamanho_cadeia(cadeia);
	int x = 0;
	for (x = 0 ; x < tam; x++){

		if(cadeia[x] >= 'a' && cadeia[x] <= 'z'){

			cadeia[x] -= 32;

		}

	}

	return x-1;
}

// ========================================================================================== //
// ========================================================================================== //

int converte_para_minusculo(char* cadeia){

	int tam = tamanho_cadeia(cadeia);
	int x = 0;
	for (x = 0 ; x < tam; x++){

		if((int)cadeia[x] >= 65 && (int)cadeia[x] <= 90){

			cadeia[x] += 32;

		}

	}

	return x-1;
}

// ========================================================================================== //
// ========================================================================================== //

int inverte_cadeia(char* cadeia){

	int tam = tamanho_cadeia(cadeia);
	int tamx = tam;
	if (tam%2 == 1) tam-= 1;
	int x = 0;
	char swap = 0;
	for ( ; x < tam; x++){



		swap = cadeia[x];
		cadeia[x] = cadeia[tamx-x];
		cadeia[tamx-x] = swap;

	}

	return tam;

}

int* busca_caracteres_cadeia(char* cadeia,char caractere){
	
	int *teste = malloc (sizeof(int));
	int contador = 1;
	int contador2 = 0;
	while (*cadeia != '\0'){
		if (*cadeia==caractere){
			contador++;
			teste = realloc(teste,sizeof(int)*contador);
			teste[contador-2] = contador2;
		}
		contador2++;
		cadeia++;
	}
	
	teste[contador-1] = -1;
	return teste;
	
}

int quantidade_caracteres_presentes(char* cadeia1, char* cadeia2){
	
	int tam_cad2 = tamanho_cadeia(cadeia2);
	int tam_cad1 = tamanho_cadeia(cadeia1);
	int erros = 0;
	int resposta = 0;
	
	int x;
	int y;
	for (x = 0; x < tam_cad1; x++){
		erros = 0;
		for (y = 0; y < tam_cad2; y++){
		
			if (cadeia1[x+y] != cadeia2[y]){
				
				erros ++;
			} 
			if (cadeia1[x+y] == 0) goto rest;
		}
		if (erros==0) resposta++;
	}
	rest:
	return resposta;
	
}


char** separa_cadeia(char* cadeia, char* subcadeia){
	int i = quantidade_caracteres_presentes(cadeia,subcadeia) + 2;
	char** ret = malloc (sizeof(char*)*i);
	
	ret[0] = cadeia;
	ret[i-1] = NULL;
	
	int x;
	int y;
	int k = 0;
	int erros = 0;
	for (x = 0; x < tamanho_cadeia(cadeia); x++){
		erros = 0;
		for (y = 0; y < tamanho_cadeia(subcadeia); y++){
		
			if (cadeia[x+y] != subcadeia[y]){
				erros++;
			} 
			if (cadeia[x+y] == 0) goto rest;
		}
		if (erros == 0){
			
			k++;
			
			ret[k] = &cadeia[x+tamanho_cadeia(subcadeia)];
			cadeia[x] = '\0';
			
		}
		
	}
	rest:
	return ret;
}



