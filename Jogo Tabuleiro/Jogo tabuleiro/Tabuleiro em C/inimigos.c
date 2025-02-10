#include "inimigos.h"
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

//adicionar inimigo
//mover inimigo

//estrutura da lista de itens 
typedef struct Inimigos{//declar isso no arquivo.h
	
	int x, y;
	int vida;
	struct Inimigos *proximo;
}Inimigos;


void gerar_posi_aleatorias(int quantidade_linha, int quantidade_coluna){
	srand(time(NULL));
	int i;
	
	//gerar posicao aleatoria para o inimigos
    int quantidade_inimigos = (quantidade_linha - 2) * (quantidade_coluna - 2) / 30;
	if(quantidade_inimigos < 1){ 
		quantidade_inimigos = 1;
	}

    // Gerar posição aleatória para o inimigo
    for( i = 0; i < quantidade_inimigos; i++){
    	do {
        linha_inimigos = rand() % (quantidade_linha - 2) + 1;
        coluna_inimigos = rand() % (quantidade_coluna - 2) + 1;
    	} while (!posicao_valida(linha_inimigos, coluna_inimigos));

    	setCaracter(tabuleiro, linha_inimigos, coluna_inimigos, 'E');
	}
}


void moverInimigos(Inimigos *listaInimigos, int movimentoXpersonagem, int movimentoYpersonagem){
	Inimigos *inimigoAtual = listaInimigos;
	
	
	while(inimigoAtual != NULL){
		//movendo o inimigo na forma horizontal
		if(inimigoAtual->x < movimentoXpersonagem){
			inimigoAtual->x += 1;
		}else if(inimigoAtual->x > movimentoXpersonagem){
			inimigoAtual->x -= 1;
		}
		
		//movendo o inimigo na forma vertical 
		if(inimigoAtual->y < movimentoXpersonagem){
			inimigoAtual->y += 1;
		}else if(inimigoAtual->y > movimentoXpersonagem){
			inimigoAtual->y -= 1;
		}

	}
	
	//passa para o proximo inimigo da lista
	inimigoAtual = inimigoAtual->proximo;
	
}


