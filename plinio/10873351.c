#include<stdio.h>

int main() {
	char matriz[32][65];
	int iIni, jIni;

	for(int i = 0; i < 32; i++) {
		for(int j = 0; j < 65; j++) {
			scanf("%c", &matriz[i][j]);
			if(matriz[i][j] == '[') {
				iIni = i;
				jIni = j;
			}
		}
	}

	int i = iIni;
	int j = jIni + 2;
	char inercia = ' ';

	do {
		if(matriz[i][j] == '<') { // esteira para a esquerda
			matriz[i][j] = '.';
			j = j - 2;
			inercia = '<';
		}
		else if(matriz[i][j] == '>') { // esteira para a direita
			matriz[i][j] = '.';
			j = j + 2;
			inercia = '>';
		}
		else if(matriz[i][j] == '^') {	// esteira pra cima
			matriz[i][j] = '.';
			i = i - 1;
			inercia = '^';
		}
		else if(matriz[i][j] == 'v') { // esteira pra baixo
			matriz[i][j] = '.';
			i = i + 1;
			inercia = 'v';
		}
		else if(matriz[i][j] == '#') { // junção
			if(inercia == '<')
				j = j - 2;
			else if(inercia == '>')
				j = j + 2;
			else if(inercia == '^')
				i = i - 1;
			else
				i = i + 1;
		}
		else if(matriz[i][j] == '.') { // loop infinito
			i = -1;
			j = -1;
		}
		else if(matriz[i][j] == ' ') { // esteira com falha
			i = -1;
			j = 0;
		}
		else if(matriz[i][j] == ']') { // chegou ao fim
			i = -1;
			j = 1;
		}

	} while(i != (-1));

	if(j == -1) {
		printf("Loop infinito.\n");
	}
	else if(j == 0) {
		printf("Falha na esteira.\n");
	}
	else
		printf("Ok.\n");

	for(int i = 0; i < 32; i++) {
		for(int j = 0; j < 65; j++) {
			printf("%c", matriz[i][j]);
		}
	}

	return 0;
}