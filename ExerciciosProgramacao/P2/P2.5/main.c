#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void)
{
	pilha_t *pilha_A = cria_pilha();
	pilha_t *pilha_B = cria_pilha();
	pilha_t *pilha_AB = cria_pilha();
	int tamPA; int tamPB;
	int i; int n;
	scanf(" %d %d", &tamPA, &tamPB);
	for(i=0;i<tamPA;i++)
	{
		scanf("%d", &n);
		push(pilha_A, n);
	}
	for(i=0;i<tamPB;i++)
	{
		scanf("%d", &n);
		push(pilha_B, n);
	}
	combinacao_pilhas(pilha_A, pilha_B, pilha_AB);
	imprime_pilha(pilha_AB);
	printf("\n");
	destroi_pilha(pilha_A);
	destroi_pilha(pilha_B);
	destroi_pilha(pilha_AB);
	return 0;
}
