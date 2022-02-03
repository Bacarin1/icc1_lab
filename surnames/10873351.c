//Adicionando sobrenomes
//G. Bacarin, N 10873351

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *lerUltimoSobrenome(char **matrizNomes, int j, int qtdNomes);
void adicionarSobrenome(char **matrizNomes, int j, int qtdNomes, char *sobrenome);

int main() {
	int *qtdNomes = calloc(1, sizeof(int));
	qtdNomes[0] = 1;

	char **matrizNomes = malloc(sizeof(void *));

	int tamanhoPalavra = 0, i = 0;

	char entrada;
	do {
		scanf("%c", &entrada);
		tamanhoPalavra++;
		matrizNomes[i] = realloc(matrizNomes[i], tamanhoPalavra * sizeof(char));
		if(entrada == ' ') {
			qtdNomes[i] = qtdNomes[i] + 1;
		}
		if(entrada != '\n' && entrada != '$') {
			matrizNomes[i][tamanhoPalavra - 1] = entrada;
		}
		else {
			if(entrada == '$') {
				matrizNomes[i][tamanhoPalavra - 1] = '\0';
				break;
			}
			matrizNomes[i][tamanhoPalavra - 1] = '\0'; // fim do nome completo
			i++;
			*matrizNomes = realloc(*matrizNomes, (i + 1) * sizeof(void *)); // criando nova linha para próximo nome
			matrizNomes[i] = calloc(0, sizeof(char));
			qtdNomes = realloc(qtdNomes, (i + 1) * sizeof(int));
			qtdNomes[i] = 1;
			tamanhoPalavra = 0;
		}

	} while(entrada != '$');

	// nesse momento, eu tenho na matrizNomes todos os nomes inseridos, um em cada linha. Ela tem i + 1 linhas
	// tenho anotado no vetor qtdNomes quantas palavras - nomes e sobrenomes - cada nome completo tem. Devo usar isso para contar
	// quantos espaços devo pular para chegar no último sobrenome

	//agora vou iterar pela matriz com a variável j, indo de linha em linha
	for(int j = 0; j <= i; j++) {
		if(j % 2 == 0) { // se a linha é par
			if(j != i) { // e se não é a última linha
				//pegar o último sobrenome da linha j e colocar ele depois do último sobrenome da linha j+1
				char *sobrenome = lerUltimoSobrenome(matrizNomes, j, qtdNomes[j]);
				//printf("%s fim\n", sobrenome);
				adicionarSobrenome(matrizNomes, j + 1, qtdNomes[j + 1], sobrenome);
			}
		}
	}

	for(int j = 0; j <= i; j++) {
		printf("%s\n", matrizNomes[j]);
	}


	for(int j = i; j >= 0; j--) {
		free(matrizNomes[j]);
	}
	free(matrizNomes);
	free(qtdNomes);
	return 0;
}

void adicionarSobrenome(char **matrizNomes, int j, int qtdNomes, char *sobrenome) {
	int novoTamanho = strlen(matrizNomes[j]);
	novoTamanho = novoTamanho + (strlen(sobrenome)) + 2;
	int tamanhoNome = strlen(matrizNomes[j]);
	int tamanhoSobrenome = strlen(sobrenome);
	matrizNomes[j] = realloc(matrizNomes[j], novoTamanho * sizeof(char));

	matrizNomes[j][tamanhoNome] = ' ';
	int i;
	for(i = 0; i < tamanhoSobrenome; i++) {
		matrizNomes[j][tamanhoNome + i + 1] = sobrenome[i];
	}
	i++;
	matrizNomes[j][tamanhoNome + i + 1] = '\0';


}

char *lerUltimoSobrenome(char **matrizNomes, int j, int qtdNomes) {
	char *sobrenome = calloc(0, sizeof(char));
	int tamanhoNomeCompleto = strlen(matrizNomes[j]), tamanhoUltimoNome = 0, qtdEspacos = 0;
	for(int i = 0; i < tamanhoNomeCompleto; i++) {
		if(matrizNomes[j][i] == ' ') {
			qtdEspacos++;
			if(qtdEspacos == qtdNomes - 1) { //cheguei no sobrenome que eu quero
				for(int k = i + 1; k < tamanhoNomeCompleto; k++) {
					tamanhoUltimoNome++;
					sobrenome = realloc(sobrenome, tamanhoUltimoNome * sizeof(char));
					sobrenome[tamanhoUltimoNome - 1] = matrizNomes[j][k];
				}
				sobrenome = realloc(sobrenome, (tamanhoUltimoNome + 1) * sizeof(char));
				sobrenome[tamanhoUltimoNome] = '\0';
				break;
			}
		}
	}
	return sobrenome;



}