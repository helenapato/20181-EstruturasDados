#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
			resposta[i2]=string[i1];
			i2++;
			resposta[i2]=repeticoes+48;
			i2++;
			repeticoes=1;
		}
	}
	resposta[i2]='\0';
	return resposta;
}

char *descompacta(char *string)
{
  int i1;
  char *resposta=(char*)malloc(2*sizeof(string)+1);
  for(i1=)
}

int main(void) 
{
	char string[] = "aaaaabcdddeeeffffffabc";
	char *resposta=compacta(string);
	char *resposta2=descompacta(resposta);
	printf("\n%s\n", resposta);
	printf("\n%s\n", resposta2);
	free(resposta);
	free(resposta2);
	return 0;
}
