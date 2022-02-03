#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void limparString(char *string) {
	for(int i = 0; i < 21; i++) {
		string[i] = ' ';
	}
}

int main() {
	char tabu[21]; //21 espaços para poder incluir o \0 no fim
	limparString(tabu);
	scanf("%s\n", tabu);
	char buffer[21];
	limparString(buffer);
	int qtdTabu = 0;
	//cria a frase na heap
	char *frase = calloc(0, sizeof(char));
	int tamanhoFrase = 0;

	char entrada;
	int letraTabu = 0, letraBuffer = 0; //variáveis que contam o tamanho do buffer e da palavra tabu
	do {
		scanf("%c", &entrada);

		if(entrada == tabu[letraTabu]) { //se a entrada for igual a letra seguinte da palavra tabu
			buffer[letraBuffer] = entrada; //ela fica armazenada no buffer
			letraTabu++;
			letraBuffer++;
			//verificar se a palavra se tornou a mesma
			buffer[letraBuffer] = '\0';
			if(strcmp(buffer, tabu) == 0) { //se sim, jogo o buffer fora e ele não entra na frase final
				limparString(buffer);
				letraBuffer = 0;
				letraTabu = 0;
				qtdTabu++;
			}
		}
		else {
			//posso carregar o buffer na frase
			tamanhoFrase++;
			frase = realloc(frase, (tamanhoFrase + letraBuffer) * sizeof(char));
			int i;
			for(i = 0; i < letraBuffer; i++) {
				frase[tamanhoFrase - 1 + i] = buffer[i];
			}
			letraBuffer = 0;
			letraTabu = 0;
			limparString(buffer);
			//colocar o caractere lido atualmente
			tamanhoFrase = tamanhoFrase + i;
			frase = realloc(frase, tamanhoFrase * sizeof(char));
			if(entrada != '$') {
				frase[tamanhoFrase - 1] = entrada;
			}
			else {
				frase[tamanhoFrase - 1] = '\0';
			}

		}

	} while(entrada != '$');
	//imprime a resposta
	printf("A palavra tabu foi encontrada %d vezes\n", qtdTabu);
	printf("Frase: %s\n", frase);
	free(frase); //desaloca frase

	return 0;
}