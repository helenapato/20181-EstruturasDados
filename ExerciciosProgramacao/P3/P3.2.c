#include <stdio.h>
#include <stdlib.h>

void troca(int *valores, int i, int j)
{
	int a=valores[i];
	valores[i]=valores[j];
	valores[j]=a;
}
void conserta_heap(int *heap, int n, int i)
{
	int e = (2*i)+1;
	int d = (2*i)+2;
	int menor;
	if(e < n && heap[e] < heap[i]) menor=e;
	else menor = i;
	if(d < n && heap[d] < heap[menor]) menor = d;
	if(menor != i)
	{
		troca(heap, i, menor);
		conserta_heap(heap, n, menor);
	}
}

void conserta_heap_todo(int *heap, int n)
{
	int i;
	for(i=((n/2)-1);i>=0;i--) conserta_heap(heap, n, i);
}

void heap_sort_k(int *vetor, int n, int k)
{
	int i;
	int j = n-k;
	conserta_heap_todo(vetor, n);
	for(i=n-1;i>=j;i--)
	{
		troca(vetor, 0, i);
		n--;
		conserta_heap(vetor, n, 0);
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
	n--;
	heap_sort_k(vetor, n, k);
	for(i=n-1;i>=n-k;i--) printf("%d ", vetor[i]);
	free(vetor);
}
