/**
 * Autor: Gustavo Fernandes dos Santos
 * Email: gfdsantos@inf.ufpel.edu.br
 *
 * ===================================
 *
 * Implementação da estrutura: Lista
 *
 * ===================================
 */

/* Área de inclusão de bibliotecas */
#include <stdlib.h>
#include <stdio.h>

/* Área de definição de tipos */
/* no: estrutura de nó para lista ligada*/
typedef struct no {
	int elemento;
	struct no *proximo;
} no;

/* lista: estrutura de lista ligada */
typedef struct {
	no *pno;
	int tamanho;
} lista;

/* Área de implementação de funções que manipulam
 * listas
 */

/**
 * Aloca memória para uma nova lista e retorna um
 * ponteiro para esta região de memória
 */
lista* nova_lista() {
	lista *plista = (lista *) malloc(1*sizeof(lista));
	plista->tamanho = 0;
	plista->pno = (void *)0;

	return plista;
}

/**
 * Aloca memória para um novo nó e o configura de
 * acordo com o conteúdo a ser armazenado e retorna
 * um ponteiro para este novo nó.
 */
no* novo_no(int elemento) {
	no *pno = (no *) malloc(1*sizeof(no));
	pno->proximo = (void *)0;
	pno->elemento = elemento;

	return pno;
}

/**
 * Insere um elemento em uma lista
 */
void insere(lista *plista, int elemento) {
	if (plista->tamanho == 0) {
		no *pno = novo_no(elemento);
		plista->pno = pno;
	}
	else {
		no *ptemp_no = plista->pno;

		while(ptemp_no->proximo) {
			ptemp_no = ptemp_no->proximo;
		} /* anda pela lista até o ultimo elemento */

		no *pnovo_no = novo_no(elemento);
		ptemp_no->proximo = pnovo_no;
	}
	plista->tamanho++;
}

/**
 * Remove um elemento de uma lista para dada posicao
 */
void remover(lista *plista, int posicao) {
	if (plista->tamanho > 0 && plista->tamanho > posicao && posicao >= 0) {
		no *ptemp_no = plista->pno;
		int cont = 0;

		while (cont != posicao - 1) {
			ptemp_no = ptemp_no->proximo;
			cont++;
		}
		
		no *pdead_no = ptemp_no->proximo;

		ptemp_no->proximo = ptemp_no->proximo->proximo;

		free(pdead_no);
		plista->tamanho--;
	}
	else {
		printf("[-] Erro: verifique a posição a ser removida.\n");
	}
}

/**
 * Retorna um ponteiro para o valor numérico do primeiro
 * elemento de uma lista
 */
int *fst(lista *plista) {
	if (plista->tamanho == 0) {
		return (void *)0;
	} /* se a lista for vazia, retornar um ponteiro nulo */
	else {
		int *pprimeiro = (int *) malloc(1*sizeof(int));
		*pprimeiro = plista->pno->elemento;
		return pprimeiro;
	} /* senão retorna o conteúdo do primeiro nó */
}

/**
 * Remove o primeiro elemento de uma dada lista e retorna
 * um ponteiro para o seu valor numérico
 */
int *drop(lista *plista) {
	if (plista->tamanho == 0) {
		return (void *)0;
	}
	else {
		no *primeiro_no = plista->pno;
		int *pprimeiro = (int *) malloc(1*sizeof(int));
		*pprimeiro = primeiro_no->elemento;
		plista->pno = plista->pno->proximo;
		free(primeiro_no);
		plista->tamanho--;
		return pprimeiro;
	}
}

/**
 * Aplica uma função sob todos elementos de uma lista
 * e retorna uma nova lista
 */
lista *map(lista *plista, int (*f)(int)) {
	if (plista->tamanho == 0) {
		return plista;
	} /* se a lista for vazia, retorna o ponteiro para a lista original */
	else {
		lista *pnova_lista = nova_lista();
		no *ptemp_no = plista->pno;

		while (ptemp_no) {
			insere(pnova_lista, f(ptemp_no->elemento));
			ptemp_no = ptemp_no->proximo;
		}

		return pnova_lista;
	}
}

/**
 * Filtra uma lista utilizando uma função de comparação
 * que retorna 1 para verdadeiro ou 0 para falso e
 * retorna uma nova lista
 */
lista *filter(lista *plista, int (*p)(int)) {
	if (plista->tamanho > 0) {
		lista *pnova_lista = nova_lista();
		pnova_lista->pno = plista->pno;
		no *ptemp_no = pnova_lista->pno;
		while (ptemp_no) {
			if (p(ptemp_no->elemento) == 1) insere(pnova_lista, ptemp_no->elemento);
			ptemp_no = ptemp_no->proximo;
		}

		return pnova_lista;
	} /* só executa se a lista não for vazia */
	else {
		return plista;
	}
}

/**
 * Imprime uma lista de forma elegante
 */
void imprimir(lista *plista) {
	printf("[");
	if (plista->tamanho > 0) {
		no *ptemp_no = plista->pno;
		while (ptemp_no) {
			printf("%d", ptemp_no->elemento);
			if (ptemp_no->proximo) printf(", ");
			ptemp_no = ptemp_no->proximo;
		}
	}
	printf("]\n");
}

/**
 * Libera a memoria utilizada por uma lista
 */
void limpar(lista *plista) {
	if (plista->tamanho > 0) {
		no *ptemp_no = plista->pno;
		no *paux = plista->pno;

		while (ptemp_no) {
			paux = ptemp_no;
			ptemp_no = ptemp_no->proximo;
			free(paux);
			paux = (void *)0;
		}

		free(ptemp_no);
	}
	free(plista);
}

/**
 * Retorna o tamanho de uma lista
 */
int tamanho(lista *plista) {
	return plista->tamanho;
}

/**
 * Recebe duas listas como entrada e retorna o anexo 
 * da segunda lista à primeira, como uma nova lista.
 */
lista *anexar(lista *plista, lista *plista_anexo) {
	if (plista->tamanho == 0) {
		return plista_anexo;
	}
	else if (plista_anexo->tamanho == 0) {
		return plista;
	}
	else {
		lista *pnova_lista = nova_lista();
		no *ptemp_no = plista->pno;
		while (ptemp_no) {
			insere(pnova_lista, ptemp_no->elemento);
			ptemp_no = ptemp_no->proximo;
		}
		
		ptemp_no = plista_anexo->pno;
		while (ptemp_no) {
			insere(pnova_lista, ptemp_no->elemento);
			ptemp_no = ptemp_no->proximo;
		}
		return pnova_lista;
	}
}


