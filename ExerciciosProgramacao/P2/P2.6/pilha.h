#ifndef PILHA_H
#define PILHA_H

typedef struct nodep {
  char valor;
  struct nodep *deBaixo;
} nodep_t;

typedef struct {
  int num_elementos;
  nodep_t *topo;
} pilha_t;

pilha_t *cria_pilha();
void push(pilha_t *pilha, int elemento);
int pop(pilha_t *pilha);
int pilha_vazia(pilha_t *pilha);
void destroi_pilha(pilha_t *pilha);
void combinacao_pilhas(pilha_t *pilha_A, pilha_t *pilha_B, pilha_t *pilha_AB);
void imprime_pilha(pilha_t *pilha);
void remove_minimo(pilha_t *pilha);
#endif
