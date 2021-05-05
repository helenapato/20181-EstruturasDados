#include <stdio.h>
#include "pilha.h"
#include "lista.h"

int main(void) {
	// Aloca Lista2
	lista_t *lista = cria_lista();
	pilha_t *pilha = cria_pilha();
	// LEITURA DA ENTRADA
//	char teste[] = {'a'};
//	char teste[] = {'a', 'r', 'a', 'r', 'a'};
//	char teste[] = {'o', 's', 's', 'o'};
//	char teste[] = {'a', 'b', 'e', 'r', 't', 'a'};
//	char teste[] = {'f', 'e', 'i', 'j', 'a', 'o'};	
	int LETRA;
//	int i;
//	for(i=0;i<6;i++)
	while(scanf(" %c", &LETRA) != EOF)
	{
		insere_valor(lista, LETRA); // Insere elementos
		push(pilha, LETRA);
//		insere_valor(lista, teste[i]);
//		push(pilha, teste[i]);
	}
	printf("\n%d\n", palindromo(lista, pilha)); // Imprime saída 
	destroi_lista(lista);
	destroi_pilha(pilha);
    return 0;
}
