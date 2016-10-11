#include <stdio.h>
#include "inteiro.h"
    int main()
    {
        int *v1=NULL,*v2=NULL,t1=0,t2=0,t3=0,*v3=NULL;
        printf("tamanho v1\t");
        scanf("%d",&t1);
        printf("tamanho v2\t");
        scanf("%d",&t2);
        v1=criar_vetor(t1);
        v2=criar_vetor(t2);
        printf("valores para v1\n");
        for(i=0; i<t1; i++)
        {
            printf("v1[%d]\t",i);
            scanf("%d",&v1[i]);
        }
        printf("valores para v2\n");
        for(i=0; i<t2; i++)
        {
            printf("v2[%i]\t",i);
            scanf("%d",&v2[i]);
        }
        imprimir(v1,t1);
        imprimir(v2,t2);
        t3=t1+t2;
        v3=concatenar_vetores(v1,t1,v2,t2);
        imprimir(v3,t3);
        destruir_vetor(&v1);
        destruir_vetor(&v2);
        destruir_vetor(&v3);
        return 0;
    }

    t3=t1+t2;
    v3=concatenar_vetores(v1,t1,v2,t2);
    imprimir(v3,t3);
    destruir_vetor(&v1);
    destruir_vetor(&v2);
    destruir_vetor(&v3);
    return 0;
}
