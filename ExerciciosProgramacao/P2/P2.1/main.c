#include <stdio.h>

#include "lista.h"

int main(void) {
	// Aloca Lista2
	lista_t *lista = cria_lista();
	// LEITURA DA ENTRADA
	int VARIAVEL;
//	int teste[] = {13, 74, 29, 17, 3, 17};
	while(scanf("%d", &VARIAVEL) != EOF)
//	int i;
//	for(i=0;i<6;i++)
	{
		insere_valor(lista, VARIAVEL); // Insere elementos
//		insere_valor(lista, teste[i]);
//		if(i==5) VARIAVEL=teste[i];
	}
	
	remove_ultimo(lista);
	printf("\n%d\n", busca_valor(lista, VARIAVEL)); // Imprime saída  
	destroi_lista(lista); 
    return 0;
}
