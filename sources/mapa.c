#include "../headers/mapa.h"
#include "../headers/modoAnalise.h"
#include <stdbool.h>
#include <string.h>

char** initMapa(int linha, int coluna){
    char **mapa;
    int i;

    mapa = malloc((linha)*sizeof(char*));
    for ( i = 0; i < linha; i++)
    {
        mapa[i] = malloc((coluna)*sizeof(char));
    }
   
    return mapa;
}

void preencherMapa(Mapa *mapa, char* nomeArquivo){
    FILE *arquivo;
    int cont = 0;
    int pforca;
    int recompensa;
    char *var;
    int i,j;
    arquivo = fopen(nomeArquivo,"r");
    while(!feof(arquivo)){
       fscanf(arquivo,"%d %d",&pforca, &recompensa);
       if(cont == 0){ //Cada if vai representar uma linha do arquivo
          mapa->heroi.forca = pforca;
          mapa->heroi.kflash = recompensa;
       }
       else if(cont == 1){
           mapa->U.forca = pforca;
           mapa->U.recompensa = recompensa;
       }
       else if(cont == 2){
           mapa->T.forca = pforca;
           mapa->T.recompensa = recompensa;
       }
       else if(cont == 3){
           mapa->S.forca = pforca;
           mapa->S.recompensa = recompensa;
       }
       else if(cont == 4){
           mapa->B.forca = pforca;
           mapa->B.recompensa = recompensa;
       }
       else if(cont == 5){
           mapa->G.forca = pforca;
           mapa->G.recompensa = recompensa;
       }else if(cont == 6){
            mapa->mapa = initMapa(pforca, recompensa);
            mapa->linha = pforca;
            mapa->coluna = recompensa;
            var = (char*)malloc(sizeof(char)*mapa->linha);
            for( i = 0; i < mapa->linha; i++){
                fscanf(arquivo,"%s",var);
                for( j = 0;j < mapa->coluna; j++){
                    mapa->mapa[i][j] = var[j];
                    if(mapa->mapa[i][j] == '@'){
                        mapa->heroi.i = i;
                        mapa->heroi.j = j;
                    }
                }
            }
            fclose(arquivo);
            break;
       }
       cont++;
    }
}


int movimentar(Mapa *mapa, int i, int j,Pilha* pilha,char posAntiga,int opAntiga, modoAnalise *m, int nivel,int *ptr){
    m->quantidadeRecursao = *ptr;
    *ptr +=1;
    if(nivel == 0){
        m->nivel = nivel;
    }
    if(nivel > m->nivel){
        m->nivel = nivel;
    }

    int acabou=false;
    int teveLuta=false;
    char string[10000];
    char aux = mapa->mapa[i][j];
    Item item;
    
    int forca=mapa->heroi.forca;
    int kflash=mapa->heroi.kflash;
    int novaForca=forca;
    int novokFlash=kflash;

     //Marcando posição atual
    if(aux!=('+')) mapa->mapa[i][j]='X';

    if(aux=='G'|| aux=='U' || aux=='S' || aux=='T' || aux=='B'){
        if(aux=='G'){
            
            if(lutar(mapa,aux)){
               sprintf(string,"Linha %d, Coluna %d; P: %d, k: %d\n",i,j,forca,kflash);
               inicializarItem(&item,string);
                addItem(pilha,&item);
               return true;
               
            }else{
                mapa->mapa[i][j]=aux;
                return false;
            }
        }else{
           if(lutar(mapa,aux)) {
               mapa->mapa[i][j]='+';
               teveLuta=true;
                 novaForca=mapa->heroi.forca;
                 novokFlash=mapa->heroi.kflash;
               }
           else{
               mapa->mapa[i][j]=aux;
               return false;
           }    
        }
    }

     if(posAntiga=='+' && aux=='+'){
        if(simular(opAntiga,0)){ 
                mapa->heroi.forca=forca;
                mapa->heroi.kflash=kflash;
            return false;}
    }
    //Verificando os caminhos possíveis
    if(posicaoEhValida(mapa, i-1, j) && aux !='-' ){  //para cima
      acabou=movimentar(mapa, i-1, j,pilha,aux,0,m,nivel+1,ptr);
    }   

    if(acabou){
        if(teveLuta){
             sprintf(string,"Linha %d, Coluna %d; P: %d, k: %d\n",i,j,novaForca,novokFlash);
        }else{
             sprintf(string,"Linha %d, Coluna %d;\n",i,j);
        }
        inicializarItem(&item,string);
        addItem(pilha,&item);
        return true;
    }
    

     if(posAntiga=='+' && aux=='+'){
        if(simular(opAntiga,1)) {
                mapa->heroi.forca=forca;
                mapa->heroi.kflash=kflash;
            return false;}
    }

    if(posicaoEhValida(mapa, i+1, j) && aux!='-'){  //para baixo
       acabou=movimentar(mapa, i+1, j,pilha,aux,1,m,nivel+1,ptr);
    }
    if(acabou) {
          if(teveLuta){
             sprintf(string,"Linha %d, Coluna %d; P: %d, k: %d\n",i,j,novaForca,novokFlash);
        }else{
             sprintf(string,"Linha %d, Coluna %d;\n",i,j);
        }
          inicializarItem(&item,string);
               addItem(pilha,&item);
        return true;
}
     if(posAntiga=='+' && aux=='+'){
        if(simular(opAntiga,2)) {
                mapa->heroi.forca=forca;
                mapa->heroi.kflash=kflash;
            return false;}
    }
    if(posicaoEhValida(mapa, i, j+1) &&  aux != '|'){  //para Direita
         acabou=movimentar(mapa, i, j+1,pilha,aux,2,m,nivel+1,ptr);
    }
    if(acabou) {
          if(teveLuta){
             sprintf(string,"Linha %d, Coluna %d; P: %d, k: %d\n",i,j,novaForca,novokFlash);
        }else{
             sprintf(string,"Linha %d, Coluna %d;\n",i,j);
        }
          inicializarItem(&item,string);
               addItem(pilha,&item);
        
        return true;}


     if(posAntiga=='+' && aux=='+'){
        if(simular(opAntiga,3)) {
                mapa->heroi.forca=forca;
                mapa->heroi.kflash=kflash;
            return false;}
    }
    if(posicaoEhValida(mapa, i, j-1)&& aux != '|'){  //para Esquerda
         acabou=movimentar(mapa, i, j-1,pilha,aux,3,m,nivel+1,ptr);
    }
    if(acabou) {
          if(teveLuta){
             sprintf(string,"Linha %d, Coluna %d; P: %d, k: %d\n",i,j,novaForca,novokFlash);
        }else{
             sprintf(string,"Linha %d, Coluna %d;\n",i,j);
        }
          inicializarItem(&item,string);
               addItem(pilha,&item);
        
        return true;
}
    //Desmarcando posição atual
    mapa->mapa[i][j]=aux;
    mapa->heroi.forca=forca;
    mapa->heroi.kflash=kflash;

    return false; 
}
int simular(int opAnterior, int opAtual){
    if((opAnterior==0 && opAtual==1) ||
     (opAnterior==1 && opAtual==0) ||
      ((opAnterior==2 && opAtual==3) || 
      (opAnterior==3 && opAtual==2) )){ return true;}
    else{return false;}
}



int posicaoEhValida(Mapa *mapa, int i, int j){
    if(i<0 || j<0 || i >= mapa->linha || j>= mapa->coluna){
        return false;
    }else if(mapa->mapa[i][j]=='X' || mapa->mapa[i][j]=='.'){
        return false;
    }else{
         return true;
    }
}

int lutar(Mapa* mapa,char monstro){
    char v[] = {'U', 'T', 'S', 'B'};
    int poder[] = {mapa->U.forca, mapa->T.forca, mapa->S.forca, mapa->B.forca};
    int recompensa[] = {mapa->U.recompensa,mapa->T.recompensa, mapa->S.recompensa, mapa->B.recompensa};
    int k;
     if(monstro=='G'){
         if(mapa->heroi.forca >=  mapa->G.forca){
                mapa->heroi.forca += mapa->G.recompensa;
                return true;
            }else {
                return false;
            }
     }
    for( k = 0; strlen(v); k++){
        if(monstro == v[k]){
            if(mapa->heroi.forca >= poder[k]){
                mapa->heroi.forca += recompensa[k];
                return true;
            }else if(mapa->heroi.kflash > 0){
                mapa->heroi.kflash -= 1;
                mapa->heroi.forca += recompensa[k];
                return true;
            }
        }
    }

return false;
}


void printMapa(Mapa *mapa){
    int i,j;
    for( i = 0; i < mapa->linha; i ++){
        for( j = 0;j < mapa->coluna; j++){
            printf("%c", mapa->mapa[i][j]);
        }
        printf("\n");
    }
}


