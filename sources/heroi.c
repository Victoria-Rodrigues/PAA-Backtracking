#include "../headers/heroi.h"
#include <stdlib.h>
#include <stdio.h>

void printHeroi(Heroi *heroi){
    printf("%d\n",heroi->forca);
    printf("%d\n", heroi->j);
    printf("%d\n", heroi->i);
}