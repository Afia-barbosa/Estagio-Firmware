#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "mercado.h"


static int contador_produto = 0;
static int contador_carrinho = 0;
static Carrinho carrinho[50];
static Produto produtos[50];


void infoProduto(Produto prod){
	printf("Codigo: %d \nNome: %s \nPreço: %.2f\n", prod.codigo, strtok(prod.nome, "\n"), prod.preco);

}


void menu(){
	printf("=============Bem-vindo(a)=============\n");
	printf("=========== Compras Online ===========\n");
	printf("======================================\n");

	printf("Selecione uma opcao abaixo: \n");
	printf("1 - Cadastrar produto\n");
	printf("2 - Listar produtos\n");
	printf("3 - Comprar produto\n");
	printf("4 - Visualizar carrinho\n");
	printf("5 - Fechar pedido\n");
	printf("6 - Sair do sistema\n");

	int opcao;
	scanf("%d", &opcao);
	getchar();

	switch(opcao){
		case 1:
			cadastrarProduto();
			break;
		case 2:
			listarProduto();
			break;
		case 3:
			comprarPorduto();
			break;
		case 4:
			visualizarItemCarrinho();
			break;
		case 5:
			fecharPedido();
			break;
		case 6:
			printf("Volte sempre!\n");
			Sleep(2);
			exit(0);
		default:
			printf("Opcao invalida.\n");
			Sleep(2);
			menu();
			break;
	}
}

void cadastrarProduto(){
	printf("Cadastro de Produto\n");
	printf("====================\n");

	printf("Informe o nome do produto: \n");
	fgets(produtos[contador_produto].nome, 30, stdin);

	printf("Informe o preco do produto: \n");
	scanf("%f", &produtos[contador_produto].preco);


	printf("O produto %s foi cadastro com sucesso.\n", strtok(produtos[contador_produto].nome, "\n"));

	produtos[contador_produto].codigo = (contador_produto + 1); //criando o codigo do produto
	contador_produto++;

	Sleep(2);
	menu();
}

void listarProduto(){ //verificando se tem produto
	if(contador_produto > 0){
		printf("Lista de produtos.\n");
		printf("-------------------\n");
		for(int i = 0; i < contador_produto; i++){
			infoProduto(produtos[i]);
			printf("-------------------\n");
			Sleep(1);
		}
		Sleep(2);
		menu();
	}else{
		printf("Nao temos ainda produtos cadastrados.\n");
		Sleep(2);
		menu();
	}
}

void comprarPorduto(){//se tiver ja tiver produto cadastrado
	if(contador_produto > 0){
		printf("Informe o codigo do produto que deseja adicionar ao carrinho.\n");

		printf("======== Produtos Disponiveis ========\n");
		for(int i = 0; i < contador_produto; i++){
			infoProduto(produtos[i]);
			printf("-----------------------------");
			Sleep(1);
	}
	int codigo;
	scanf("%d", &codigo);
	getchar();

	int tem_mercado = 0;
	for(int i = 0; i < contador_produto; i++){//vai verificar se tem produto atraves do codigo
		if(produtos[i].codigo == codigo){
			tem_mercado = 1; //ja tem e so vai aumentar a quantidade

			if(contador_carrinho > 0){ //se tiver produto
				int *retorno = temNoCarrinho(codigo);

				if(retorno[0] == 1){ //aumentando a quantidade
					carrinho[retorno[1]].quantidade++;
					printf("Aumentei a quantidade do produto %s ja existente no carrinho.\n",
							strtok(carrinho[retorno[1]].produto.nome, "\n"));
					Sleep(2);
					menu();

				}else{
						Produto p = pegarProdutoPorCodigo(codigo);//adicionando o produto que nao tinha na carrinho
						carrinho[contador_carrinho].produto = p;
						carrinho[contador_carrinho].quantidade = 1;
						contador_carrinho++;
						printf("O produto %s foi adicionado ao carrinho.\n", strtok(p.nome, "\n"));
						Sleep(2);
						menu();
				}
			}else{//caso nao tenha nenhum produto no carrinho
				Produto p = pegarProdutoPorCodigo(codigo);
				carrinho[contador_carrinho].produto = p;
				carrinho[contador_carrinho].quantidade = 1;
				contador_carrinho++;
				printf("O produto %s foi adicionado ao carrinho.\n", strtok(p.nome, "\n"));
				Sleep(2);
				menu();
			}
		}
	}
		if (tem_mercado < 1) {
			printf("Nao e encontrado o produto com codigo %d.\n", codigo);
			Sleep(2);
			menu();
		}

}else{
	printf("Ainda nao existem produtos para vender.\n");
	Sleep(2);
	menu();
	}
}

void visualizarItemCarrinho(){ //
	if(contador_carrinho > 0){
		printf("Produtos do Carrinho\n");
		printf("---------------------\n");
		for(int i = 0; i < contador_carrinho; i++){
			infoProduto(carrinho[i].produto);
			printf("Quantidade: %d\n", carrinho[i].quantidade);
			printf("---------------------\n");
			Sleep(1);
		}
		Sleep(2);
		menu();
	}else{
		printf("Nao temos ainda produtos no carrinho.\n");
		Sleep(2);
		menu();
	}
}

Produto pegarProdutoPorCodigo(int codigo){
	Produto p;
	for(int i = 0; i < contador_produto; i++){
		if(produtos[i].codigo == codigo){
			p = produtos[i];
		}
	}
	return p;
}

int * temNoCarrinho(int codigo){
	int static retorno[] = {0, 0};
	for(int i = 0; i < contador_carrinho; i++){
		if(carrinho[i].produto.codigo == codigo){
			retorno[0] = 1;//produto encontrado
			retorno[1] = i;//Armazena o índice do produto no carrinho
		}
	}
	return retorno;
}

void fecharPedido(){
	if(contador_carrinho > 0){//se tiver algo no carrinho >>
		float valorTotal = 0.0;
		printf("Produto do carrinho\n");
		printf("--------------------\n");
		for(int i = 0; i < contador_carrinho; i++){//pega i indice do produto
			Produto p = carrinho[i].produto;
			int quantidade = carrinho[i].quantidade;
			valorTotal = valorTotal +p.preco * quantidade;//faz o calculo para saber o valor da compra
			infoProduto(p);
			printf("Quantidade: %d\n", quantidade);
			printf("---------------\n");
			Sleep(1);
		}
		printf("Sua fatura é %.2f\n", valorTotal);

		contador_carrinho = 0;
		printf("Obrigada! Volte sempre.\n");
		Sleep(5);
		menu();
	}else{
		printf("Você nao tem nenhum produto no carrinho ainda.\n");
		Sleep(3);
		menu();
	}
}



