#ifndef INIMIGOS_H
#define INIMIGOS_H
#include <stdbool.h>

typedef struct Inimigos{
    int x, y;
    int vida;
    struct Inimigos *proximo;
}Inimigos;

//gerar posicao aleatoria de inimigos 
void gerarInimigos(char **tabuleiro, int quantidade_linha, int quantidade_coluna);

// Move todos os inimigos da lista pela mesma distância
void moverInimigos(Inimigos *listaInimigos, int movimentoXpersonagem, int movimentoYpersonagem);

// Função para remover um inimigo da lista
void removerInimigo(Inimigos **inicio, Inimigos *inimigo);


#endif
