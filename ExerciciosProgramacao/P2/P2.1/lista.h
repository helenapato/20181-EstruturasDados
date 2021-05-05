#ifndef LISTA_H
#define LISTA_H

typedef struct node {
  int valor;
  int indice;
  struct node *next;
} node_t;

typedef struct {
  int num_elementos;
  node_t *inicio;
  node_t *fim;
} lista_t;

lista_t *cria_lista();
void insere_valor(lista_t *lista, int elemento);
int busca_valor(lista_t *lista, int elemento);
void destroi_lista(lista_t *lista);
void remove_ultimo(lista_t *lista);

#endif
