#include<stdio.h>

void maior(int vetor[]) {
	int maior = vetor[0];
	for(int i = 1; i < 10; i++) {
		if(vetor[i] > maior) {
			maior = vetor[i];
		}
	}
	printf("%i ", maior);
}

void menor(int vetor[]) {
	int menor = vetor[0];
	for(int i = 1; i < 10; i++) {
		if(vetor[i] < menor) {
			menor = vetor[i];
		}
	}
	printf("%i ", menor);
}

void media(int vetor[]) {
	int soma = 0;
	for(int i = 0; i < 10; i++) {
		soma = soma + vetor[i];
	}
	printf("%.2f ", (soma / 10.0));
}

void moda(int vetor[]) {
	int frequencia[10][2] = {};
	int j = 0, adcZero = 0;
	for(int i = 0; i < 10; i++) {
		for(int k = 0; k <= j; k++) {
			if(frequencia[k][0] == vetor[i]) {
				frequencia[k][1]++;
				if(vetor[i] == 0 && adcZero == 0) {
					j++;
					adcZero++;
				}
				break;
			}
			else {
				if(k == j) {
					frequencia[k][0] = vetor[i];
					frequencia[k][1] = 1;
					j++;
					break;
				}
			}
		}
	}
	int maior[2] = {};
	for(int i = 0; i < j; i++) {
		if(frequencia[i][1] > maior[1]) {
			maior[0] = i;
			maior[1] = frequencia[i][1];
		}
	}
	printf("%i\n", frequencia[maior[0]][0]);
}

int main() {
	int vetor[10];
	for(int i = 0; i < 10; i++) {
		scanf("%i", &vetor[i]);
	}

	maior(vetor);
	menor(vetor);
	media(vetor);
	moda(vetor);

	return 0;
}