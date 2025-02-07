#ifndef TABULEIRO_H
#define TABULEIRO_H
#include <stdbool.h>

//inicializando o tabuleiro com as dimensoes 
char **inicializar_tabuleiro(int quantidade_linha, int quantidade_coluna);

//printando o tubuleiro
void printar_tabuleiro(int quantidade_linha, int quantidade_coluna);

//liberar a memoria alocada
void liberar_tabuleiro(char **tabuleiro, int quantidade_linha);

//gerando posicao aleatoria
void gerar_posi_aleatorias(int quantidade_linha, int quantidade_coluna);

void setCaracter(char **tabuleiro, int x, int y, char c);

#endif

