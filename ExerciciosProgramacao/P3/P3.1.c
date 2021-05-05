#include <stdio.h>
#include <stdlib.h>

void troca(int *valores, int i, int j)
{
	int a=valores[i];
	valores[i]=valores[j];
	valores[j]=a;
}

int particao(int *v, int in, int fi)
{
	int pivot = v[fi-1];
	int i = in;
	int j = fi-2;
	while(i<=j)
	{
		while(v[j] > pivot) j--;
		while(v[i] < pivot) i++;
		if(i < j) troca(v, i, j);
	}
	troca(v, i, fi-1);
	return i;
}

void quick_select(int *vet, int n, int inicio, int fim)
{
	int pivot;
	if((fim-inicio) > 1)
	{
		pivot = particao(vet, inicio, fim);
		if(pivot>n) quick_select(vet, n, inicio, pivot);
		else 
		{
			quick_select(vet, n, inicio, pivot);
			quick_select(vet, n, pivot+1, fim);
		}
		
	}
}

int main(void) 
{
	int *vetor = (int *) malloc(sizeof(int));
	int k;
	int i=1;
	int n=1;
	scanf("%d", &vetor[0]);
//	int cnt;
//	for(cnt=0;cnt<10;cnt++)
	while(scanf("%d", &k) != EOF)
	{
		n++;
//		scanf("%d", &k);
		vetor = (int *) realloc(vetor, n*sizeof(int));
		vetor[i] = k;
		i++;
	}
	k = vetor[i-1];
	quick_select(vetor, k, 0, i-1);
	for(i=0;i<k;i++)
	{
		printf("%d ", vetor[i]);
	}
	free(vetor);
}
