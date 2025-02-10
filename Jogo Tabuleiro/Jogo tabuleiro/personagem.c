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


//funcao para limpar a posicao antiga do P
void limparposicaoPersonagem(char **tabuleiro, int x, int y) {
    tabuleiro[y][x] = ' ';
     
}


void moverPersonagem(char **tabuleiro, int *x, int *y, char tecla, int quantidade_linha, int quantidade_coluna){
	
	int novaPosicaoX = *x;
	int novaPosicaoY = *y;
	
	#ifdef _WIN32 
        system("cls");  // Para Windows
    #else
        system("clear"); // Para Linux/macOS
    #endif

    // Movimentação baseada na tecla pressionada
    switch(tecla){
        case 'a':  // Esquerda
            if (novaPosicaoX > 1) novaPosicaoX--;
            break;
        case 'd':  // Direita
            if (novaPosicaoX < quantidade_coluna - 2) novaPosicaoX++;
            break;
        case 'w':  // Cima
            if (novaPosicaoY > 1) novaPosicaoY--; 
            break;
        case 's':  // Baixo
            if (novaPosicaoY < quantidade_linha - 2) novaPosicaoY++; 
            break;
        default:
            printf("Tecla invalida!\n");
    }
    
	if(posicao_valida(novaPosicaoX, novaPosicaoY)){
		
		limparposicaoPersonagem(tabuleiro, *x,*y);
		
		*x = novaPosicaoX;
		*y = novaPosicaoY;
		
		setCaracter(tabuleiro, *x, *y, 'P');
		
		printf("Personagem movido para: x = %d, y = %d\n", *x, *y);
	}else{
		printf("MOvimento bloquado: Obstaculo na posicao desejada.\n");
	}

    // Imprime o tabuleiro atualizado
    printar_tabuleiro(quantidade_linha, quantidade_coluna);
    
}




