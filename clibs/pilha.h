#include <stdlib.h>
#include <stdio.h>

typedef struct no {
	int elemento;
	struct no *abaixo;
} no;

typedef struct {
	no *topo;
	int tamanho;
} pilha;

#define TRUE  1
#define FALSE 0

/**
 * Função que cria um novo nó e retorna um ponteiro
 * para esta nova região de memória.
 */
no *novo_no(int elemento) {
	no* pno = (no *) malloc(1*sizeof(no));
	pno->elemento = elemento;
	pno->abaixo = (void *)0;
}

/**
 * Função que cria uma nova estrutura de pilha e 
 * retorna um ponteiro para esta região de 
 * memória
 */
pilha *nova_pilha() {
	pilha *ppilha = (pilha *) malloc(1*sizeof(pilha));
	ppilha->tamanho = 0;
	ppilha->topo = (void *)0;
	return ppilha;
}

/**
 * Função que empilha um elemento na pilha
 */
void push(pilha *ppilha, int elemento) {
	if (ppilha->tamanho > 0) {
		no *ptemp_no = novo_no(elemento);
		ptemp_no->abaixo = ppilha->topo;
		ppilha->topo = ptemp_no;
		ppilha->tamanho++;
	}
	else {
		no *ptemp_no = novo_no(elemento);
		ppilha->topo = ptemp_no;
		ppilha->tamanho++;
	}
}

/**
 * Função que remove o elemento no topo da pilha e
 * retorna um ponteiro para o conteúdo armazenado
 * por este elemento
 */
int *pop(pilha *ppilha) {
	if (ppilha->tamanho > 0) {
		int *topo = (int *) malloc(1*sizeof(int));
		*topo = ppilha->topo->elemento;
		no *pdead_no = ppilha->topo;
		ppilha->topo = ppilha->topo->abaixo;
		ppilha->tamanho--;
		free(pdead_no);
		pdead_no = (void *)0;
		return topo;
	}
	else {
		return (void *)0;
	}
}

/**
 * Imprime na saída padrão o conteúdo da pilha
 * de forma elegante
 */
void imprimir(pilha *ppilha) {
	printf("|");
	if (ppilha->tamanho > 0) {
		no *ptemp_no = ppilha->topo;
		while (ptemp_no) {
			printf("%d", ptemp_no->elemento);
			if (ptemp_no->abaixo) printf(", ");
			ptemp_no = ptemp_no->abaixo;
		}
	}
	printf("|\n");
}

/**
 * Libera a memória ocupada pela pilha
 */
void limpar(pilha *ppilha) {
	if (ppilha->tamanho > 0) {
		no *ptemp_no = ppilha->topo;
		no *paux = ppilha->topo;

		while (ptemp_no) {
			paux = ptemp_no;
			ptemp_no = ptemp_no->abaixo;
			free(paux);
			paux = (void *)0;
		}

		free(ptemp_no);
	}
	free(ppilha);
}	

