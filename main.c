#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headers/mapa.h"
#include "headers/monstro.h"
#include "headers/geradorMapa.h"
#include "headers/pilha.h"
#include "headers/modoAnalise.h"

//gcc main.c mapa.c monstro.c heroi.c geradorMapa.c pilha.c modoAnalise.c -o e
int main(){
    Mapa mapa;
    Pilha pilha;
    modoAnalise m;
    pilha.itemTopo=NULL;
    char nomeArquivo[30];
    int k = 0;
    int op[4];
    bool flag= true;
    clock_t t[2]; //variável para armazenar tempo
    double tempo = 0;
    int opcao1,opcao2;
    while (true)
    {
      flag= true;
      printf("\n=================================================\n");
      printf("========================MENU=====================\n");
      printf("=================================================\n");
      printf("[1] Inserir um arquivo\n");
      printf("[2] Geracao de arquivos de teste\n");
      printf("[0] Sair\n");
      scanf("%d", &opcao1);
      if(opcao1 == 0){
        break;
      }
      if (opcao1 == 1){
        printf("Insira nome do arquivo:");
        scanf("%s",nomeArquivo); 
        preencherMapa(&mapa, nomeArquivo);
        t[0] = clock(); //armazenando o tempo inicial
        int valor = 0; //quantidade inicial de funções recursivas
        printf("\nPercorrendo o mapa...\n");
        if(movimentar(&mapa, mapa.heroi.i, mapa.heroi.j,&pilha,' ', -1,&m,0, &valor)){
          printf("Ness matou o Giygas!!!");
        }else{
          printf("Apesar de todas as tentativas, Ness falha em derrotar Giygas!");
        }
        t[1] = clock();
        tempo = (t[1] - t[0]) * 1000.0 / CLOCKS_PER_SEC;//Tempo Final - Tempo Inicial

        printf("\n=================================================\n");
        printf("===================CAMINHO DO MAPA===============\n");
        printf("=================================================\n");
        printf("[1] Caminho normal\n");
        printf("[2] Caminho pelo do mapa\n");
        printf("Digite a opcao escolhida:");
        int op;
        scanf("%d",&op);
        if(op==1) esvaziarPilha(&pilha);
        else if(op==2){
           printf("\n");
           printMapa(&mapa);
           esvaziarPilha(&pilha);
        }
        else printf("Opcao invalida!!!\n");
        
      }
      else if(opcao1 == 2){
        printf("[1] Modo Facil\n");
        printf("[2] Modo Medio\n");
        printf("[3] Modo Dificil\n");
        printf("Digite a opcao que deseja:");
        scanf("%d", &opcao2);
        flag = false;
        if(opcao2 == 1) mapaFacil();
        else if(opcao2 == 2) mapaMedio();
        else if(opcao2 == 3) mapaDificil();
        else printf("Opcão invalida!\n");
      }
      else{
        flag = false;
        printf("Opcão invalida!Tente novamente\n");
      }
  
      if(flag){
        printf("\n=================================================\n");
        printf("====================MODO ANALISE=================\n");
        printf("=================================================\n");
        printf("\nDeseja realizar a analise desse jogo? [1]Sim - [2]Nao\n");
        int res;
        scanf("%d", &res);
        if(res == 1)imprimirAnalise(&m,tempo);
      }
         
    } 
    return 0;
}

