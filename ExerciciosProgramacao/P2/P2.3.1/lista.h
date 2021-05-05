#ifndef LISTA_H
#define LISTA_H
#include "pilha.h"

typedef struct node {
  char letra;
  struct node *proximo;
} node_t;

typedef struct {
  int num_elementos;
  node_t *inicio;
  node_t *fim;
} lista_t;

lista_t *cria_lista();
void insere_valor(lista_t *lista, char info);
int palindromo(lista_t *lista, pilha_t *pilha);
void destroi_lista(lista_t *lista);

#endif
