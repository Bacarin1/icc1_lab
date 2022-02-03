#include<stdio.h>

int main() {
	int a, b;

	scanf("%i %i", &a, &b);

	printf("%i\n", (a & b)); // and
	printf("%i\n", (a | b)); // or
	printf("%i\n", (a ^ b)); // xor
	printf("%i\n", (~a)); // complemento a
	printf("%i\n", (~b)); // complemento b
	printf("%i\n", (a >> 2)); // a rshift 2
	printf("%i\n", (b << 2)); // b lshift 2

	return 0;
}