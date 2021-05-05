#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) { // complexidade 2(logaritmando-1)+7 da ordem de logaritmando (n)
	int base; // 1
	int logaritmando; // 1
	int logaritmo; // 1
	int potencia; // 1
	scanf("%d %d", &base, &logaritmando); // 1
	for(logaritmo=0;potencia<logaritmando;logaritmo++) // logaritmando-1
	{
		potencia*=base; // logaritmando-1
	}
	printf("%d", logaritmo); // 1
	return 0; // 1
}
