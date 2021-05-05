#include <stdio.h>
#include <stdlib.h>

void counting_sort(int *vetor, int n, int max, int min)
{
	int i;
	int j=0;
	int contador [max-min+1];
	int ordenado [n];
	for(i=0;i<max-min;i++)
	{
		contador[i]=0;
	}
	for(i=0;i<n;i++)
	{
		contador[vetor[i]-min]++;
	}
	i=0;
	while(i<n)
	{
		while(contador[j] != 0)
		{
			ordenado[i]=j+min;
			contador[j]--;
			i++;
		}
		j++;	
	}
	for(i=0;i<n;i++)
	{
		printf("%d ", ordenado[i]);
	}
}

int main(void) 
{
	int *vetor = (int *) malloc(sizeof(int));
	int *vetor_ordenado;
	int k;
	int i=1;
	int n=1;
	scanf("%d", &vetor[0]);
//	int cnt;
//	for(cnt=0;cnt<7;cnt++)
	while(scanf("%d", &k) != EOF)
	{
		n++;
//		scanf("%d", &k);
		vetor = (int *) realloc(vetor, n*sizeof(int));
		vetor[i] = k;
		i++;
	}
	int max=vetor[0]; 
	int min=vetor[0];
	for(i=0;i<n;i++)
	{
		if(vetor[i]<min) min=vetor[i];
		if(vetor[i]>max) max=vetor[i];
	}
	counting_sort(vetor, n, max, min);	
	free(vetor);
}
