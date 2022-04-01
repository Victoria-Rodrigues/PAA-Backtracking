#include "../headers/geradorMapa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

char** alocaMatriz(int linha, int coluna){
    char **mapa;

    mapa = malloc((linha)*sizeof(char*));
    for (int i = 0; i < linha; i++)
    {
        mapa[i] = malloc((coluna)*sizeof(char));
    }
   
    return mapa;
}

void mapaFacil(){
    srand(time(0));
    int qtdMonstros = 7;
    int v1, v2;
    char recebe;
    int linha = 7, coluna = 10;
    char **matriz;
    matriz = alocaMatriz(linha, coluna);
    FILE *arquivo;
    char nomeArquivo[30];
    printf("Digite o nome do arquivo:\n");
    scanf("%s", nomeArquivo);
    arquivo = fopen(nomeArquivo, "w");
    if(arquivo == NULL){
        printf("Arquivo Inexistente!!");
    }else{
        for(int i = 0; i < 7; i++){
            if(i == 6){
                fprintf(arquivo,"%d %d\n", linha, coluna); 
            }else{
                v1 =  1+rand()%40;
                v2 =  1+rand()%20;
                fprintf(arquivo,"%d %d\n", v1, v2);
            }
        }
       // geraInicioFim(linha, coluna, matriz);
        geradorMapa(linha, coluna, matriz, qtdMonstros);
        for(int i = 0; i < linha; i++){
            for(int j = 0; j < coluna; j++){
                fprintf(arquivo, "%c" , matriz[i][j]);
            }
            fputc('\n',arquivo);
        }
        fclose(arquivo);
    }
}

void mapaMedio(){
    srand(time(0));
    int v1, v2;
    int qtdMonstros = 10;
    char recebe;
    int linha = 10, coluna = 13;
    char **matriz;
    matriz = alocaMatriz(linha, coluna);
    FILE *arquivo;
    char nomeArquivo[30];
    printf("Digite o nome do arquivo:\n");
    scanf("%s",nomeArquivo);
    arquivo = fopen(nomeArquivo, "w");
    if(arquivo == NULL){
        printf("Arquivo Inexistente!!");
    }else{
        for(int i = 0; i < 7; i++){
            if(i == 6){
                fprintf(arquivo,"%d %d\n", linha, coluna); //verificar se o tamanho também deve ser aleatorio?
            }else{
                v1 =  1+rand()%80;
                v2 =  1+rand()%40;
                fprintf(arquivo,"%d %d\n", v1, v2);
            }
        }
       // geraInicioFim(linha, coluna, matriz);
        geradorMapa(linha, coluna, matriz, qtdMonstros);
        for(int i = 0; i < linha; i++){
            for(int j = 0; j < coluna; j++){
                fprintf(arquivo, "%c" , matriz[i][j]);
            }
            fputc('\n',arquivo);
        }
        fclose(arquivo);
    }
}

void mapaDificil(){
    srand(time(0));
    int v1, v2;
    int qtdMonstros = 13;
    char recebe;
    int linha = 13, coluna = 16;
    char **matriz;
    matriz = alocaMatriz(linha, coluna);
    FILE *arquivo;
    char nomeArquivo[30];
    printf("Digite o nome do arquivo:\n");
    scanf("%s",nomeArquivo);
    arquivo = fopen(nomeArquivo, "w");
    if(arquivo == NULL){
        printf("Arquivo Inexistente!!");
    }else{
        for(int i = 0; i < 7; i++){
            if(i == 6){
                fprintf(arquivo,"%d %d\n", linha, coluna); 
            }else{
                v1 =  1+rand()%160;
                v2 =  1+rand()%80;
                fprintf(arquivo,"%d %d\n", v1, v2);
            }
        }
        geradorMapa(linha, coluna, matriz, qtdMonstros);
        for(int i = 0; i < linha; i++){
            for(int j = 0; j < coluna; j++){
                fprintf(arquivo, "%c" , matriz[i][j]);
            }
            fputc('\n',arquivo);
        }
        fclose(arquivo);
    }
}



//gerando o mapa
char geradorMapa(int linha, int coluna, char **matriz, int monstros){
    srand(time(0));
    int gerador;
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
                 matriz[i][j] = '.';
        }
    }
    int i = rand() % linha;
    int j = rand() % coluna;
    matriz[i][j] = '@';
    while (matriz[i][j] == '@'){
        i = rand() % linha;
        j = rand() % coluna;
    } 
    matriz[i][j] = 'G';
    for(int i = 0; i < monstros; i++){
        gerador = rand() % 4;
        while (matriz[i][j] == '@' || matriz[i][j] == 'G' || matriz[i][j] == 'U' ||  matriz[i][j] == 'T' ||  matriz[i][j] == 'S' ||  matriz[i][j] == 'B'){
           i = rand() % linha;
           j = rand() % coluna;
        }
        if(gerador == 0) {
            matriz[i][j] = 'U';
        }
        if(gerador == 1) {
            matriz[i][j] = 'T';
        }
        if(gerador == 2){
            matriz[i][j] = 'S';
        }
        if(gerador == 3){          
           matriz[i][j] = 'B';
        }
    }
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            gerador =  rand() % 4;
            if(matriz[i][j] != '@' && matriz[i][j] != 'G' && matriz[i][j] != 'U' && matriz[i][j] != 'T' && matriz[i][j] != 'S' && matriz[i][j] != 'B'){
                if(gerador == 0) matriz[i][j] = '+';
                if(gerador == 1) matriz[i][j] = '-';
                if(gerador == 2) matriz[i][j] = '|';
                if(gerador == 3) matriz[i][j] = '.';
            }
        }
    }
    printf("\n");
    printMatriz(matriz, linha, coluna);
}


void printMatriz(char **matriz,int linha,int coluna){
    printf("\n===============Mapa Gerado=================\n");
    for(int i = 0; i < linha; i ++){
        for(int j = 0; j < coluna; j++){
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
}