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



void insere_final(lista_t *lista, char letra)
{
	node_t *novo = (node_t *) malloc(sizeof(node_t));
	if(novo == NULL)
	{
		printf("ERRO");
		exit(1);
	}
	novo->peca = letra;
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
		novo->indice = 0;
	}
	else novo->indice = novo->anterior->indice +1;
	lista->num_elementos +=1;
}



void insere_meio(lista_t *lista, char letra, int i)
{
	node_t *novo = (node_t *) malloc(sizeof(node_t));
	if(novo == NULL)
	{
		printf("ERRO");
		exit(1);
	}
	novo->peca = letra;
	novo->indice = i;
	node_t *percorre = lista->inicio;
	while(percorre->proximo != NULL && percorre->indice < i)
	{
		percorre = percorre->proximo;
	}
	if(i < percorre->indice)
	{
		novo->proximo = percorre;
		novo->anterior = percorre->anterior;
		percorre->anterior = novo;
		novo->anterior->proximo = novo;
	}
	else
	{
		novo->anterior = percorre;	
		if(percorre->proximo == NULL)
		{
			novo->proximo = NULL;
			percorre->proximo = novo;
		}
		else
		{
			novo->proximo = percorre->proximo;
			novo->proximo->anterior = novo;
			percorre->proximo = novo;
		}
	}
	lista->num_elementos +=1;
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



void imprime_lista(lista_t *lista)
{
	node_t *visitar = lista->inicio;
	while (visitar != NULL) 
	{
    	printf("%c %d\n", visitar->peca, visitar->indice);
		visitar = visitar->proximo;
	}
	printf("\n");
}


char remover_elemento(lista_t *lista, int i)
{
	node_t *liberar = lista->inicio;
	node_t *percorre = NULL;
	node_t *atualiza_indice;
	int atual = 0;
	char letra;
	while (liberar != NULL) //Caminha até achar o elemento 
	{ 
    	if (atual == i) break;
		liberar = liberar->proximo;
    	atual++;
	}
	if (liberar == NULL) return; //Lista Vazia
	//Atualiza ponteiros
	if (liberar == lista->inicio) lista->inicio = liberar->proximo;
	if (liberar == lista->fim) lista->fim = liberar->anterior;
	if (liberar->anterior != NULL) liberar->anterior->proximo = liberar->proximo;
	//Free!
	percorre = liberar->anterior;
	letra = liberar->peca;
	free(liberar);
	while(percorre->proximo != NULL)
	{
		atualiza_indice = percorre->proximo;
		atualiza_indice->indice -= 1;
		percorre = percorre->proximo;
	}
	return letra;
}



char remover_inicio(lista_t *lista)
{
	node_t *percorre = lista->inicio;
	if(percorre == NULL) return 0;
	char retorno = lista->inicio->peca;
	if(lista->inicio == lista->fim) lista->fim = NULL;
	lista->inicio = lista->inicio->proximo;
	free(percorre);
	return retorno;
}
