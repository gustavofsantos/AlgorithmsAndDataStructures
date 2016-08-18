/*
 * Author: Gustavo Santos
 * E-mail: gfdsantos@inf.ufpel.edu.br
 */
#include <stdlib.h>

typedef struct no {
	int conteudo;
	struct no *prox;
} no;

typedef struct pilha {
	no *head;
	int tamanho;
} pilha;

void push(int elemento, pilha *p) {
	no *head_temp = p->head;
	
	if (p->tamanho > 0) {
		
		while (head_temp->prox != NULL) {
			head_temp = head_temp->prox;
		}
		
		no *novo_no = malloc(1*sizeof(no));
		novo_no->conteudo = elemento;
		novo_no->prox = NULL;
		head_temp->prox = novo_no;
		p->tamanho++;
	}
	else {
		no *novo_no = malloc(1*sizeof(no));
		novo_no->conteudo = elemento;
		novo_no->prox = NULL;
		p->head = novo_no;
		p->tamanho = 1;
	}
}

int bottom(pilha *p) {
	if (p->tamanho > 0) {
		int topo = p->head->conteudo;
		return topo;
	}
	else {
		return 0;	
	}
}

int top(pilha *p) {
	if (p->tamanho == 0) {
		return 0;	
	}
	else {
		no *head_temp = p->head;
		while (head_temp->prox != NULL) {
			head_temp = head_temp->prox;
		}
		
		int topo = head_temp->conteudo;
		return topo;
	}
}















