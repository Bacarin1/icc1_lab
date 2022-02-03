#include<stdio.h>


int main() {
	char string[50000];
	char ler;
	int i = 0, linha = 0, palavra = 0, caracter = 0;

	while(scanf("%c", &ler) != EOF) {
		string[i] = ler;
		i++;
	}
	string[i] = '\0';

	for(int j = 0; j < i; j++) {
		if(string[j] == ' ' || string[j] == '\r' || string[j] == '\n' || string[j] == '\t') {
			if(string[j - 1] != ' ' && string[j - 1] != '\n' && string[j - 1] != '\r' && string[j - 1] != '\t')
				palavra++;
		}
		if(string[j] == '\n') {
			linha++;
		}
		caracter++;
	}
	if(string[i - 1] != '\n')
		palavra++;

	printf("Linhas\tPalav.\tCarac.\n");
	printf("%d\t%d\t%d\n", linha, palavra, caracter);

	return 0;
}