#include "obstaculos.h"
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

//estrtura da lista de obstaculos 
typedef struct Obstaculos{
	int x, y;
	int vida;
	struct Obstaculos *proximo;
	 
}Obstaculos;

