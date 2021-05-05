#ifndef LISTA_H
#define LISTA_H

typedef struct node {
  char peca;
  int indice;
  struct node *proximo;
  struct node *anterior;
} node_t;

typedef struct {
  int num_elementos;
  node_t *inicio;
  node_t *fim;
} lista_t;

lista_t *cria_lista();
void insere_final(lista_t *lista, char letra);
void insere_meio(lista_t *lista, char letra, int i);
void destroi_lista(lista_t *lista);
void imprime_lista(lista_t *lista);
char remover_elemento(lista_t *lista, int i);
char remover_inicio(lista_t *lista);

#endif
