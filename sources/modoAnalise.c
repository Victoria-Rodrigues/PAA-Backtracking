#include "../headers/modoAnalise.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirAnalise(modoAnalise *m,double tempo){
    printf("\n====================MODO ANALISE=====================\n");
    printf("Nivel maximo da chamada recursiva:%d\n",m->nivel);
    printf("Quantidade de chamadas recursivas que foram feitas: %lld \n", m->quantidadeRecursao);
    printf("Tempo gasto: %lf ms\n",tempo);

}

