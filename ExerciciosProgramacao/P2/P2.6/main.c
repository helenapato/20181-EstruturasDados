#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void)
{
	pilha_t *pilha = cria_pilha();
//	int teste[] = {4, 7, 34, 15, 3, 6, 8};
//	int i;
//	for(i=0; i<7;i++) push(pilha, teste[i]);
	int VALOR;
	while(scanf("%d", &VALOR) != EOF)
	{
		push(pilha, VALOR);
	}
	remove_minimo(pilha);
	imprime_pilha(pilha);
	destroi_pilha(pilha);
	return 0;
}
