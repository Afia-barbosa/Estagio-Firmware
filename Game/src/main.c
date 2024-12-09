#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "calcular.h"

int main(){
	setbuf(stdout, NULL);

	//deve ser chamado apenas 1 vez
	srand(time(NULL));

	jogar();
	return 0;
}
