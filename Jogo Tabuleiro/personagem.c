#include "personagem.h"
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>

//Personagem: O personagem do jogador será representado por uma struct, contendo:
//Posição no tabuleiro (x, y).
//Pontuação (inicialmente 0).
//Vida (inicialmente 100).


//estrutura do personagem
typedef struct Personagem{
	int y, x;
	int pontuacao;
	int vida;
	
}personagem;


//funcao para limpar a posicao antiga do P
void limparposicaoPersonagem(char **tabuleiro, int x, int y) {
    tabuleiro[y][x] = ' ';
     
}


void moverPersonagem(char **tabuleiro, int *x, int *y, char tecla, int quantidade_linha, int quantidade_coluna){
	
	limparposicaoPersonagem(tabuleiro, *x,*y);
	
	#ifdef _WIN32 
        system("cls");  // Para Windows
    #else
        system("clear"); // Para Linux/macOS
    #endif

    // Movimentação baseada na tecla pressionada
    switch(tecla){
        case 'a':  // Esquerda
            if (*x > 1) (*x)--;
            break;
        case 'd':  // Direita
            if (*x < quantidade_coluna - 2) (*x)++;
            break;
        case 'w':  // Cima
            if (*y > 1) (*y)--; 
            break;
        case 's':  // Baixo
            if (*y < quantidade_linha - 2) (*y)++; 
            break;
        default:
            printf("Tecla invalida!\n");
    }
    
	//funcao para checar caractere 	
    setCaracter(tabuleiro, *x, *y, 'P');
    
    //funcao para checar se tem algum elemento nas posicoes
    
    

    // Imprime o tabuleiro atualizado
    printar_tabuleiro(quantidade_linha, quantidade_coluna);
    
    printf("Teste: Personagem movido para: x = %d, y = %d\n", *x, *y);
}

