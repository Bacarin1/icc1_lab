#include<stdio.h>
#include<stdlib.h>

typedef struct atq {
	int danoAtaque;
	int tipoAtaque;
	float danoTotal;
} ataque;

int lerAtaques(ataque *entradasAtaque, int *qtdAtaques) {
	int dano, tipo;
	scanf("%d", &dano);
	if(dano == -1) {
		return dano; //se a entrada for -1, retorna -1 e o loop para
	}
	*qtdAtaques = *qtdAtaques + 1; //caso contrário, adiciona um novo ataque ao vetor;
	entradasAtaque = realloc(entradasAtaque, *qtdAtaques * sizeof(ataque));
	entradasAtaque[*qtdAtaques - 1].danoAtaque = dano;
	scanf("%d", &tipo);
	entradasAtaque[*qtdAtaques - 1].tipoAtaque = tipo;
	return 0;
}

void atribuirDano(float **matrizMulti, ataque *entradasAtaque, int indiceAtaque, int tipoInimigo) {
	entradasAtaque[indiceAtaque].danoTotal = entradasAtaque[indiceAtaque].danoAtaque * matrizMulti[entradasAtaque[indiceAtaque].tipoAtaque][tipoInimigo];
}

int main() {
	int qtdTipos;
	scanf("%d", &qtdTipos);
	//criando a matriz que vai receber os multiplicadores de dano
	float **matrizMulti = malloc(qtdTipos * sizeof(void*));
	for(int i = 0; i < qtdTipos; i++) {
		matrizMulti[i] = malloc(qtdTipos * sizeof(float));
	}

	//preenchendo a matriz com as entradas
	for(int i = 0; i < qtdTipos; i++) {
		for(int j = 0; j < qtdTipos; j++) {
			scanf("%f", &matrizMulti[i][j]);
		}
	}

	//criação do vetor de ataques
	int qtdAtaques = 0;
	ataque *entradasAtaque = malloc(0 * sizeof(ataque));
	int ler = 0;
	do {
		ler = lerAtaques(entradasAtaque, &qtdAtaques);
	} while(ler != -1);

	//leitura do tipo de inimigo
	int tipoInimigo;
	scanf("%d", &tipoInimigo);

	//atribuir os danos totais
	for(int i = 0; i < qtdAtaques; i++) {
		atribuirDano(matrizMulti, entradasAtaque, i, tipoInimigo);
	}

	//encontrar o índice do maior dano possível
	int indiceAtaque;
	float maiorDano = -1;
	for(int i = 0; i < qtdAtaques; i++) {
		if(entradasAtaque[i].danoTotal > maiorDano) {
			indiceAtaque = i;
			maiorDano = entradasAtaque[i].danoTotal;
		}
	}

	//printar o resultado
	printf("O melhor ataque possui indice %d e dano %.2f\n", indiceAtaque, maiorDano);

	//limpar as coisas - o vetor de ataques e a matriz de multiplicadores
	for(int i = qtdTipos - 1; i >= 0; i--) {
		free(matrizMulti[i]);
	}
	free(matrizMulti);
	free(entradasAtaque);


	return 0;
}