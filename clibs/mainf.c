#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

int main(int argc, char **argv) {
	fila *pfila = nova_fila();

	enfileira(pfila, 1);
	enfileira(pfila, 2);
	enfileira(pfila, 3);
	enfileira(pfila, 4);

	imprimir(pfila);

	int *pprimeiro = desenfileira(pfila);

	printf("Primeiro: %d\n", *pprimeiro);

	imprimir(pfila);

	free(pprimeiro);

	limpar(pfila);

	return 0;
}