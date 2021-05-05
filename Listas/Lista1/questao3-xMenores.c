#include <stdio.h>
#include <stdlib.h>
// complexidade da ordem de n^2
int * nMenores(int *vetor, int n, int x)
{
	int *menores = (int*)malloc(x*sizeof(int)); // 1
	int menor; // 1
	int i1; int i2; int i3=0;  // 1
	int i4=n; // 1
	for(i1=0;i1<x;i1++) // x vezes
	{
		menor=vetor[0]; // x vezes
		i3=0; // x vezes
		for(i2=0;i2<i4;i2++) // i4*x vezes
		{
			if(vetor[i2]<menor) // i4*x vezes
			{
				menor=vetor[i2]; // i4*x-t vezes
				i3=i2;  // i4*x-t vezes
			}
			
		}
		menores[i1]=menor; // x vezes
		i4--; // x vezes
		for(i2=i3;i2<i4;i2++) // (i4-i3)*x vezes
		{
			vetor[i2]=vetor[i2+1]; // (i4-i3)*x vezes
		}
	}
	return menores; // 1
	free(menores); // 1
}

int main(int argc, char *argv[]) 
{
	int i; // 1
	int x; // 1
	int tamanho; // 1 
	scanf("%d %d", &x, &tamanho); // 1
	int *ponteiro_menores; // 1
	int *arranjo = malloc(sizeof(int) * tamanho); // 1
 	for(i=0;i<tamanho;i++) // tamanho vezes
 	{
 		scanf("%d", &arranjo[i]); // tamanho vezes
 	}
 	ponteiro_menores=nMenores(arranjo,tamanho,x); // 1
 	for(i=0;i<x;i++) // x vezes
 	{
		printf("%d ", *ponteiro_menores); // x vezes
		ponteiro_menores++; // x vezes
 	}
	free(arranjo); // 1
	return 0; // 1
}
