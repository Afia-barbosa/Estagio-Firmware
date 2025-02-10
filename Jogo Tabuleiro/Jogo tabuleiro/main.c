#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tabuleiro.h"
#include "personagem.h"
#include "inimigos.h"
#include "itens.h"
#include "obstaculo.h"

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
    
    //Inicianlizando a lista de inimigos
    Inimigos *listaInimigos = NULL;  
    
    //colando os inimigos de forma aleatoria 
   	void gerarInimigos(tabuleiro, qLinha, qColuna, &listaInimigos);
   	
   	//colando os itens de forma aleatoria 
	void gerarItens(tabuleiro, qLinha, qColuna);
	
	//colando os obstaculos de forma aleatoria 
	void gerarItens(tabuleiro, qLinha, qColuna);
   	
    
    //printando o tubuleiro
    printar_tabuleiro(qLinha, qColuna);

    	
	while(1){
		if(kbhit()){
			char tecla = getch();
			if(tecla == 27){
				break;
			}
			moverPersonagem(tabuleiro, &x, &y, tecla, qLinha, qColuna);
			
			moverInimigos(listaInimigos, x, y);
			
			printar_tabuleiro(tabuleiro, qLinha, qColuna);
			
		}
	}
    
    //liberar memoria 
    liberar_tabuleiro(tabuleiro, qLinha);
    
     Inimigos *inimigoAtual = listaInimigos;
    while (inimigoAtual != NULL) {
        Inimigos *prox = inimigoAtual->proximo;
        free(inimigoAtual);
        inimigoAtual = prox;
    }
    
    return 0;
}

