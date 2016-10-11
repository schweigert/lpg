#include <stdio.h>
#include <stdlib.h>

#define TAM_NOME 40
#define TAM_END 200

typedef struct {
	char *rua;
	int numero;
}Endereco;

typedef struct {
	int matricula;
	char *nome;
	Endereco ende;
}Aluno;

typedef struct {
	Aluno *alunos;
	int membros;
}Turma;

int main (void){
	
	// VARIAVEIS INICIAIS
	Turma tur;
	int sair = 0;
	Aluno *temp = NULL;
	int i = 0;
	// ZERAR A TURMA
	tur.alunos = NULL;
	tur.membros = 0;
	
	while (!sair){
		tur.membros++;
		i = tur.membros -1;
		
		// ALOCAR UM NOVO ALUNO
		temp = (Aluno*)realloc(tur.alunos,tur.membros*sizeof(Aluno));
		
		// VERIFICAR SE ALOCOU!
		if (temp == NULL){
			tur.membros--;
			printf("Erro alocando memoria!\n");
			continue;
		}
		
		tur.alunos = temp;
		tur.alunos[i].nome=(char*)malloc(sizeof(char)*TAM_NOME);
		tur.alunos[i].ende.rua = (char*)malloc(sizeof(char)*TAM_END);
		
		printf("Informe Matrícula, nome, rua e endereco:\n");
		scanf("%d%s%s%d", &tur.alunos[i].matricula, tur.alunos[i].nome, tur.alunos[i].ende.rua, &tur.alunos[i].ende.numero);
		printf("\n\n\tDeseja sair?\t\n");
		scanf ("%d",&sair);
		
	}
	
	printf ("\n\n Alunos Cadastrados:\n\n");
	
	for (i=0; i < tur.membros;i++){
		
		printf("Matricula: %d\tNome:%s\tEndereco:%s,%d\n",
		tur.alunos[i].matricula,
		tur.alunos[i].nome,
		tur.alunos[i].ende.rua,
		tur.alunos[i].ende.numero);
		
		
	}
	
	for (i=0;i<tur.membros;i++){
		free(tur.alunos[i].ende.rua);
		free(tur.alunos[i].nome);
	}
	free(tur.alunos);
	tur.alunos=NULL;
	tur.membros=0;
		
	return 0;
	
}
