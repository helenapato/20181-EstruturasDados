#include <stdio.h> 
#define BUFSZ 256 
int valor_absoluto(int a)
{
  if(a>=0) return a;
  else return -a;
}
int main(void) 
{
    // Lendo arquivo de entrada: 
    char line[BUFSZ]; 
    fgets(line, BUFSZ, stdin); 
    // Declaracao das variaveis A, B e C: 
    int A = 0; 
    int B = 0; 
    int C = 0; 
    // Inicializando A, B e C com os dados lidos do arquivo: 
    sscanf(line, "%d %d %d\n", &A, &B, &C); 
    // Insira codigo para calcular o numero com maior valor absoluto TODO
    int maximo;
    maximo=A;
    if(valor_absoluto(maximo)<valor_absoluto(B)) maximo=B;
    if(valor_absoluto(maximo)<valor_absoluto(C)) maximo=C;
    printf("%d\n", maximo);
    return 0; 
} 
