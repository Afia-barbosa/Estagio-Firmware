#ifndef INIMIGOS_H
#define INIMIGOS_H
#include <stdbool.h>

// Move todos os inimigos da lista pela mesma distância
void moverInimigos(Inimigos *listaInimigos, int movimentoXpersonagem, int movimentoYpersonagem);

// Aplica dano a um inimigo específico
void aplicarDanoAoInimigo(Inimigos *inimigo, int dano); 

// Função para remover um inimigo da lista
void removerInimigo(Inimigos **inicio, Inimigos *inimigo);

#endif
