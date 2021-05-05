#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "scrabble.h"
#include "hash.h"

int main(void) 
{
	int i; int j; int fim = 0; int jogada; int jogador = 1;
	char insercao[100]; char inseridas1[100]; char inseridas2[100];
	int passar = 0;
	tabela_hash_t *palavras = palavras_validas();
	lista_t *saco = cria_saco();
	char tabuleiro [15][15];
	for(i=0;i<15;i++)
	{
		for(j=0;j<15;j++)
		{
			tabuleiro [i][j] = '@';
		}
	}
	char jogador1[7]; char jogador2[7];
	for(i=0;i<7;i++)
	{
		jogador1[i] = remover_inicio(saco);
		jogador2[i] = remover_inicio(saco);
	}
	while(!fim)
	{
		imprime_tabuleiro(tabuleiro);
		printf("Jogador %d suas pecas sao:\n0 1 2 3 4 5 6\n", jogador);
		for(i=0;i<7;i++)
		{
			if(jogador == 1) printf("%c ", jogador1[i]);
			else printf("%c ", jogador2[i]);
		}
		printf("\nEscolha sua jogada:\n 1.Colocar pecas no tabuleiro\n 2.Trocar pecas\n 3.Passar a vez\n", jogador);
		scanf("%d", &jogada);
		if(jogada == 1)
		{
			passar = 0;
			if(jogador == 1) jogada = jogada1(palavras, saco, inseridas1, jogador1, tabuleiro);
			else jogada = jogada1(palavras, saco, inseridas2, jogador2, tabuleiro);	
		}
		if(jogada == 2)
		{
			passar = 0;
			if(jogador == 1) jogada2(saco, jogador1);
			else jogada2(saco, jogador2);
		}
		if(jogada == 3)
		{
			passar++;
		}
		if(jogador == 1) jogador = 2;
		else jogador = 1;
		if(passar == 4) fim = 1;
		if(jogador == 1) fim = verifica_zerado(jogador1);
		else fim = verifica_zerado(jogador2);
	}
	destroi_lista(saco);
	destroi_tabela(palavras);
	printf("\nJogador 1 seus pontos sao: %d", calculo_pontos(inseridas1, jogador1));
	printf("\nJogador 2 seus pontos sao: %d", calculo_pontos(inseridas2, jogador2));
	return;
}
