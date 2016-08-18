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

	free(topo);
	limpar(ppilha1);

	return 0;
}
