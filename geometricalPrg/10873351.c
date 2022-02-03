#include<stdio.h>

int main() {
	float a1, q, soma;
	int n;
	scanf("%f %f %d", &a1, &q, &n);

	soma = a1;

	for(int i = 0; i < n - 1; i++) {
		a1 = a1 * q;
		soma = soma + a1;
	}

	printf("%.2f\n%.2f\n", a1, soma);

	return 0;
}