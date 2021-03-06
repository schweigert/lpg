#include <stdio.h>
#include <stdlib.h>
#include "inteiro.h"



int* realocar_vetor(int *v, int tamanho_atual,int *novos_elementos){
    int *p = NULL;
    p = (int*)realloc(v,(tamanho_atual+novos_elementos)*sizeof(int));
    return p;


}


void imprimir(int *v1,int t)
{
    int i;
    for(i=0; i<t; i++)
    {
        printf("%d=%d\n",i,v1[i]);
    }
}
int *criar_vetor(int tam)
{
    int *ret=NULL;
    if((ret=(int *)malloc(tam*sizeof(int)))==NULL)
    {
        exit(EXIT_FAILURE);
    }
    return ret;
}

void destruir_vetor(int **v)
{
    free(*v);
    *v=NULL;
}

int *concatenar_vetores(int *v1,int t1,int *v2, int t2)
{
    int *ret;
    int i;

    ret = criar_vetor(t1+t2);

    for(i=0; i<t1; i++)
    {
        ret[i]=v1[i];
    }
    for(i=0; i<t2; i++)
    {
        ret[i+t1-1]= v2[i];
    }

    return ret;
}
