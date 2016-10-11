#include <stdio.h>
#include <stdlib.h>



int tamanho_cadeia(char* cadeia){// DONE

	int x = 0;
	int y = 0;

	for (x = 0; cadeia[x] != '\0'; x++){

		y++;

	}

	return y;

}

// ========================================================================================== //
// ========================================================================================== //

void imprime_cadeia(char* cadeia){// DONE

	int x;
	int y = tamanho_cadeia(cadeia);
	for (x = 0; x < y; x++){

		printf ("%c", cadeia[x]);

	}
	printf ("\n");
}

// ========================================================================================== //
// ========================================================================================== //

int compara_cadeias(char* cadeia1, char* cadeia2){// DONE

	while (*cadeia1 != 0 && *cadeia2 != 0){

		if (*cadeia1 != *cadeia2) return *cadeia1 - *cadeia2;

		cadeia1++; cadeia2++;
	}
	return tamanho_cadeia(cadeia1)-tamanho_cadeia(cadeia2);

}

// ========================================================================================== //
// ========================================================================================== //

char* clona_cadeia (char* fonte){// DONE

	char *c;
	c = (char*)malloc(sizeof(char)*(tamanho_cadeia(fonte)));

	int x;

	for (x = 0; x < tamanho_cadeia(fonte); x++){

		*(c+x) = *(fonte+x);

	}

	return c;

}

// ========================================================================================== //
// ========================================================================================== //

int copia_cadeia(char* destino, char* origem){ // DONE


	int x;


	for (x = 0; origem[x] != '\0'; x++){

		*(destino+x) = *(origem+x);	

	}

	return x-1;

}

// ========================================================================================== //
// ========================================================================================== //

int altera_caracteres_cadeia(char* destino, char caractere, int n){// DONE


	int x = 0;
	for (x = 0; x < n && x < tamanho_cadeia(destino); x++){

		destino[x] = caractere;

	}

	return x-1;


}

// ========================================================================================== //
// ========================================================================================== //

int concatena_cadeia (char* destino, char* fonte){// DONE

	int tam = tamanho_cadeia(destino) + tamanho_cadeia(fonte)+1;
	
	destino = realloc(destino, tam);
	//destino = (char*) realloc (destino, tam);
	int x = tamanho_cadeia(destino);
	int y = x;

	for(; x < tam; x++){

		*(destino+x) = *(fonte+x-y);

	}

	*(destino+x) = '\0';

	return tamanho_cadeia(destino);

}


// ========================================================================================== //
// ========================================================================================== //

int concatena_caracteres_cadeia (char* destino, char* fonte, int n){// DONE

	char *c;
	int x,y;


	if(tamanho_cadeia(fonte) < n){

		y = tamanho_cadeia(fonte);

	} else {

		y = n;

	}


	c = (char*)malloc(sizeof(char)*(y+1));

	for (x = 0; x < y; x++){

		*(c+x) = *(fonte+x);

	}

	*(c+x) = '\0';

	concatena_cadeia(destino,c);

	return tamanho_cadeia(destino);

}

// ========================================================================================== //
// ========================================================================================== //

int* busca_caracteres_cadeia(char* cadeia,char caractere){// DONE

	int tam = tamanho_cadeia(cadeia);
	int x;
	int y = 0;
	int z = 0;

	for(x = 0; x < tam; x++){
	
		if(cadeia[x] == caractere){
		
			y++;
		
		}
	
	}

	int *c = NULL;
	c = (int*)malloc(sizeof(char)*(y+1));

	for(x = 0; x < tam; x++){
	
		if(cadeia[x] == caractere){
		
			*(c+z) = x;
			z++;
		
		}
	
	}
	*(c+z) = -1;

	return c;
}
// ========================================================================================== //
// ========================================================================================== //

int quantidade_caracteres_presentes(char* cadeia1, char* cadeia2){

	int i,j;
	int tam1,tam2;
	int c = 0;

	tam1 = tamanho_cadeia(cadeia1);
	tam2 = tamanho_cadeia(cadeia2);

	for(i = 0; i < tam1; i++){

		for(j = 0; j < tam2; j++){

			if(cadeia1[i] == cadeia2[j]){

				c++;

			}

		}

	}

	return c;

}

// ========================================================================================== //
// ========================================================================================== //

char** separa_cadeia(char* fonte, char* divisor){// Fatality!!!

	char **c = NULL;
	int x = 0;
	int y = 0;

	int tamx = tamanho_cadeia(fonte);
	int tamy = tamanho_cadeia(divisor);

	int flag = 0;

	for(x = 0; x < tamx; x++){

		for(y = x; y < tamy+x && y < tamx; y++){

				putchar(fonte[x]);
			if(fonte[y] != divisor[y-x]){
				
				x += tamy;
				puts("");
				puts("--DIVIDIU!");
				break;

			}

		}

	}



	return c;



//--------------------------//


	/*char **c = NULL;
	int x = 0;
	int y = 0;
	int k = 0;
	int j = 0;
	int aux = 0;

	c = (char**) malloc (sizeof(char*));
	c[0] = (char*) malloc (sizeof(char));

	int tam = tamanho_cadeia(fonte);
	int tamy = tamanho_cadeia(divisor);

	for(; x < tam; x++){

		aux = 0;
		

		for(y = x; y < tamy+x && fonte[y] != '\0'; y++){

			
			printf("%c\n", fonte[x]);

			if(fonte[y] == divisor[y-x]){
				aux++;
			}

		}

		if(aux != y-x-1){

	puts("DIVIDIU!!!");
			k++;
			x += tamy;
			c = realloc(c, sizeof(char*)*k+1);
			j = 0;

		} else {

			j++;
			c[k-1] = (char*) realloc (c[k], sizeof(char)*j+1);
			c[k-1][j] = '\0';
			c[k-1][j-1] = fonte[x];

		}

	}

	k++;
	c = realloc(c, sizeof(char*)*k);
	c[k-1] = NULL;

	puts("TERMINOU!!");

	return c;*/
}

// ========================================================================================== //
// ========================================================================================== //

int converte_para_maiusculo(char* cadeia){// DONE

	int tam = tamanho_cadeia(cadeia);
	int x = 0;
	for (x = 0 ; x < tam; x++){

		if(cadeia[x] >= 'a' && cadeia[x] <= 'z'){

			*(cadeia+x) -= 32;

		}

	}

	return x-1;
}

// ========================================================================================== //
// ========================================================================================== //

int converte_para_minusculo(char* cadeia){// DONE

	int tam = tamanho_cadeia(cadeia);
	int x = 0;
	for (x = 0 ; x < tam; x++){

		if((int)cadeia[x] >= 65 && (int)cadeia[x] <= 90){

			*(cadeia+x) += 32;

		}

	}

	return x-1;
}

// ========================================================================================== //
// ========================================================================================== //

int inverte_cadeia(char* cadeia){// DONE

	
	int tam = tamanho_cadeia(cadeia);
	int tamx = tam;
	if (tam%2 == 1) tam-= 1;
	int x = 0;
	char swap = 0;
	for ( ; x < tam/2; x++){

		swap = cadeia[x];
		cadeia[x] = cadeia[tamx-x-1];
		cadeia[tamx-x-1] = swap;

	}

	return tam;

}

// ========================================================================================== //
// ========================================================================================== //
char** busca_sub_cadeia(char* cadeia, char* subcadeia){
	int i=0, j=0,a=0;
	
	for(j=0;cadeia[j]!='\0';j++){
		i=0;
		if(cadeia[j]==subcadeia[0]){
			for(i=1;(subcadeia[i]!='\0')&&(subcadeia[i]==cadeia[j+i]);i++){}
		}
		if(subcadeia[i]=='\0'){
			a++;
		}
		j+=i;
	}
	pont=(char**)malloc(sizeof(char*)*(a+1)));
	a=0;
	int c = 0;
	for(i=0;i<tamanho(cadeia);i++){
		c=0;
		if(cadeia[i]==subcadeia[0]){
			for(c=1;(c<tamanho_cadeia(subcadeia))&&(subcadeia[c]==cadeia[i+c]);c++){}
		}
		if(subcadeia[c]=='\0'){
			pont[a]=cadeia+i;
			a++;
		}
		i+=c;
	}
	pont[a]=NULL;
	return pont;
}
