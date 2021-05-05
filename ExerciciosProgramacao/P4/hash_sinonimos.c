#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "hash_sinonimos.h"

tabela_hash_t *cria_tabela(int tamanho) 
{
	// aloca memoria para tabela
	tabela_hash_t *tab = (tabela_hash_t*) malloc(sizeof(tabela_hash_t));
	// aloca memoria para as entradas
	tab->entradas = (entrada_hash_t**) malloc(tamanho * sizeof(entrada_hash_t*)); 
	tab->tamanho = tamanho;
	int i;
	for (i=0;i<tamanho;i++)
	{
		tab->entradas[i] = NULL; // preenche todas as entradas com NULL
	}   
	return tab;
}

int hash(char pa[]) // funcao de calculo da chave hash
{
	int i; // ela faz o valor de cada letra da palavra na tabela ASCII vezes
	int resultado = 0; // a sua posicao na palavra, comecando do 1, e depois
	for (i = 1; i <= strlen(pa); i++)                           // soma tudo
	{
		resultado += pa[i] * i;
	}
	return resultado;
}

void insere_hash(tabela_hash_t *tab, int chave_hash, char p[], char s[]) 
{
	// aloca memoria para a entrada
	entrada_hash_t *entrada = (entrada_hash_t*) malloc(sizeof(entrada_hash_t));
	// atribui os valores para cada campo da estrutura
	entrada->chave_hash = chave_hash; 
	strcpy(entrada->palavra, p);
	strcpy(entrada->sinonimos, s);
	entrada->proximo = NULL;
	// calcula a posicao na tabela que a estrutura sera inserida
	int posicao = chave_hash % tab->tamanho; 
	// percorre vai procurar um lugar vazio para inserir
	entrada_hash_t *percorre = tab->entradas[posicao]; 
	if (percorre == NULL) // se a posicao inicial estiver vazia
	{
		tab->entradas[posicao] = entrada; // insere
	} 
	else // senao, ele vai caminhar ate achar uma posicao vazia para inserir
	{
		while (percorre->proximo != NULL) // usando o ponteiro para proximo da estrutura
		{
			percorre = percorre->proximo;
		}
		percorre->proximo = entrada; // insere
	}
	return;
}

char *busca_hash(tabela_hash_t *tab, int chave_hash, char pala[]) 
{
	// calcula a posicao que a palavra buscada deveria estar na tabela
	int posicao = chave_hash % tab->tamanho; 
	void *retorno = NULL;
	entrada_hash_t *procura = tab->entradas[posicao]; // procura vai procurar a palavra
	while(procura != NULL && strcmp(procura->palavra, pala) != 0)      // se existe
	{ // algo na ista que nao eh a palavra ele percorre a lista ate achar a palavra 
		procura = procura->proximo;                            // ou a lista acabar
	}
	if(procura != NULL) // se ele achou alguma coisa
	{
		retorno = procura->sinonimos; // ele retorna o que achou
	}
	return retorno; // senao ele returna NULL (visto que retorno eh inicialmente NULL)
}

void teste (tabela_hash_t *tab) // imprime os valores inseridos na tabela
{
	int i;
	for(i=0; i<100000;i++)
	{
		entrada_hash_t *percorre = tab->entradas[i];
		if(percorre != NULL) // se ha algo na posicao i
		{
			printf("%s\n", percorre->palavra); // imprime os valores da entrada
			printf("%d\n", percorre->chave_hash);
			printf("%s\n", percorre->sinonimos);
		}	
	}
	return;
}

void destroi_tabela (tabela_hash_t *tab)
{
	int i;
	for(i=0; i<100000;i++)
	{
		entrada_hash_t *percorre = tab->entradas[i];
		entrada_hash_t *libera;
		if(percorre != NULL) // se ha alguma entrada na posicao i
		{
			while(percorre->proximo != NULL) // e ha uma lista encadeada
			{
				libera = percorre; // libera recebe o ponteiro atual
				percorre = percorre->proximo; // o ponteiro atual recebe o proximo
				free(libera); // libera o anterior
			} // ate que a lista acabe
			free(percorre); // libera o atual
		}
		free(tab); // libera a tabela
	}
	return;
}
