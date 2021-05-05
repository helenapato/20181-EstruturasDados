#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	float valor_atual;
	valor_atual=789.54;
	float rendimento1;
	rendimento1=valor_atual*0.0056;
	valor_atual+=rendimento1;
	float deposito;
	deposito=303.20;
	valor_atual+=deposito;
	float rendimento2;
	rendimento2=valor_atual*0.0056;
	valor_atual+=rendimento2;
	float retirada;
	retirada=58.25;
	valor_atual-=retirada;
	float rendimento3;
	rendimento3=valor_atual*0.0056;
	valor_atual+=rendimento3;
	printf("%.2f", valor_atual);
	return 0;
}
