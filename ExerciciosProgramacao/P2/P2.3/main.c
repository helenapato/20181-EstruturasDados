#include <stdio.h>

#include "lista.h"

int main(void) {
	// Aloca Lista2
	lista_t *lista = cria_lista();
	// LEITURA DA ENTRADA
//	char teste[] = {'a'};	
	int LETRA;
//	int i;
//	for(i=0;i<1;i++)
	while(scanf(" %c", &LETRA) != EOF)
	{
		insere_valor(lista, LETRA); // Insere elementos
//		insere_valor(lista, teste[i]);
	}
	printf("\n%d\n", palindromo(lista)); // Imprime saída 
	destroi_lista(lista);
    return 0;
}
