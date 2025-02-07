#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tabuleiro.h"

int i;

int main() {
	setbuf(stdout, (NULL));
	
    int quantidade_linha;
    int quantidade_coluna;

    printf("Digite a quantidade de linha: ");
    scanf("%d", &quantidade_linha);

    printf("Digite a quantidade de coluna: ");
    scanf("%d", &quantidade_coluna);
    
	
	//inicializando o tabuleiro
    char **tabuleiro = inicializar_tabuleiro(quantidade_linha, quantidade_coluna);
    
    //colando os elementos
    int x = 1, y = 1;
    setCaracter(tabuleiro, x, y, 'P');
    
    //colando os elementos de forma aleatoria 
    gerar_posi_aleatorias(quantidade_linha, quantidade_coluna);
    
    //printando o tubuleiro
    printar_tabuleiro(quantidade_linha, quantidade_coluna);

    	
	while(1){
		if(kbhit()){
			char tecla = getch();
			if(tecla == 27){
				break;
			}
			moverPersonagem(tabuleiro, &x, &y, tecla, quantidade_linha, quantidade_coluna);
		}
	}
    
    //liberar memoria 
    liberar_tabuleiro(tabuleiro, quantidade_linha);
    
    return 0;
}

