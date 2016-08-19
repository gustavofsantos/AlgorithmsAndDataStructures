typedef struct no {
	int elemento;
	struct no *abaixo;
} no;

typedef struct {
	no *topo;
	int tamanho;
} pilha;

no *novo_no(int elemento);
pilha *nova_pilha();
void push(pilha *ppilha, int elemento);
int *pop(pilha *ppilha);
void imprimir(pilha *ppilha);
void limpar(pilha *ppilha);