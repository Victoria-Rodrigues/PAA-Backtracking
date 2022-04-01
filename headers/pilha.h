#ifndef PILHA_H
#define PILHA_H

typedef struct Item* Apontador;

typedef struct Item
{
    struct Item* proximo;
    char* string;
}Item;

typedef struct{
    struct Item* itemTopo;
}Pilha;

char* popItem(Pilha* pilha);
void addItem(Pilha* pilha,Item *item);
void inicializarItem(Item* item,char* string);
void esvaziarPilha(Pilha* pilha);
#endif