#include "itens.h"
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include "personagem.h"


void gerarItens(char **tabuleiro, int quantidade_linha, int quantidade_coluna){
	
	srand(time(NULL));
	
	int i;
    int linha_itens, coluna_itens;
    

	//colocando a quantidade aleatoria conforme ao tamanho do tabuleiro
    int quantidade_itens = (quantidade_linha - 2) * (quantidade_coluna - 2) / 30;
	if(quantidade_itens < 1){ 
		quantidade_itens = 1;
	}

   
    for(i = 0; i < quantidade_itens; i++){
    	do {
        linha_itens = rand() % (quantidade_linha - 2) + 1;
        coluna_itens = rand() % (quantidade_coluna - 2) + 1;
    	} while (!posicao_valida(linha_itens, coluna_itens));

    	setCaracter(tabuleiro, linha_itens, coluna_itens, 'I');
	}


}

//Se o jogador coletou um item (I). Isso aumenta a pontuação e remove o item da lista.
void itensJogo(Itens **lista, Personagem *personagem){
	if(*lista == NULL){
		return;
	}
	
	Itens *ponteiroAtual = *lista;
	Itens *ponteiroAnterior = NULL;
	
	while(ponteiroAtual != NULL){
		if(personagem->x == ponteiroAtual->x && personagem->x == ponteiroAtual->x){
			personagem->pontuacao += 10;
			
			if(ponteiroAnterior == NULL){
				*lista = ponteiroAtual->proximo;
			}else{
				ponteiroAnterior->proximo = ponteiroAtual->proximo;
			}
			
			free(ponteiroAtual);
			return;
				
		}
		ponteiroAnterior = ponteiroAtual;
		ponteiroAtual = ponteiroAtual->proximo;
	}
}







