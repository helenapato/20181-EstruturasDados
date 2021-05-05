#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_sinonimos.h"

int main(void) 
{
	int i1 = 0; int i2 = 0; int i = 0;
	FILE *arquivo;
	arquivo = fopen("Palavras.dat","r"); // abre o arquivo a ser lido
	if(arquivo == NULL) printf("\nERRO o arquivo nao pode ser aberto\n");
	else printf("\nO arquivo foi aberto com sucesso\n");
	tabela_hash_t *tabela = cria_tabela(100000); // cria a tabela hash
	while(fgetc(arquivo) != '{') // inicia a leitura da palavra apos o {
	{
		i1++;		
	}
	char palavra[100]; // arranjo char para a palavra que vai ser lida
	char c = fgetc(arquivo);
	palavra[i] = c;
	while(c != '|') // le a palavra ate o |
	{
		i++;
		c = fgetc(arquivo);
		if(c != '|' && c!= '/' && c != '&') palavra[i] = c; // so aceita letras na palavra
	}
	palavra[i] = '\0'; // fim da palavra
	while(c != EOF)
	{
		while(fgetc(arquivo) != ')') // comeca a ler os sinonimos depois de (sinonimos)
		{
			i2++;
		}
		char sinonimos[10000]; // arranjo char para os sininomos que vao ser lidos
		fgets(sinonimos, 10000, arquivo); // pega o string dos sinonimos no arquivo
		c = fgetc(arquivo);
		while(c == '(') // se houver mais de um (sinonimos) para aquela palavra
		{
			while(fgetc(arquivo) != ')')
			{
				i2++;
			}
			char sin2[10000];
			fgets(sin2, 10000, arquivo); // pega o segundo set de sinonimos
			strcat(sinonimos, sin2); // junta os dois
			c = fgetc(arquivo);
		}
		insere_hash(tabela, hash(palavra), palavra, sinonimos); // insere a palavra no hash
		i = 0;
		if(c != '\n' && c != '&' && c != '/' && c != '|') // so aceita letras na palavra
		{
			palavra[i] = c;
		}
		else
		{
			c = fgetc(arquivo);
			while(c == '\n' || c == '&' || c == '/' || c == '|') // so aceita letras na palavra
			{
				c = fgetc(arquivo);
			}
			palavra[i] = c;
		}
		while(c != '|' && c != EOF)
		{
			i++;
			c = fgetc(arquivo); // le uma nova palavra letra por letra
			if(c != '|' && c!= '/' && c != '&') // so aceita letras na palavra
			{
				palavra[i] = c;
			}
		}
		palavra[i] = '\0'; // fim da palavra
	}
	fclose(arquivo); // fecha o arquivo
	printf("\nDigite a palavra que deseja encontrar: ");
	char busca[100];
	scanf("%s", &busca); // le a palavra que o usuario quer encontrar
	char *resultado_busca = busca_hash(tabela, hash(busca), busca); // procura a palavra na tabela
	while(resultado_busca == NULL) // se nao achar
	{
		printf("\nA palavra pesquisada nao existe no dicionario, favor digitar outra: ");
		scanf("%s", &busca);
		resultado_busca = busca_hash(tabela, hash(busca), busca); // continua ate que o usuario digite uma palavra valida
	}
	printf("\nOs sinonimos da palavra buscada sao: %s", resultado_busca);
	destroi_tabela(tabela); // libera a tabela
	return 0;
}
