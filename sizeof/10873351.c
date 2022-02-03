#include<stdio.h>

int main() {
	// imprimir tamanho dos tipos primitivos em bytes

	printf("%li\n", sizeof(unsigned char));
	printf("%li\n", sizeof(char));
	printf("%li\n", sizeof(unsigned int));
	printf("%li\n", sizeof(short int));
	printf("%li\n", sizeof(int));
	printf("%li\n", sizeof(long int));
	printf("%li\n", sizeof(unsigned long int));
	printf("%li\n", sizeof(long long int));
	printf("%li\n", sizeof(float));
	printf("%li\n", sizeof(double));
	printf("%li\n", sizeof(long double));


	return 0;
}