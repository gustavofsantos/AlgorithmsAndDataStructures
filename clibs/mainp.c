#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(int argc, char **argv) {
	pilha *ppilha1 = nova_pilha();
	push(ppilha1, 3);
	push(ppilha1, 9);
	push(ppilha1, 0);
	push(ppilha1, 2);
	push(ppilha1, 1);

	imprimir(ppilha1);

	int *topo = pop(ppilha1);

	printf("topo: %d\n", *topo);

	free(topo);

	imprimir(ppilha1);
	
	topo = pop(ppilha1);

	printf("topo: %d\n", *topo);

	imprimir(ppilha1);

	pilha *ppilha2 = nova_pilha();
	pilha *ppilha3 = nova_pilha();

	push(ppilha2, 9);
	push(ppilha2, 0);
	push(ppilha2, 2);

	push(ppilha3, 0);
	push(ppilha3, 2);
	push(ppilha3, 1);

	free(topo);
	limpar(ppilha1);
	limpar(ppilha2);
	limpar(ppilha3);

	return 0;
}
