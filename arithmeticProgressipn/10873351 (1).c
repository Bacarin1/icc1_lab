#include<stdio.h>

int main() {
	long int a1, r, n, soma;

	scanf("%ld %ld %ld", &a1, &r, &n);
	soma = a1; // soma precisa começar por a1

	for(int i = 0; i < n - 1; i++) {
		a1 = a1 + r;
		soma = soma + a1; // a1 aqui virou an, e é acrescentado a soma
		if(i == n - 2) {
			printf("%ld\n%ld\n", a1, soma);
		}
	}

	return 0;
}