#include <stdio.h>
#include <stdlib.h>
#include "lista.h"



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
	if(lista->fim != NULL)
	{
		novo->anterior = lista->fim;
		lista->fim->proximo = novo;
	}
	lista->fim = novo;
	if(lista->inicio == NULL)
	{
		lista->inicio = novo;
		novo->anterior = NULL;
	}
	lista->num_elementos +=1;
}



int palindromo(lista_t *lista)
{
	if(lista->num_elementos == 1) return 1;
	node_t *primeiro = lista->inicio;
	node_t *ultimo = lista->fim;
	int i;
	for(i=0; i<((lista->num_elementos)/2);i++)
	{
		if(primeiro->letra != ultimo->letra) return 0;
		primeiro = primeiro->proximo;
		ultimo = ultimo->anterior;
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
