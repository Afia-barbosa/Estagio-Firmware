#include "tabuleiro.h"
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

char **tabuleiro = NULL;//fazendo o tabuleiro apontar para NULL inicialmente

int i, j;

char  **inicializar_tabuleiro(int quantidade_linha, int quantidade_coluna){


    if(tabuleiro != NULL){
        return;
    }

    tabuleiro = (char**)malloc(quantidade_linha * sizeof(char*));

    if(tabuleiro == NULL){
        printf("Erro ao alocar memória para as linhas!\n");
        return;
    }


    for(i = 0; i < quantidade_linha; i++){
        tabuleiro[i] = (char *)malloc(quantidade_coluna * sizeof(char));
        if(tabuleiro[i] == NULL){
          printf("Erro ao alocar memória para as colunas!\n");
          return;
        }
    }
    
    
	//estruturando o tabuleiro 
    for(i = 0; i < quantidade_linha; i++){
        for(j = 0; j < quantidade_coluna; j++){
           if(i == 0|| i == quantidade_linha - 1 || j == 0|| j == quantidade_coluna - 1){//posicao da borda
             tabuleiro[i][j] = '*';
           }
           else{
             tabuleiro[i][j] = '.';//dentro da matriz sera .
            }
        }
    }
    
    return tabuleiro;

}


void printar_tabuleiro(int quantidade_linha, int quantidade_coluna){
	
     for(i = 0; i < quantidade_linha; i++){
        for(j = 0; j < quantidade_coluna; j++){
           printf("%c ", tabuleiro[i][j]);
    	}
     printf("\n");
    }
    printf("\n");
}

void liberar_tabuleiro(char **tabuleiro, int quantidade_linha) {
    if (tabuleiro != NULL) {
        for (i = 0; i < quantidade_linha; i++) {
            free(tabuleiro[i]); // Libera cada linha
        }
        free(tabuleiro); // Libera o array de ponteiros
        tabuleiro = NULL; // Evita uso de memória já liberada
    }
}

//fazer uma funcao para gerar posicoes 

void gerar_posi_aleatorias(int quantidade_linha, int quantidade_coluna){
	//garantindo que os numero sejam mais aleatorios possiveis
	srand(time(NULL));
	
	//posicao aleatoria para o obstaculo
	int linha_obs = rand() % (quantidade_linha - 2) + 1; //-2 para evitar printar na borda
	int coluna_obs = rand() % (quantidade_coluna - 2) + 1; //-2 para evitar printar na borda
	setCaracter(tabuleiro, linha_obs, coluna_obs, 'X');
	
	
	//posicao aleatoria para o itens
	int linha_itens = rand() % (quantidade_linha - 2) + 1; //-2 para evitar printar na borda
	int coluna_itens = rand() % (quantidade_coluna - 2) + 1; //-2 para evitar printar na borda
	setCaracter(tabuleiro, linha_itens, coluna_itens, 'I');
	
	
	//posicao aleatoria para o inimigos
	int linha_inimigos = rand() % (quantidade_linha - 2) + 1; //-2 para evitar printar na borda
	int coluna_inimigos = rand() % (quantidade_coluna - 2) + 1; //-2 para evitar printar na borda
	setCaracter(tabuleiro, linha_inimigos, coluna_inimigos, 'E');
	
}



//setando caractere 
void setCaracter(char **tabuleiro, int y, int x, char c){
    if(tabuleiro != NULL){
    	tabuleiro[x][y] = '.';
    	tabuleiro[x][y] = c;
    }
}







