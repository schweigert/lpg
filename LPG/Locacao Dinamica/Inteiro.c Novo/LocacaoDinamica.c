#include <stdio.h>
#include <stdlib.h>
#include "inteiro.h"

int main (void)
{
    int *v1 = NULL;
    int *v2 = NULL;
    int tamanho = 0;
    int novos = 0;
    int i;

    printf ("INFORME O TAMANHO DO VETOR \n");
    scanf ("%d",&tamanho);

    v1 = criar_vetor(tamanho);
    if (v1==NULL)
    {
        exit(EXIT_FAILURE);
    }
    printf("INFORME OS VALORES\n");
    for (i=0; i<tamanho; i++)
    {
        scanf("%d",&v1[i]);
    }
    printf ("QUANTAS CASAS A MAIS?\t");
    scanf("%d",&novos);
    v2=realocar_vetor(v1,tamanho,&novos);
    if (!v2)
    {
        printf("NÃO FOI POSSIVEL ALTERAR O VETOR\n");
        novos=0;
    }
    else
    {
        v1=v2;
    }
    for (i=0; i < novos; i++)
    {
        scanf("%d",&v1[tamanho+i]);
    }
    tamanho+= novos;
    printf("CONTEUDO DO VETOR\n");
    imprimir(v1,tamanho);

    return 0;
}
