#include<stdio.h>

int main() {
	int entrada;
	char a, b, c, d;
	// 11111111 = 255, que será a máscara para isolar os 8 bits mais
	// a direita do número de entrada
	scanf("%i", &entrada);
	
	// o programa vai armazenar os bytes da direita para a esquerda

	a = (entrada & 255); // armazena em a o byte mais a direita

	b = ((entrada >> 8) & 255); // armazena em b o byte mais a direita
								// após mover a sequência 8 casas para
								// a direita

	c = ((entrada >> 16) & 255); // em c após mover 16 casas para dir

	d = ((entrada >> 24) & 255); // em d após mover 24 casas
	
	//imprimindo o resultado da esquerda para a direita
	printf("%c%c%c%c\n", d, c, b, a);

	return 0;
}