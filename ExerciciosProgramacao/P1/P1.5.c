#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *array, int i, int n)
{
	int i1; int i2=0;
	int menor=array[0];
	for(i1=0;i1<n;i1++)
	{
		if(array[i1]<menor)
		{
			menor=array[i1];
			i2=i1;
		}
	}
	printf("%d ", menor);
	for(i1=i2;i1<n;i1++)
	{
		array[i1]=array[i1+1];
	}
	if(n>1) selectionSort(array, i+1, n-1);
}

int main(int argc, char *argv[]) {
	int i=0;
	int vetor[100];
	int n=0;
	while(scanf("%d", &vetor[n])!=EOF)
	{
		n++;
	}
	selectionSort(vetor, i, n);
	return 0;
}
