#include <stdio.h>
#include <string.h>
#define BUFSZ 1024

char *compacta(char *string)
{
	char *resposta=(char*)malloc(2*sizeof(string)+1);
	int repeticoes=1;
	int i1;
	int i2=0;
	int i3;
	int ndigitos;
	for(i1=0;i1<strlen(string);i1++)
	{
		if(string[i1]==string[i1+1]) repeticoes++;
		else
		{
			if(repeticoes==1)
			{
				resposta[i2]=string[i1];
				i2++;
			}
			else
			{
				resposta[i2]=string[i1];
				i2++;
				resposta[i2]=repeticoes+48;
				i2++;
				repeticoes=1;
			}
			
		}
	}
	resposta[i2]='\0';
	return resposta;
}

int main(void) {
    // Lendo linha do arquivo de entrada:
    char linha[BUFSZ];
    fgets(linha, BUFSZ, stdin);
   
    // chame sua função aqui
    
    char *resposta=compacta(linha);
	printf("\n%s\n", resposta);
	free(resposta);
    
    return 0;
}
