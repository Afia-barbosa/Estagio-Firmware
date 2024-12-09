#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h> //Sleep(segundos)
#include <time.h>

typedef struct {
	int codigo;
	char nome[50];
	char email[50];
	char cpf[20];
	char dataNascimento[20];
	char dataCadastro[20];
} Cliente;

typedef struct {
	int numero;
	Cliente cliente;
	float saldo;
	float limite;
	float saldoTotal; //saldo + limite
} Conta;

void menu();
void infoCliente(Cliente cliente);
void infoConta(Conta conta);
void criarConta();
void efetuarSaque();
void efetuarDeposito();
void efetuarTransferencia();
void listarContas();
float atualizaSaldoTotal(Conta conta);
Conta buscarContaPorNumero(int numero);
void sacar(Conta conta, float valor);
void depositar(Conta conta, float valor);
void transferir(Conta conta_origem, Conta conta_destino, float valor);

static Conta contas[50];
static int contador_contas = 0;
static int contador_clientes = 0;

int main(){

	setbuf(stdout, NULL);

	menu();
	return 0;
}



void menu(){ //menu princial / escolher funcao
	int opcao = 0;
	printf("======================================\n");
	printf("=============== BANCO ================\n");
	printf("=============== XBank ================\n");
	printf("======================================\n");

	printf("Selecione uma opcao no menu:\n");
	printf("1 - Criar conta\n");
	printf("2 - Efetuar saque\n");
	printf("3 - Efetuar deposito\n");
	printf("4 - Efetuar transferencia\n");
	printf("5 - Listar contas\n");
	printf("6 - Sair do sistema\n");

	scanf("%d", &opcao);
	getchar();

	switch(opcao){
		case 1:
			criarConta();
			break;
		case 2:
			efetuarSaque();
			break;
		case 3:
			efetuarDeposito();
			break;
		case 4:
			efetuarTransferencia();
			break;
		case 5:
			listarContas();
			break;
		case 6:
			printf("Até a próxima!\n");
			Sleep(2); //Sleep(2)
			exit(0);
		default:
			printf("Opçao invalida.\n");
			Sleep(2);
			menu();
			break;
	}
}

void infoCliente(Cliente cliente){//out
	printf("Codigo: %d \nNome: %s \nData de Nascimento: %s \nCadastro: %s\n",
			cliente.codigo, strtok(cliente.nome, "\n"), strtok(cliente.dataNascimento, "\n"),
			strtok(cliente.dataCadastro, "\n"));
}

void infoConta(Conta conta){//out
	printf("Numero da conta: %d \nCliente: %s \nData Nascimento: %s \nData Cadastro: %s \nSaldo: %.2f \nlimite disponivel: %.2f\n",
			conta.numero, strtok(conta.cliente.nome, "\n"), strtok(conta.cliente.dataNascimento, "\n"),
			strtok(conta.cliente.dataCadastro, "\n"), conta.saldo, conta.limite);
}

void criarConta(){
	Cliente cliente;

	//Data de cadastro
	char dia[3];
	char mes[3];
	char ano[5];
	char data_cadastro[20];
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	//dia
	if(tm.tm_mday < 10){
		sprintf(dia, "0%d", tm.tm_mday);//formatando a data 08/10/2020
	}else{
		sprintf(dia, "%d", tm.tm_mday);
	}

	//mes
	if((tm.tm_mon + 1) < 10){ // 01/08/2020
		sprintf(mes, "0%d", tm.tm_mon + 1);
	}else{
		sprintf(mes, "%d", tm.tm_mon + 1);
	}

	//ano
	sprintf(ano, "%d", tm.tm_year + 1900);

	strcpy(data_cadastro, "");
	strcat(data_cadastro, dia); //22
	strcat(data_cadastro, "/"); //22/
	strcat(data_cadastro, mes); //22/08
	strcat(data_cadastro, "/"); //22/08/
	strcat(data_cadastro, ano); //22/08/2020
	strcat(data_cadastro, "\0");
	strcpy(cliente.dataCadastro, data_cadastro);

	//Criando o cliente
	printf("Informe os dados do cliente:\n");
	cliente.codigo = contador_clientes + 1;

	printf("Nome do cliente: \n");
	fgets(cliente.nome, 50, stdin);

	printf("E-mail do cliente: \n");
	fgets(cliente.email, 50, stdin);

	printf("CPF do cliente: \n");
	fgets(cliente.cpf, 20, stdin);

	printf("Data de nascimento do cliente: \n");
	fgets(cliente.dataNascimento, 20, stdin);

	contador_clientes++;

	//Criar a conta
	contas[contador_contas].numero = contador_contas + 1;
	contas[contador_contas].cliente = cliente;
	contas[contador_contas].saldo = 0.0;
	contas[contador_contas].limite = 500.0;
	contas[contador_contas].saldoTotal = contas[contador_contas].limite + contas[contador_contas].saldo;




	printf("Conta criada com sucesso!\n");
	printf("\n");
	printf("Dados da conta criada: \n");
	printf("\n");
	infoConta(contas[contador_contas]);
	contador_contas++;

	Sleep(4);
	menu();
}

float atualizaSaldoTotal(Conta conta){ //retornar soma de saldo mais o limite da conta, chamar a funcao toda vez que alterar saldo
	return conta.saldo + conta.limite;
}


Conta buscarContaPorNumero(int numero){
	Conta c;
	if(contador_contas > 0){
		for(int i = 0; i < contador_contas; i++){
			if(contas[i].numero == numero){//caso o numero do paramentro for igual ao numero no indice conta
				c = contas[i];
			}
		}
	}
	return c;//retornando conta //funcao feita produto
}

void sacar(Conta conta, float valor){
	if(valor > 0 && conta.saldoTotal >= valor){//caso tiver valor na conta
		for(int i = 0; i < contador_contas; i++){//analisnado as contas
			if(contas[i].numero == conta.numero){//numero de conta
				if(contas[i].saldo >= valor){//caso tenha o valor na conta
					contas[i].saldo = contas[i].saldo - valor;//tirando o valor da conta no array de Contas
					contas[i].saldoTotal = atualizaSaldoTotal(contas[i]);//toal limite atualizado
					printf("Saque efetuado com sucesso!\n");
				}else{
					float restante = contas[i].saldo - valor;//caso nao tenha saldo na conta, iremos usar o limite
					contas[i].limite = contas[i].limite + restante;
					contas[i].saldo = 0.0;
					contas[i].saldoTotal = atualizaSaldoTotal(contas[i]);
					printf("Saque efetuardo com sucesso!\n");
				}
			}
		}
	}else{
		printf("Saque nao realizado. Tente novamente.\n");
		menu();
	}
}

void depositar(Conta conta, float valor){//validacao de conta para depositar

	if(valor > 0){
		for(int i = 0; i < contador_contas; i++){
			if(contas[i].numero == conta.numero){

				printf("Deposito efetuado com sucesso!\n");
				if (contas[i].saldo < 0) { // Caso o saldo esteja negativo
					float faltaParaCobrir = -contas[i].saldo;//convertendo o valor negativo

					if (valor >= faltaParaCobrir) { // Depósito cobre o negativo
						contas[i].saldo = valor - faltaParaCobrir; // Saldo após cobrir a dívida
						contas[i].limite = contas[i].limite + faltaParaCobrir;// Restaura o limite
					} else { // Depósito não cobre todo o valor negativo
						contas[i].saldo = contas[i].saldo + valor; // Apenas reduz o negativo
						contas[i].limite = contas[i].limite + valor; // Ajusta o limite
					}
				} else { // Saldo positivo
					contas[i].saldo = contas[i].saldo + valor; // Adiciona ao saldo diretamente
				}

				//soamando saldo + limite atual :)
				contas[i].saldoTotal = atualizaSaldoTotal(contas[i]);

				// Mostra os novos valores
				printf("Saldo atual: %.2f\n", contas[i].saldo);
				printf("Limite atual: %.2f\n", contas[i].limite);

			}
		}
	}else{
		printf("Erro ao efetuar deposito. Tente novamente.\n");
		menu();
	}

}

void transferir(Conta conta_origem, Conta conta_destino, float valor){
	if(valor > 0 && conta_origem.saldoTotal >= valor){//caso tiver money
		for(int contaOrigem = 0; contaOrigem < contador_contas; contaOrigem++){
			if(contas[contaOrigem].numero == conta_origem.numero){//se a conta de quem esta transferindo o money for igual a alguma conta
				for(int contaDestino = 0; contaDestino < contador_contas; contaDestino++){
					if(contas[contaDestino].numero == conta_destino.numero){//se a conta de quem esta recebendo o money for igual a alguma conta
						if(contas[contaOrigem].saldo >= valor){


							contas[contaOrigem].saldo = contas[contaOrigem].saldo - valor;//tirando o valor da conta que esta transferindo
							contas[contaDestino].saldo = contas[contaDestino].saldo + valor;
							contas[contaOrigem].saldoTotal = atualizaSaldoTotal(contas[contaOrigem]);//saldo atualizado da conta origem
							contas[contaDestino].saldoTotal = atualizaSaldoTotal(contas[contaDestino]);
							printf("Transferencia realizada com sucesso!\n");

						}else{
							float restante = contas[contaOrigem].saldo - valor;
							contas[contaOrigem].limite = contas[contaOrigem].limite + restante;
							contas[contaDestino].saldo = contas[contaDestino].saldo + valor;

							contas[contaOrigem].saldo = contas[contaOrigem].saldo - valor;//atualizando o valor que restou na conta
							contas[contaOrigem].saldoTotal = atualizaSaldoTotal(contas[contaOrigem]); //limite + saldo
							contas[contaDestino].saldoTotal = atualizaSaldoTotal(contas[contaDestino]);


							printf("Transferencia realizada com sucesso!\n");
							printf("Atenção: Você usou do seu limite.\n");
							printf("limite atual: %.2f\n", contas[contaOrigem].limite);
							printf("saldo atual: %.2f\n", contas[contaOrigem].saldo);

						}
					}
				}
			}
		}
	}else{
		printf("Transferencia nao realizada. Tente novamente.\n");
		menu();
	}
}

void efetuarSaque(){
	if(contador_contas > 0){//validacao
		int numero;
		printf("Informe o numero da conta: \n");
		scanf("%d", &numero);

		Conta conta = buscarContaPorNumero(numero);

		if(conta.numero == numero){
			float valor;
			printf("Informe o valor do saque: \n");//so vai pegar os dados
			scanf("%f", &valor);

			sacar(conta, valor);//chamando a funcao parar realizar o saque
		}else{
			printf("Nao foi encontrada uma conta com o numero %d\n", numero);
		}


	}else{
		printf("Ainda nao existem contas para saque.\n");
	}
	Sleep(2);
	menu();
}

void efetuarDeposito(){//mesma logica da funcao de efetuar saque
	if(contador_contas > 0){
			int numero;
			printf("Informe o numero da conta: \n");
			scanf("%d", &numero);

			Conta conta = buscarContaPorNumero(numero);

			if(conta.numero == numero){//vendo se a conta tem o mesmo numero
				float valor;
				printf("Informe o valor do deposito: \n");
				scanf("%f", &valor);

				depositar(conta, valor);//chamando a funcao para realizar o deposito
			}else{
				printf("Nao foi encontrada uma conta com o numero %d\n", numero);
			}


		}else{
			printf("Ainda nao existem contas para deposito.\n");
		}
		Sleep(2);
		menu();
}

void efetuarTransferencia(){
	if(contador_contas > 0){
		int numero_origem, numero_destino;
		printf("Informe o numero da sua conta: \n");
		scanf("%d", &numero_origem);

		Conta conta_o = buscarContaPorNumero(numero_origem);

		if(conta_o.numero ==numero_origem){
			printf("Informe o numero da conta destino: \n");
			scanf("%d", &numero_destino);

			Conta conta_d = buscarContaPorNumero(numero_destino);

			if(conta_d.numero == numero_destino){
				float valor;
				printf("Informe o valor para transferencia: \n");
				scanf("%f", &valor);

				transferir(conta_o, conta_d, valor);//chamando a funcao para transferir
			}else{
				printf("A conta destino com numero %d nao foi encontrada.\n", numero_destino);
			}
		}else{
			printf("A conta origem com numero %d nao foi encontrada.\n",numero_origem);
		}

	}else{
		printf("Ainda nao existem contas para transferencia.\n");
	}
	Sleep(2);
	menu();
}

void listarContas(){
	if(contador_contas > 0){//verifiacando se tem conta
		for(int i = 0; i < contador_contas; i++){
			infoConta(contas[i]);
			printf("\n");
			Sleep(1);
		}
	}else{
		printf("Nao existem contas cadastradas ainda.\n");
	}
	Sleep(2);
	menu();
}



