#include "../headers/monstro.h"
#include <stdio.h>
#include <stdlib.h>

void printMonstro(monstro *m){
    printf("%d", m->forca);
    printf("%d", m->recompensa);
}