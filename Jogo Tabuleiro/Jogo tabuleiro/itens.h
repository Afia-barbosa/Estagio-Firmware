#ifndef ITENS_H
#define ITENS_H
#include <stdbool.h>
#include "personagem.h"


typedef struct{
	int x, y;
	int vida;
	struct Itens *proximo;
	 
}Itens;


void gerarItens(char **tabuleiro, int quantidade_linha, int quantidade_coluna);

void itensJogo(Itens **lista, Personagem *personagem);

#endif
