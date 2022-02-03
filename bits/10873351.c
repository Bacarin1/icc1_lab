#include<stdio.h>
#include<math.h>

int main() {
	double a, b;
	// da biblioteca math.h pegamos a funcao pow(base, expoente)
	// compila usando -lm
	scanf("%lf %lf", &a, &b);
	printf("%.4lf\n", (pow(a, b)));

	return 0;
}