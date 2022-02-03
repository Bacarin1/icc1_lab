#include<stdio.h>
// eu não estou nada feliz com como esse programa está, vou pensar em algo melhor e fazer a versão completa depois
int main() {
	int dia;
	scanf("%d", &dia);

	printf("         Abril 2021         \n");
	printf(" Do  Se  Te  Qu  Qu  Se  Sa \n");
	printf("                ");
	for(int i = 1; i < 31; i++) {
		if(i == dia) {
			printf("(%2d)", i);
		}
		else {
			printf(" %2d ", i);
		}
		if(i == 3 || i == 10 || i == 17 || i == 24)
			printf("\n");
	}
	printf("\n");
	return 0;
}