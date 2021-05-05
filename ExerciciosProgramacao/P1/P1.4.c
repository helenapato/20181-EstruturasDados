#include <stdio.h>

int buscaBinaria(int *array, int esquerda, int direita, int n)
{
	if (direita < esquerda) 
	{
    	return -1;
	}
	int meio = (esquerda + direita) / 2;
	if (n == array[meio]) return meio;
	else 
	{
    	if (n < array[meio])
    	{
    		return buscaBinaria(array, esquerda, meio - 1, n);
		}
    	else
    	{
    		return buscaBinaria(array, meio + 1, direita, n);
		}
	}
}

int main(int argc, int argv) {
	int *vetor;
	int array[25];
	vetor=array;
	int i=0;
	while(scanf("%d", (vetor+i)) != EOF)
	{
		i++;
	}
	i--;
	int n=*(vetor+i);
	printf("\n%d\n", buscaBinaria(vetor,0,i-1,n));
}
