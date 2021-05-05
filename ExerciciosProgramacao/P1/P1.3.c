#include <stdio.h>

int contapulos(int degraus)
{
	if(degraus<0) return 0;
	else if(degraus==0) return 1;
	return contapulos(degraus-1)+contapulos(degraus-2);
}

int main(int argc, char *argv[]) {
	int degraus;
	scanf("%d", &degraus);
	printf("\n%d\n", contapulos(degraus));
	return 0;
}
