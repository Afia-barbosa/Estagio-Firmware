#include "inimigos.h"
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

//adicionar inimigo
//mover inimigo


typedef struct Inimigos{//declar isso no arquivo.h
	
	int x, y;
	int vida;
	struct Inimigos *prox;
	
}Inimigos;




