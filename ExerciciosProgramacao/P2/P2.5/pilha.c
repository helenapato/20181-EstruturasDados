#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"



pilha_t *cria_pilha()
{
	pilha_t *pilha = (pilha_t *) malloc(sizeof(pilha_t));
	if (pilha == NULL) 
	{
    		printf("ERRO");
    		exit(1);
	}
	pilha->topo = NULL;
	pilha->num_elementos = 0;
	return pilha;
}



void push(pilha_t *pilha, int elemento)
{
	nodep_t *nova = (nodep_t *) malloc(sizeof(nodep_t));
	nova->valor  = elemento;
	pilha->num_elementos += 1;
	if(pilha->topo == NULL) nova->deBaixo = NULL;
	else nova->deBaixo = pilha->topo;
	pilha->topo = nova;
}



int pop(pilha_t *pilha)
{
	nodep_t *remover = pilha->topo;
	int num = remover->valor;
	pilha->topo = pilha->topo->deBaixo;
	free(remover);
	return num;
}



int pilha_vazia(pilha_t *pilha)
{
	if(pilha->topo == NULL) return 1;
	return 0;
}



void destroi_pilha(pilha_t *pilha)
{
	while(!pilha_vazia(pilha))
	{
		pop(pilha);
	}
	free(pilha);
}



void combinacao_pilhas(pilha_t *pilha_A, pilha_t *pilha_B, pilha_t *pilha_AB)
{
	nodep_t *percorre_A = pilha_A->topo;
	nodep_t *percorre_B = pilha_B->topo;
	while(percorre_A != NULL || percorre_B != NULL)
	{
		if(percorre_A == NULL)
		{
			while(percorre_B != NULL)
			{
				push(pilha_AB, percorre_B->valor);
				percorre_B = percorre_B->deBaixo;
			}
			return;
		}
		if(percorre_B == NULL)
		{
			while(percorre_A != NULL)
			{
				push(pilha_AB, percorre_A->valor);
				percorre_A = percorre_A->deBaixo;
			}
			return;
		}
		if(percorre_A->valor > percorre_B->valor)
		{
			push(pilha_AB, percorre_A->valor);
			percorre_A = percorre_A->deBaixo;
		}
		else
		{
			push(pilha_AB, percorre_B->valor);
			percorre_B = percorre_B->deBaixo;
		}
	}
}



void imprime_pilha(pilha_t *pilha)
{
	nodep_t *visita = pilha->topo;
	while(visita != NULL)
	{
		printf("%d ", visita->valor);
		visita = visita->deBaixo;
	}
}
