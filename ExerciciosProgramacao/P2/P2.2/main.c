#include <stdio.h>

#include "lista.h"

int main(void) {
	// Aloca Lista2
	lista_t *lista = cria_lista();
	// LEITURA DA ENTRADA
	int VARIAVEL;
//	int teste[] = {1, 1, 2, 3, 4, 3, 5, 6, 7, 8, 7};
	while(scanf("%d", &VARIAVEL) != EOF)
//	int i;
//	for(i=0;i<11;i++)
	{
		insere_valor(lista, VARIAVEL); // Insere elementos
//		insere_valor(lista, teste[i]);
	}
	remove_duplicados(lista);
	imprime_lista(lista); // Imprime saída 
	destroi_lista(lista);
    return 0;
}
