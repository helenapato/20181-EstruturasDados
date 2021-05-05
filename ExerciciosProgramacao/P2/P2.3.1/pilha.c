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
