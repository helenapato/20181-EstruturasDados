#include <stdio.h>
#define BUFSZ 256

int main(void)
{
    // Lendo arquivo de entrada:
    char line[BUFSZ];
    fgets(line, BUFSZ, stdin);

    // Lendo e inicializando o CPF lido da entrada:
    int CPF = 0;
    sscanf(line, "%ld\n", &CPF);

    // Insira codigo para calcular a unidade e a dezena do CPF aqui.
    
    int d0, d1, d2, d3, d4, d5, d6, d7, d8; 
	int somaprod1, somaprod2; 
	int dezena, unidade; 
	int restoAux; 
	d0=CPF%10;         d1=CPF/10%10;       d2=CPF/100%10; 
	d3=CPF/1000%10;    d4=CPF/10000%10; 
	d5=CPF/100000%10;  d6=CPF/1000000%10; 
	d7=CPF/10000000%10; d8=CPF/100000000%10;
	//calculo da dezena 
	somaprod1=d0*2+d1*3+d2*4+d3*5+d4*6+d5*7+d6*8+d7*9+d8*10; 
	restoAux=somaprod1%11; 
	dezena=(restoAux<2) ? (0) : (11-restoAux);
	//calculo da unidade 
	somaprod2=dezena*2+  d0*3+d1*4+d2*5+d3*6+d4*7+d5*8+d6*9+d7*10+d8*11; 
	restoAux=somaprod2%11; 
	unidade=restoAux<2 ? 0 : 11-restoAux;
	
    // Nao modifique as outras linhas.
//    int dezena = 0;
//    int unidade = 0;

    // Imprimir o resultado:
    printf("%09d-%d%d\n", CPF, dezena, unidade);

    // Terminar de executar com sucesso:
    return 0;
}

