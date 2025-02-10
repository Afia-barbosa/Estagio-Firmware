#include "inimigos.h"
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


void gerarInimigos(char **tabuleiro, int quantidade_linha, int quantidade_coluna, Inimigos **listaInimigos) {
    srand(time(NULL)); 
    int i;

    int quantidade_inimigos = (quantidade_linha - 2) * (quantidade_coluna - 2) / 30;
    if (quantidade_inimigos < 1) {
        quantidade_inimigos = 1;
    }

    int linha_inimigos, coluna_inimigos;

    for (i = 0; i < quantidade_inimigos; i++) {
        do {
            linha_inimigos = rand() % (quantidade_linha - 2) + 1;
            coluna_inimigos = rand() % (quantidade_coluna - 2) + 1;
        } while (!posicao_valida(linha_inimigos, coluna_inimigos));

        setCaracter(tabuleiro, linha_inimigos, coluna_inimigos, 'E');
        
        Inimigos *novoInimigo = (Inimigos*)malloc(sizeof(Inimigos));
        novoInimigo->x = linha_inimigos;
        novoInimigo->y = coluna_inimigos;
        novoInimigo->proximo = *listaInimigos;
        *listaInimigos = novoInimigo;
    }
}

void moverInimigos(Inimigos *listaInimigos, int movimentoXpersonagem, int movimentoYpersonagem){
    Inimigos *inimigoAtual = listaInimigos;

    while (inimigoAtual != NULL) {
        if (inimigoAtual->x < movimentoXpersonagem) {
            inimigoAtual->x += 1;
        } else if (inimigoAtual->x > movimentoXpersonagem) {
            inimigoAtual->x -= 1;
        }

        if (inimigoAtual->y < movimentoYpersonagem) { 
            inimigoAtual->y += 1;
        } else if (inimigoAtual->y > movimentoYpersonagem) {
            inimigoAtual->y -= 1;
        }

        inimigoAtual = inimigoAtual->proximo;
    }
}

void removerInimigo(Inimigos **inicio, Inimigos *inimigo) {
    if (*inicio == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    if (*inicio == inimigo) {
        *inicio = (*inicio)->proximo;
        free(inimigo);
        return;
    }

    Inimigos *aux = *inicio;
    while (aux->proximo != NULL && aux->proximo != inimigo) {
        aux = aux->proximo;
    }

    if (aux->proximo == inimigo) {
        aux->proximo = inimigo->proximo;
        free(inimigo); 
    }
}
