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



void insere_valor(lista_t *lista, int elemento)
{
	node_t *novo = (node_t *) malloc(sizeof(node_t));
	if(novo == NULL)
	{
		printf("ERRO");
		exit(1);
	}
	novo->valor = elemento;
	novo->next = NULL;
	if(lista->fim != NULL) lista->fim->next = novo;
	lista->fim = novo;
	if(lista->inicio == NULL) lista->inicio = novo;	
	else lista->num_elementos +=1;
	novo->indice = lista->num_elementos;
}



int busca_valor(lista_t *lista, int elemento)
{
	node_t *visitar = lista->inicio;
	while(visitar != NULL)
	{
		if(visitar->valor == elemento)
		{
			return visitar->indice;
		}
		visitar = visitar->next;
	}
	return -1;
}



void destroi_lista(lista_t *lista)
{
	node_t *visitar = lista->inicio;
	node_t *liberar;
	while(visitar != NULL)
	{
		liberar = visitar;
		visitar = visitar->next;
		free(liberar);
	}
	free(lista);
}


void remove_ultimo(lista_t *lista)
{
	node_t *visitar = lista->inicio;
	while(visitar->next->next != NULL)
	{
		visitar = visitar->next;
	}
	lista->fim = visitar;
	node_t *liberar;
	liberar = visitar->next;
	visitar->next = NULL;
	free(liberar);	
}
