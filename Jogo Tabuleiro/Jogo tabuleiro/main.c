#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tabuleiro.h"

int i;

int main() {
	setbuf(stdout, (NULL));
	
    int qLinha;
    int qColuna;

    printf("Digite a quantidade de linha: ");
    scanf("%d", &qLinha);

    printf("Digite a quantidade de coluna: ");
    scanf("%d", &qColuna);
    
	
	//inicializando o tabuleiro
    char **tabuleiro = inicializar_tabuleiro(qLinha, qColuna);
    
    //colando os elementos
    int x = 1, y = 1;
    setCaracter(tabuleiro, x, y, 'P');
    
    //colando os elementos de forma aleatoria 
    gerar_posi_aleatorias(qLinha, qColuna);
    
    //printando o tubuleiro
    printar_tabuleiro(qLinha, qColuna);

    	
	while(1){
		if(kbhit()){
			char tecla = getch();
			if(tecla == 27){
				break;
			}
			moverPersonagem(tabuleiro, &x, &y, tecla, qLinha, qColuna);
		}
	}
    
    //liberar memoria 
    liberar_tabuleiro(tabuleiro, qLinha);
    
    return 0;
}

