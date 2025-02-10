#include "obstaculos.h"
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>


void gerarObstaculos(char **tabuleiro, int quantidade_linha, int quantidade_coluna){
	
	srand(time(NULL));
	int i;

	int linha_obs, coluna_obs;
	
    int quantidade_obstaculo = (quantidade_linha - 2) * (quantidade_coluna - 2) / 30;
	if(quantidade_obstaculo < 1){ 
		quantidade_obstaculo = 1;
	}
	
	 // Gerar posição aleatória para o obstaculo
    for(i = 0; i < quantidade_obstaculo; i++){
    	do {
        linha_obs = rand() % (quantidade_linha - 2) + 1;
        coluna_obs = rand() % (quantidade_coluna - 2) + 1;
    	} while (!posicao_valida(linha_obs, coluna_obs));

    	setCaracter(tabuleiro, linha_obs, coluna_obs, 'X');
	}

}





