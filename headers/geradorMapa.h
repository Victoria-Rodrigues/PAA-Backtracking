#ifndef GERADORMAPA_H
#define GERADORMAPA_H

char** alocaMatriz(int linha, int coluna);

void mapaFacil(); //7 x 10

void mapaMedio(); //10 x 13

void mapaDificil(); //13 x 16

char geradorMapa(int linha, int coluna, char **matriz, int monstros);

void printMatriz(char **matriz,int linha,int coluna);

#endif