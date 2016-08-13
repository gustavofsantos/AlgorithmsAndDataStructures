#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int content;
	struct Node *next;
	struct Node *prev;
} Node;

typedef struct List {
	Node *fst;
	Node *lst;
	int size;
} List;

void insert(int elem, List *list) {
	Node *fst = list->fst;
	Node *temp = fst;
	if (fst == NULL) {
		fst = malloc(sizeof(Node));
		fst->content = elem;
		fst->next = NULL;
		fst->prev = NULL;
	}
	else {
		// traverse the list
		while (temp->next == NULL) {
			temp = temp->next;
		}

		Node *new = malloc(sizeof(Node));
		new->content = elem;
		new->next = NULL;
		new->prev = temp;
		temp->next = new;
		list->fst = fst;
	}
}

void print_list(List *list) {
	printf("[");
	Node *fst = list->fst;
	while (fst->next != NULL) {
		printf("%d,", fst->content);
		fst = fst->next;
	}
	printf("]\n");
}

int main() {
	printf("[!] Implementação de lista.\n");

	List *restrict list = malloc(sizeof(List));

	printf("insere 1\n");
	insert(1, list);
	printf("insere 2\n");
	insert(1, list);

	printf("imprime\n");
	print_list(list);

	printf("limpa\n");
	free(list);

	return 0;
}
