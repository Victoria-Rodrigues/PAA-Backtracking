#include "../headers/pilha.h"
#include <stdlib.h>
#include <stdio.h>

void inicializarItem(Item* item,char* string){
    item->string=string;
    item->proximo= NULL;
}

void addItem(Pilha* pilha,Item *item){
    if(pilha->itemTopo== NULL){
        pilha->itemTopo = item;
    }else{
        item->proximo=pilha->itemTopo;
        pilha->itemTopo=item;
    }
}

char* popItem(Pilha* pilha){
    Item* aux;
    aux = pilha -> itemTopo;
    pilha->itemTopo = aux->proximo;
    return aux->string;
}

void esvaziarPilha(Pilha* pilha){
    while(pilha->itemTopo!=NULL){
        printf("%s",popItem(pilha));
    }
}