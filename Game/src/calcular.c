#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "calcular.h"


int pontos = 0;

// Função para definir os valores com base na dificuldade
void definir_valores(Calcular *calc) { //mundanca de Àfia
    int maximo;


    switch (calc->dificuldade) {
        case 1:
            maximo = 10; // Nível fácil: valores de 0 a 10
            break;
        case 2:
            maximo = 100;
            break;
        case 3:
            maximo = 1000;
            break;
        default:
            printf("Nível de dificuldade inválido!\n");
            exit(1);
    }

    // Define os valores aleatórios com base no intervalo
    calc->valor1 = rand() % (maximo + 1); // Gera valores de 0 até "maximo" :)
    calc->valor2 = rand() % (maximo + 1);
}

void jogar(){
	Calcular calc;
	int dificuldade;
	int continuar;
	int rodadas = 0; //para saber a quatidade de rodadas

	do {

		printf("Informe o nivel de dificuldade desejado [1, 2, 3]:\n");
		scanf("%d", &dificuldade);
		calc.dificuldade = dificuldade;

		calc.operacao = rand() % 3;
		definir_valores(&calc); //chamando a funcao


			int resposta;
			printf("Informe o resultado para a seguinte operação: \n");

			//somando
			if(calc.operacao == 0){
				printf("%d + %d\n", calc.valor1, calc.valor2);
				scanf("%d", &resposta);

				if(somar(resposta, calc)){
					pontos += 1;
					printf("Você ganhou %d pirulito(s).\n", pontos);
				}
			}//diminuindo
			else if(calc.operacao == 1) {
				if (calc.valor1 < calc.valor2){//validação
					int menor = calc.valor1;
					calc.valor1 = calc.valor2;
					calc.valor2 = menor;
				}
				printf("%d - %d\n", calc.valor1, calc.valor2);
				scanf("%d", &resposta);

				if(diminuir(resposta, calc)){
					pontos += 1;
					printf("Você ganhou %d pirulito(s).\n", pontos);
				}
			}//multiplicar
			else if(calc.operacao == 2){
				printf("%d * %d\n", calc.valor1, calc.valor2);
				scanf("%d", &resposta);

				if(multiplicar(resposta, calc)){
					pontos += 1;
					printf("Você ganhou %d pirulito(s).\n", pontos);
				}
			}//desconhcida
			else{
				printf("A operação %d nao e reconhecida.\n", calc.operacao);

			}

			mostrarInfo(calc);

			rodadas++; //conta quantas vezes o usuario jogou

			printf("Deseja continuar jogando? [1 - sim, 0 - não]\n");
			scanf("%d", &continuar);




		}while(continuar);

		printf("Você finalizou com %d pirulito(s).\n", pontos);
		printf("De %d Rodada(s)!\n", rodadas);
		printf("adeus!.\n");

}


void mostrarInfo(Calcular calc){
	char op[25];

	if(calc.operacao == 0 ){
		printf(op, "Somar");
	}else if(calc.operacao == 1){
		printf(op, "diminuir");
	}else if(calc.operacao == 2){
		printf(op, "Multiplicar");
	}else{
		printf(op, "Operacao desconhecida.");
	}

	printf("Valor 1: %d \nValor 2: %d \ndificuldade: %d \n",calc.valor1, calc.valor2, calc.dificuldade);

}

int somar(int resposta, Calcular calc){
	int resultado = calc.valor1 + calc.valor2;
    calc.resultado = resultado;
    int certo = 0; //0 == errou, 1 == acertou

    if(resposta == calc.resultado){
    	printf("Resposta correta!\n");
    	certo = 1;
    }else{
    	printf("Resposta errada!\n");
    }
    printf("%d + %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
    return certo;
}

int diminuir(int resposta, Calcular calc){ //uma validação
	int resultado = calc.valor1 - calc.valor2;

    calc.resultado = resultado;
    int certo = 0; //0 == errou, 1 == acertou

    if(resposta == calc.resultado){
    	printf("Resposta correta!\n");
    	certo = 1;
    }else{
    	printf("Resposta errada!\n");
    }
    printf("%d - %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
    return certo;
}

int multiplicar(int resposta, Calcular calc){
	int resultado = calc.valor1 * calc.valor2;
    calc.resultado = resultado;
    int certo = 0; //0 == errou, 1 == acertou

    if(resposta == calc.resultado){
    	printf("Resposta correta!\n");
    	certo = 1;
    }else{
    	printf("Resposta errada!\n");
    }
    printf("%d * %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
    return certo;
}


