#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*"gratuito", "atencao", "urgente", "imediato", "zoombies", "oferta",
"dinheiro", "renda", "fundo", "limitado", "ajuda" e "SOS"*/
void apagarString(char string[]) {
	for(int i = 0; i < strlen(string); i++) {
		string[i] = '\0';
	}
}

int analisarPalavra(char palavra[]) {
	//printf("%s\n", palavra);
	if(strcmp(palavra, "gratuito") == 0 ||
		strcmp(palavra, "atencao") == 0 ||
		strcmp(palavra, "urgente") == 0 ||
		strcmp(palavra, "imediato") == 0 ||
		strcmp(palavra, "zoombies") == 0 ||
		strcmp(palavra, "oferta") == 0 ||
		strcmp(palavra, "dinheiro") == 0 ||
		strcmp(palavra, "renda") == 0 ||
		strcmp(palavra, "fundo") == 0 ||
		strcmp(palavra, "limitado") == 0 ||
		strcmp(palavra, "ajuda") == 0 ||
		strcmp(palavra, "SOS") == 0){
		//printf("%s\n", palavra);
		return 1;}
	return 0;
}

int quebrarLinha(char linha[]) {
	int qtd = 0;
	char palavra[76];
	int i = 0;

	for(int j = 0; j < 76; j++) {
		if(linha[j] == '\0' || linha[j] == '\n') {
			//printf("return %d\n", qtd);
			return qtd;
		}
		if(linha[j] != ' ' && linha[j] != ',' && linha[j] != '.') {
			palavra[i] = linha[j];
			i++;
		}
		else {
			palavra[i] = '\0'; 
			qtd = qtd + analisarPalavra(palavra);
			//printf("qtd func%d\n", qtd);
			apagarString(palavra);
			i = 0;
		}
	}
	return qtd;
}


int main() {
	int tamanhoLinha = 0, qtd = 0;
	char ler;
	char linha[76] = {};

	while(scanf("%c", &ler) != EOF) {
		if(ler == '\n') {
			// analisar linha
			linha[tamanhoLinha] = '\0';
			//printf("%s\n", linha);
			qtd = qtd + quebrarLinha(linha);
			if(qtd >= 2) {
				//printf("qtd %d\n", qtd);
				printf("Spam\n");
				exit(0);
			}
			tamanhoLinha = 0;
			apagarString(linha);
		}
		else { // estou lendo a linha
			linha[tamanhoLinha] = ler;
			tamanhoLinha++;
			if(tamanhoLinha > 76) {
				printf("Spam\n");
				exit(0);
			}

		}
	}
	printf("Inbox\n");

	return 0;
}