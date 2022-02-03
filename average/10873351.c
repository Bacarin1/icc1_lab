#include<stdio.h>

int main() {
	double numeros[4], temp;

	scanf("%lf %lf %lf %lf", &numeros[0], &numeros[1], &numeros[2], &numeros[3]);
	// usando bubble sort para separar os 3 maiores numeros nas 3
	// primeiras posicoes do vetor
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++){
			if(numeros[j] < numeros[j + 1]) {
				temp = numeros[j];
				numeros[j] = numeros[j + 1];
				numeros[j + 1] = temp;
			}
		}
	}
	
	printf("%.4lf\n", ((numeros[0] + numeros[1] + numeros[2]) / 3.0));

	return 0;
}