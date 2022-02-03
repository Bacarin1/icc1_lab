#include<stdio.h>

char matriz[32][64]; // variável global chamada em diversas funções

void inicializaMatriz() { // transforma todas as posições da matriz em partículas de ar
	for(int i = 0; i < 32; i++) {
		for(int j = 0; j < 64; j++) {
			matriz[i][j] = ' ';
		}
	}
}

void copiarMatriz(char matrizCopiar[][64], char matrizCopiada[][64]) { // transforma a matrizCopiar na matrizCopiada
	for(int i = 0; i < 32; i++) {
		for(int j = 0; j < 64; j++) {
			matrizCopiar[i][j] = matrizCopiada[i][j];
		}
	}
}

void imprimirMatriz() { // imprime a matriz
	//printf("imprimindo matriz?\n");
	//printf("caracter %c\n", matriz[][]);
	for(int i = 0; i < 32; i++) {
		for(int j = 0; j < 64; j++) {
			printf("%c", matriz[i][j]);
		}
		printf("\n");
	}
}

void moverAreia(int i, int j, char copia[32][64]);
void moverAgua(int i, int j, char copia[32][64]);

void calcularFisica() {
	char copia[32][64]; // cria a matriz na qual vão acontecer as mudanças
	copiarMatriz(copia, matriz); // copia se torna igual a matriz
	for(int i = 0; i < 32; i++) {
		for(int j = 0; j < 64; j++) { // percorre todas as posições da matriz
			if(matriz[i][j] == '#') { //verifica se é partícula de areia
				moverAreia(i, j, copia);
			}
			else if(matriz[i][j] == '~') { //verifica se é partícula de água
				moverAgua(i, j, copia);
			}
		}
	}
	copiarMatriz(matriz, copia); // aplica as alterações na matriz
}

int main() {
	inicializaMatriz();
	int nFrames, frame, x, y;
	char novaParticula;

	scanf("%d", &nFrames);

	int contador = 0;
	while(contador < nFrames) {
		int nLido = scanf(" %d: %d %d %c", &frame, &y, &x, &novaParticula);

		if(nLido == EOF) {
			frame = nFrames;
		}

		//printf("frame - %d, x - %d, y - %d, nova Particula - %c\n", frame, x, y, novaParticula);

		while(contador < frame) {
			printf("frame: %d\n", contador + 1);
			imprimirMatriz(); // imprimir a matriz
			calcularFisica(); // calcular a física
			contador++;
		}

		if(nLido != EOF) {
			matriz[x][y] = novaParticula;
			//printf(" caracter %c\n", matriz[x][y]);
		}
	}

	return 0;
}

void moverAreia(int i, int j, char copia[32][64]) {
	char temp;
	if(i != 31) { //não é a última linha >> pode se mover pra baixp
		if(matriz[i + 1][j] != '@' && matriz[i + 1][j] != '#') { //se a posição abaixo não é cimento nem areia
			temp = copia[i][j];
			copia[i][j] = copia[i + 1][j];
			copia[i + 1][j] = temp;
			return;
		}
	
		if(j != 0) { //não está no canto esquerdo >> pode se mover para a esquerda
			if(matriz[i + 1][j - 1] != '@' && matriz[i + 1][j - 1] != '#') { // se a posição à esquerda está livre
				temp = copia[i][j];
				copia[i][j] = copia[i + 1][j - 1];
				copia[i + 1][j - 1] = temp;
				return;
			}
		}
		if(j != 63) { //não está no canto direito >> pode se mover para a direira
			if(matriz[i + 1][j + 1] != '@' && matriz[i + 1][j + 1] != '#') { // se a posição à direita está livre
				temp = copia[i][j];
				copia[i][j] = copia[i + 1][j + 1];
				copia[i + 1][j + 1] = temp;
				return;
			}
		}
	}
}

void moverAgua(int i, int j, char copia[32][64]) {
	char temp;
	if(i != 31) { //não é a última linha >> pode se mover pra baixp
		if(matriz[i + 1][j] == ' ') { //se a posição abaixo é ar
			temp = copia[i][j];
			copia[i][j] = copia[i + 1][j];
			copia[i + 1][j] = temp;
			return;
		}
	
		if(j != 0) { //não está no canto esquerdo >> pode se mover para a esquerda
			if(matriz[i + 1][j - 1] == ' ') { // se a posição à esquerda abaixo está livre
				temp = copia[i][j];
				copia[i][j] = copia[i + 1][j - 1];
				copia[i + 1][j - 1] = temp;
				return;
			}
		}
		if(j != 63) { //não está no canto direito >> pode se mover para a direira
			if(matriz[i + 1][j + 1] == ' ') { // se a posição à direita abaixo está livre
				temp = copia[i][j];
				copia[i][j] = copia[i + 1][j + 1];
				copia[i + 1][j + 1] = temp;
				return;
			}
		}
	}
	if(j != 0) { //não está no canto esquerdo >> pode se mover para a esquerda na mesma linha
		if(matriz[i][j - 1] == ' ') { // se a posição à esquerda está livre
			temp = copia[i][j];
			copia[i][j] = copia[i][j - 1];
			copia[i][j - 1] = temp;
			return;
		}
	}
	if(j != 63) { //não está no canto direito >> pode se mover para a direira na mesma linha
		if(matriz[i][j + 1] == ' ') { // se a posição à direita está livre
			temp = copia[i][j];
			copia[i][j] = copia[i][j + 1];
			copia[i][j + 1] = temp;
			return;
		}
	}

}