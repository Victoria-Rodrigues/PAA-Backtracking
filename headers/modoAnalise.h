#ifndef MODOANALISE_H
#define MODOANALISE_H


typedef struct{
    long long int quantidadeRecursao;
    int nivel;
}modoAnalise;

void imprimirAnalise(modoAnalise *m,double tempo);

#endif