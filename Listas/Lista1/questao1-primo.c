#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char *argv[]) { // complexidade 2n+6 ordem de n
	int n; // 1
	int i; // 1
	int divisores=0; // 1
	scanf("%d", &n); // 1
	for(i=1;i<=n;i++) // n
	{
		if(abs(n)%i==0) divisores++; // n
	}
	if(divisores==2) printf("primo"); // 1
	else printf("nao primo"); // 1
	return 0;
}
