#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#include <stdbool.h>

void limparposicaoPersonagem(char **tabuleiro, int x, int y);
void moverPersonagem(char **tabuleiro, int *x, int *y, char tecla, int quantidade_linha, int quantidade_coluna);

#endif

