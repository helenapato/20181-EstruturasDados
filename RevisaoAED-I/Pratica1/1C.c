#include <stdio.h>
#define BUFSZ 256

int main(void)
{
	// Lendo arquivo de entrada:
	char line[BUFSZ];
	fgets(line, BUFSZ, stdin);

	// Declaracao das variaveis A e B:
	int A = 0;
	int B = 0;

	// Inicializando A e B com os dados lidos do arquivo:
	sscanf(line, "%d %d\n", &A, &B);

	// Declarando variaveis para o quociente e o resto:
	int quociente = 0;
	int resto = 0;

	// Insira codigo para calcular o valor do quociente e do resto aqui.
	while(A>=B)
	{
		A-=B;
		quociente++;
	}
	resto=A;
	// Nao modifique as outras linhas.
	// Utilize apenas os operadores aritmeticos de soma e subtracao.

	// Imprimir o resultado:
	printf("%d %d\n", quociente, resto);
	
	// Terminar de executar com sucesso:
	return 0;
}
