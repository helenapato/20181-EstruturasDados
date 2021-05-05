#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pilha.h"



lista_t *cria_lista()
{
	lista_t *lista = (lista_t *) malloc(sizeof(lista_t));
	if (lista == NULL) 
	{
    		printf("ERRO");
    		exit(1);
	}
	lista->inicio = NULL;
	lista->fim = NULL;
	lista->num_elementos = 0;
	return lista;
}



void insere_valor(lista_t *lista, char info)
{
	node_t *novo = (node_t *) malloc(sizeof(node_t));
	if(novo == NULL)
	{
		printf("ERRO");
		exit(1);
	}
	novo->letra = info;
	novo->proximo = NULL;
	if(lista->fim != NULL) lista->fim->proximo = novo;
	lista->fim = novo;
	if(lista->inicio == NULL) lista->inicio = novo;
	lista->num_elementos +=1;
}



int palindromo(lista_t *lista, pilha_t *pilha)
{
	node_t *visita_lista = lista->inicio;
	nodep_t *visita_pilha = pilha->topo;
	while(visita_lista != NULL)
	{
		if(visita_lista->letra != visita_pilha->valor) return 0;
		visita_lista = visita_lista->proximo;
		visita_pilha = visita_pilha->deBaixo;
	}
	return 1;	
}


void destroi_lista(lista_t *lista)
{
	node_t *visitar = lista->inicio;
	node_t *liberar;
	while(visitar != NULL)
	{
		liberar = visitar;
		visitar = visitar->proximo;
		free(liberar);
	}
	free(lista);
}
