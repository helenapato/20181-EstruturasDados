#include <stdio.h>
#include <stdlib.h>

float calculo_imc(float altura, float peso)
{
	float altura2;
	float imc;
	altura2=altura*altura;
	imc=peso/altura2;
	return imc;
}
float diferenca_peso(float imc, float altura, float peso)
{
	float diferenca;
	float ideal;
	float altura2=altura*altura;
	if(imc<18.5)
	{
		ideal=18.5*altura2;
		diferenca=ideal-peso;
	}
	else if(imc>25)
	{
		ideal=25*altura2;
		diferenca=peso-ideal;
	}
	return diferenca;
}

int main(int argc, char *argv[]) {
	float imc_brutus;
	float imc_olivia;
	float diferenca_brutus;
	float diferenca_olivia;
	imc_brutus=calculo_imc(1.84,122);
	diferenca_brutus=diferenca_peso(imc_brutus,1.84,122);
	imc_olivia=calculo_imc(1.76,45);
	diferenca_olivia=diferenca_peso(imc_olivia,1.76,45);
	printf ("%.2f %.2f %.2f %.2f\n", imc_brutus, imc_olivia, diferenca_brutus, diferenca_olivia);	
	return 0;
}
