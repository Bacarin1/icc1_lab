#include<stdio.h>

int main() {
	int hist[25];
	int cor[5] = {};
	int maiorOcorrencia = 0, indice = 0;

	for(int i = 0; i < 25; i++) {
		scanf("%d", &hist[i]);
		switch(hist[i]){
			case 0: cor[0] = cor[0] + 1;
			break;
			case 1: cor[1] = cor[1] + 1;
			break;
			case 2: cor[2] = cor[2] + 1;
			break;
			case 3: cor[3] = cor[3] + 1;
			break;
			case 4: cor[4] = cor[4] + 1;
		}
	}

	for(int i = 0; i < 5; i++) {
		if(cor[i] > maiorOcorrencia) {
			maiorOcorrencia = cor[i];
			indice = i;
		}
	}

	for(int i = 0; i < 5; i++) {
		if(cor[i] != 0) {
			printf("%d: |", i);
			for(int j = 0; j < cor[i]; j++){
				printf("#");
			}
			printf("\n");
		}
		else { printf("%d: |\n", i);}
	}

	for(int i = 0; i < 25; i++) {
		if(hist[i] == indice) {
			printf("%d\n", i);
		}
	}

	return 0;
}