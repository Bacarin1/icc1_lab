#include<stdio.h>
#include<stdlib.h>

int main() {
	int altura, largura;
	scanf("%d %d", &largura, &altura);
	//criar a matriz que vai receber a imagem original
	int **imagemOriginal = malloc(altura * sizeof(void*));
	for(int i = 0; i < altura; i++) {
		imagemOriginal[i] = malloc(largura * sizeof(int));
	}
	for(int i = 0; i < altura; i++) {
		for(int j = 0; j < largura; j++) {
			scanf("%d", &imagemOriginal[i][j]);
		}
	}
	int tamanhoBorda;
	scanf("%d", &tamanhoBorda);
	int novaAltura = altura + tamanhoBorda * 2; // dimensões da
	int novaLargura = largura + tamanhoBorda * 2;// nova imagem
	int **novaImagem = calloc(novaAltura, sizeof(void*));
	for(int i = 0; i < novaAltura; i++) {
		novaImagem[i] = calloc(novaLargura, sizeof(int));
	}

	//copia a imagem antiga para dentro da matriz da imagem nova
	int linhaOriginal = 0, colunaOriginal = 0;
	for(int i = tamanhoBorda; i < altura + tamanhoBorda; i++) {
		for(int j = tamanhoBorda; j < largura + tamanhoBorda; j++) {
			novaImagem[i][j] = imagemOriginal[linhaOriginal][colunaOriginal];
			colunaOriginal++;
		}
		linhaOriginal++;
		colunaOriginal = 0;
	}

	for(int i = 0; i < novaAltura; i++) {
		for(int j = 0; j < novaLargura; j++) {
			printf("%d ", novaImagem[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	for(int i = 0; i < altura; i++) {
		for(int j = 0; j < largura; j++) {
			printf("%d ", imagemOriginal[i][j]);
		}
		printf("\n");
	}

	for(int i = novaAltura - 1; i >= 0; i--) {
		free(novaImagem[i]);
	}
	free(novaImagem);

	for(int i = altura - 1; i >= 0; i--) {
		free(imagemOriginal[i]);
	}
	free(imagemOriginal);

	return 0;
}