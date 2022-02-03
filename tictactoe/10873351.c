#include<stdio.h>
#include<stdlib.h>

int main() {
	char matriz[3][3];

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			scanf(" %c", &matriz[i][j]);
		}
	}

	// verificar linha por linha para vitória
	for(int i = 0; i < 3; i++) {
		if(matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2] && matriz[i][0] != '-') {
			printf("%c ganhou\n", matriz[i][0]);
			exit(0);
		}
	}
	// verificar coluna por coluna
	for(int i = 0; i < 3; i++) {
		if(matriz[0][i] == matriz[1][i] && matriz[0][i] == matriz[2][i] && matriz[0][i] != '-') {
			printf("%c ganhou\n", matriz[i][0]);
			exit(0);
		}
	}
	// verificar diagonais
	if(matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2] && matriz[1][1] != '-') {
		printf("%c ganhou\n", matriz[0][0]);
		exit(0);
	}
	else if(matriz[0][2] == matriz[1][1] && matriz[0][2] == matriz[2][0] && matriz[2][2] != '-') {
		printf("%c ganhou\n", matriz[0][2]);
		exit(0);
	}
	// verificar -s
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(matriz[i][j] == '-') {
				printf("em jogo\n");
				exit(0);
			}
		}
	}
	// caso nada ocorra
	printf("empate\n");

	return 0;
}