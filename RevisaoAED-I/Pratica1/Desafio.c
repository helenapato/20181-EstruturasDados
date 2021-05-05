#include <stdio.h>
#include <stdlib.h>

int calculo_digito_verificador (int cpf)
{
	int somaprod;
	int aux;
	int algarismos[9];
	int i;
	int dezena;
	int unidade;
	int digito_verificador;
	for(i=0;i<9;i++)
	{
		
		algarismos[i]=cpf%10;
		aux=cpf;
		cpf=aux/10;	
	}
	somaprod=algarismos[0]*2+algarismos[1]*3+algarismos[2]*4+algarismos[3]*5+algarismos[4]*6+algarismos[5]*7+algarismos[6]*8+algarismos[7]*9+algarismos[8]*10;
	aux=somaprod%11;
	if(aux==0 || aux==1) dezena=0;
	else dezena=11-aux;
	somaprod=dezena*2+algarismos[0]*3+algarismos[1]*4+algarismos[2]*5+algarismos[3]*6+algarismos[4]*7+algarismos[5]*8+algarismos[6]*9+algarismos[7]*10+algarismos[8]*11;
	aux=somaprod%11;
	if(aux==0 || aux==1) unidade=0;
	else unidade=11-aux;
	digito_verificador=dezena*10+unidade;
	return digito_verificador;
	

}

int main(int argc, char *argv[]) {
	int cpfi;
	int digito;
	//scanf("%d", &cpfi);
	cpfi=123456789;
	digito=calculo_digito_verificador(cpfi);
	if(digito<10) printf("%d0%d", cpfi, digito);
	else printf("%d%d", cpfi, digito);
	return 0;
}
