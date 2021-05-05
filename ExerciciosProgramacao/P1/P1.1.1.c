#include <stdio.h>
#include <string.h>
#define BUFSZ 1024

char *descompacta(char *string)
{
	int i1; int i2; int i3=0;
	int repeticoes;
	char *resposta=(char*)malloc(2*sizeof(string)+1);
	for(i1=0;i1<strlen(string);i1++)
	{
		if(isdigit(string[i1]))
		{
			repeticoes=string[i1]-48;
			for(i2=0;i2<repeticoes-1;i2++)
			{
				resposta[i3]=string[i1-1];
				i3++;
			}
		}
		else
		{
			resposta[i3]=string[i1];
			i3++;
		}
	}
	resposta[i3]='\0';
	return resposta;
}

int main(void) {
    // Lendo linha do arquivo de entrada:
    char linha[BUFSZ];
    fgets(linha, BUFSZ, stdin);
   
    // chame sua função aqui
    
    char *resposta=descompacta(linha);
	printf("\n%s\n", resposta);
	free(resposta);
    
    return 0;
}
