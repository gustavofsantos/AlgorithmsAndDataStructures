#include "listaligada.h"

int mais_um(int x) {
	return x + 1;
}

int eh_par(int x) {
	if (x%2 == 0) return 1;
	else return 0;
}

int main(int argc, char **argv) {
	lista *plista = nova_lista();

	insere(plista, 1);
	insere(plista, 2);
	insere(plista, 3);
	insere(plista, 4);

	printf("imprimindo plista\n");
	imprimir(plista);

	lista *plista2 = map(plista, &mais_um);

	imprimir(plista2);

	printf("printando o filter...\n");

	lista *plista3 = filter(plista2, &eh_par);

	imprimir(plista3);

	lista *plista4 = anexar(plista3, plista2);

	imprimir(plista4);

	remover(plista4, 5);

	imprimir(plista4);

	limpar(plista);
	limpar(plista2);
	limpar(plista3);
	limpar(plista4);
	return 0;
}
