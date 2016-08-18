#include <stdio.h>
#include "pilha.h"

int main() {
	pilha *p = malloc(1*sizeof(pilha));
	p->tamanho = 0;
	p->head = NULL;
	
	push(1, p);
	puts("Inserido 1");
	push(2, p);
	puts("Inserido 2");
	push(3, p);
	puts("Inserido 3");
	
	puts("Itz working!");
	printf("Bottom: %d\n", bottom(p));
	printf("Top: %d\n", top(p));
	printf("Tamanho: %d\n", p->tamanho);
	return 0;
}
