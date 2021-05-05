#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "scrabble.h"
#include "hash.h"

lista_t *cria_saco()
{
	int i; int j=0;
	char ponto1[77]; 
	for(i=0;i<14;i++) ponto1[i] = 'A';
	for(;i<25;i++) ponto1[i] = 'E';
	for(;i<35;i++) ponto1[i] = 'I';
	for(;i<45;i++) ponto1[i] = 'O';
	for(;i<53;i++) ponto1[i] = 'S';
	for(;i<60;i++) ponto1[i] = 'U';
	for(;i<66;i++) ponto1[i] = 'M';
	for(;i<72;i++) ponto1[i] = 'R';
	for(;i<77;i++) ponto1[i] = 'T';
	char ponto2[18];
	for(i=0;i<5;i++) ponto2[i] = 'D';
	for(;i<10;i++) ponto2[i] = 'L';
	for(;i<14;i++) ponto2[i] = 'C';
	for(;i<18;i++) ponto2[i] = 'P';
	char ponto3[] = {'N', 'N', 'N', 'N', 'B', 'B', 'B'};
	char ponto4[] = {'F', 'F', 'G', 'G', 'H', 'H', 'V', 'V'};
	char ponto5[] = {'J', 'J'};
	char ponto6[] = {'Q'};
	char ponto8[] = {'X', 'Z'};
	char ponto0[] = {'_', '_', '_'};
	lista_t *saco  = cria_lista();
	insere_final(saco, ponto1[0]);
	srand(time(NULL));
	int indices[118];
	for(i=0;i<118;i++)
	{
		indices[i] = rand();
	}
	for(i=1;i<77;i++)
	{
		insere_meio(saco, ponto1[i], indices[j]);
		j++;
	}
	for(i=0;i<18;i++)
	{
		insere_meio(saco, ponto2[i], indices[j]);
		j++;
	}
	for(i=0;i<7;i++)
	{
		insere_meio(saco, ponto3[i], indices[j]);
		j++;
	}
	for(i=0;i<8;i++)
	{
		insere_meio(saco, ponto4[i], indices[j]);
		j++;
	}
	for(i=0;i<2;i++)
	{
		insere_meio(saco, ponto5[i], indices[j]);
		j++;
	}
	insere_meio(saco, ponto6[0], indices[j]);
	j++;
	for(i=0;i<2;i++)
	{
		insere_meio(saco, ponto8[i], indices[j]);
		j++;
	}
	for(i=0;i<3;i++)
	{
		insere_meio(saco, ponto0[i], indices[j]);
		j++;
	}
//	imprime_lista(saco);
	return saco;
}



char *troca_pecas(lista_t *saco, char pecas[])
{
	int i;
	int tam = strlen(pecas);
	int indices[tam];
	srand(time(NULL));
	for(i=0;i<tam;i++)
	{
		indices[i] = rand();
	}
	for(i=0;i<tam;i++)
	{
		insere_meio(saco, pecas[i], indices[i]);
	}
	char retorno[tam];
	for(i=0;i<tam;i++)
	{
		retorno[i] = remover_inicio(saco);
	}
	char *r = &retorno[0];
	return r;
}



tabela_hash_t *palavras_validas()
{
	int i=0;
	tabela_hash_t *tabela = cria_tabela(300000);
	FILE *arquivo;
	arquivo = fopen("palavras-port-sem-espaco.txt","r");
	if(arquivo == NULL) printf("\nERRO o arquivo nao pode ser aberto\n");
	char palavra[100];
	char c = fgetc(arquivo);
	while(c != EOF)
	{
		while(c != '\n' && c != EOF)
		{
			palavra[i] = c;
			c = fgetc(arquivo);
			i++;
		}
		palavra[i] = '\0';
		i=0;
		insere_hash(tabela, hash(palavra), palavra);
		c = fgetc(arquivo);
	}
	fclose(arquivo);
	return tabela;
}



int jogada1(tabela_hash_t *palavras, lista_t *saco, char inseridasn[], char jogadorn[], char tabuleiro[15][15])
{
	char insercao[100]; int pecas; int i; int j; 
	int p1; int p2; char c; int d;
	printf("\nDigite a palavra que deseja inserir: ");
	scanf("%s", &insercao);
	while(busca_hash(palavras, hash(insercao), insercao) == NULL)
	{
		printf("Essa palavra nao e valida, deseja tentar outra ou Desistir?\n 1.Tentar outra\n 2.Desistir\n");
		scanf("%d", &d);
		if(d == 1)
		{
			printf("Digite outra palavra: ");
			scanf("%s", &insercao);
		}
		else
		{
			printf("Deseja:\n 2.Trocar pecas\n 3.Passar a vez\n");
			scanf("%d", &d);
			return d;
		}
	}
	strcat(inseridasn, insercao);
	printf("Digite os o numero de pecas que ira usar: ");
	scanf("%d", &pecas);
	printf("Digite os indices das pecas que ira usar e a posicao do tabuleiro que deseja colocar: ");
	for(i=0;i<pecas;i++)
	{
		scanf("%d %d %d", &j, &p1, &p2);
		tabuleiro[p1][p2] = jogadorn[j];				 
		c = remover_inicio(saco);
		if(c != 0)
		{
			jogadorn[j] = c;
		}
		else jogadorn[j] = '@';
	}
	return 1;
}



void jogada2(lista_t *saco, char jogadorn[])
{
	char pecas[7]; char novas[7]; int i; int j = 0;
	printf("\nDigite quais pecas deseja trocar, sem espaco e em letra maiuscula: ");
	scanf("%s", &pecas);
	strcpy(novas, troca_pecas(saco, pecas));
	for(i=0;i<strlen(pecas);i++)
	{
		for(;j<7;j++)
		{
			if(jogadorn[j] == pecas[i])
			{
				jogadorn[j] = novas[i];
				j++;
				break;
			}
		}
	}
	
}



void imprime_tabuleiro(char tabuleiro[15][15])
{
	int i; int j;
	printf("   0 1 2 3 4 5 6 7 8 9 10 11 12 13 14\n");
	for(i=0;i<15;i++)
	{		
		if(i<10) printf(" %d ", i);
		else printf("%d ", i);
		for(j=0;j<15;j++)
		{
			if(j>9) printf(" %c ", tabuleiro [i][j]);
			else printf("%c ", tabuleiro [i][j]);
		}
		printf("\n");
	}
}



int calculo_pontos(char inseridasn[], char jogadorn[])
{
	int pontos = 0; int n = strlen(inseridasn); int i;
	int pena = 0;
	for(i=0;i<n;i++)
	{
		if(inseridasn[i] == 'a' || inseridasn[i] == 'e' || inseridasn[i] == 'i' || inseridasn[i] == 'o' || inseridasn[i] == 's' || inseridasn[i] == 'u' || inseridasn[i] == 'm' || inseridasn[i] == 'r' || inseridasn[i] == 't')
		{
			pontos++;
		}
		if(inseridasn[i] == 'd' || inseridasn[i] == 'l' || inseridasn[i] == 'c' || inseridasn[i] == 'p')
		{
			pontos+=2;
		}
		if(inseridasn[i] == 'n' || inseridasn[i] == 'b')
		{
			pontos+=3;
		}
		if(inseridasn[i] == 'f' || inseridasn[i] == 'g' || inseridasn[i] == 'h' || inseridasn[i] == 'v')
		{
			pontos+=4;
		}
		if(inseridasn[i] == 'j')
		{
			pontos+=5;
		}
		if(inseridasn[i] == 'q')
		{
			pontos+=6;
		}
		if(inseridasn[i] == 'x' || inseridasn[i] == 'z')
		{
			pontos+=8;
		}
	}
	for(i=0;i<7;i++)
	{
		if(jogadorn[i] != '@')
		{
			if(jogadorn[i] == 'a' || jogadorn[i] == 'e' || jogadorn[i] == 'i' || jogadorn[i] == 'o' || jogadorn[i] == 's' || jogadorn[i] == 'u' || jogadorn[i] == 'm' || jogadorn[i] == 'r' || jogadorn[i] == 't')
			{
				pena++;
			}
			if(jogadorn[i] == 'd' || jogadorn[i] == 'l' || jogadorn[i] == 'c' || jogadorn[i] == 'p')
			{
				pena+=2;
			}
			if(jogadorn[i] == 'n' || jogadorn[i] == 'b')
			{
				pena+=3;
			}
			if(jogadorn[i] == 'f' || jogadorn[i] == 'g' || jogadorn[i] == 'h' || jogadorn[i] == 'v')
			{
				pena+=4;
			}
			if(jogadorn[i] == 'j')
			{
				pena+=5;
			}
			if(jogadorn[i] == 'q')
			{
				pena+=6;
			}
			if(jogadorn[i] == 'x' || jogadorn[i] == 'z')
			{
				pena+=8;
			}
		}
	}
	pontos = pontos - pena;
	return pontos;
}


int verifica_zerado(char jogadorn[])
{
	int zero = 0; int i;
	for(i=0;i<7;i++)
	{
		if(jogadorn[i] == '@')
		{
			zero++;
		}
	}
	if(zero == 7) return 1;
	else return 0;
}
