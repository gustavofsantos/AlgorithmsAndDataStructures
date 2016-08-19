#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

/**
 * Função que cria um novo nó e retorna um ponteiro
 * para esta nova região de memória.
 */
no *novo_no(int elemento) {
	no* pno = (no *) malloc(1*sizeof(no));
	pno->elemento = elemento;
	pno->proximo = (void *)0;
}

/**
 * Função que cria uma nova estrutura de fila e 
 * retorna um ponteiro para esta região de 
 * memória
 */
fila *nova_fila() {
	fila *pfila = (fila *) malloc(1*sizeof(fila));
	pfila->tamanho = 0;
	pfila->primeiro = (void *)0;
	return pfila;
}

/**
 * Enfileira um elemento na fila original
 */
void enfileira(fila *pfila, int elemento) {
	if (pfila->tamanho > 0) {
		no *ptemp_no = pfila->primeiro;
		while (ptemp_no->proximo) {
			ptemp_no = ptemp_no->proximo;
		}
		no *pnovo_no = novo_no(elemento);
		ptemp_no->proximo = pnovo_no;
		pfila->tamanho++;
	}
	else {
		no *pnovo_no = novo_no(elemento);
		pfila->primeiro = pnovo_no;
		pfila->tamanho++;
	}
}

/* Retira o elemento da vez da fila e retorna
 * um ponteiro para o valor numérico deste
 * elemento
 */
int *desenfileira(fila *pfila) {
	if (pfila->tamanho > 0) {
		int *pprimeiro = (int *) malloc(1*sizeof(int));
		*pprimeiro = pfila->primeiro->elemento;
		no *pdead_no = pfila->primeiro;
		pfila->primeiro = pfila->primeiro->proximo;
		free(pdead_no);
		pfila->tamanho--;
		return pprimeiro;
	}
	else {
		return (void *)0;
	}
}

/**
 * Imprime de forma elegante o conteúdo
 * da fila
 */
void imprimir(fila *pfila) {
	printf("<");
	if (pfila->tamanho > 0) {
		no *ptemp_no = pfila->primeiro;
		while (ptemp_no) {
			printf("%d", ptemp_no->elemento);
			if (ptemp_no->proximo) printf(", ");
			ptemp_no = ptemp_no->proximo;
		}
	}
	printf("|\n");
}

/**
 * Libera a memória ocupada pela fila
 */
void limpar(fila *pfila) {
	if (pfila->tamanho > 0) {
		no *ptemp_no = pfila->primeiro;
		no *paux = pfila->primeiro;

		while (ptemp_no->proximo) {
			paux = ptemp_no;
			ptemp_no = ptemp_no->proximo;
			free(paux);
			paux = NULL;
		}

		free(ptemp_no);
	}
	free(pfila);
}