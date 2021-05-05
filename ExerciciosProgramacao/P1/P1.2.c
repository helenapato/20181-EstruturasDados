#include <stdio.h>
#include <string.h>
#define BUFSZ 1024

int unicos(char *string)
{
	int i1; int i2;
	for(i1=0;i1<strlen(string);i1++)
	{
		for(i2=i1+1;i2<strlen(string)-i1;i2++)
		{
			if(string[i1]==string[i2]) return 0;
		}
	}
	return 1;
}

int main(void) {
    // Lendo linha do arquivo de entrada:
    char linha[BUFSZ];
    fgets(linha, BUFSZ, stdin);
   
    // chame sua função aqui
    
	int resposta=unicos(linha);
	printf("\n%d\n", resposta);
    
    return 0;
}
