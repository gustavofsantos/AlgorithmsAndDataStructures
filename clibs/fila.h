typedef struct no {
	int elemento;
	struct no *proximo;
} no;

typedef struct {
	no *primeiro;
	int tamanho;
} fila;

no *novo_no(int elemento);
fila *nova_fila();
void enfileira(fila *pfila, int elemento);
int *desenfileira(fila *pfila);
void imprimir(fila *pfila);
void limpar(fila *pfila);
