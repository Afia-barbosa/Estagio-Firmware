#include "itens.h"
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

//estrtura da lista de itens 
typedef struct Itens{
	int x, y;
	int vida;
	struct Itens *proximo;
	 
}Itens;

