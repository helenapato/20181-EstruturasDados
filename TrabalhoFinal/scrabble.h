#ifndef SCRABBLE_H
#define SCRABBLE_H
#include "lista.h"
#include "hash.h"

lista_t *cria_saco();
char *troca_pecas(lista_t *saco, char pecas[]);
tabela_hash_t *palavras_validas();
int jogada1(tabela_hash_t *palavras, lista_t *saco, char inseridasn[], char jogadorn[], char tabuleiro[15][15]);
void jogada2(lista_t *saco, char jogadorn[]);
void imprime_tabuleiro(char tabuleiro[15][15]);
int calculo_pontos(char inseridasn[], char jogadorn[]);

#endif
