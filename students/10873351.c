/*Bloco 6 - Gerenciamento de estudantes
Aluno Gabriel Bacarin N 10873351*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct aluno{
	int id;
	char *nome;
	char *curso;
	int idade;
} aluno;

char *readLine() { // função para ler uma string do stdin
	char entrada;
	int tamanho = 0;
	char *texto = malloc(0 * sizeof(char));
	do {
		entrada = fgetc(stdin);

		tamanho = tamanho + 1;
		texto = realloc(texto, tamanho * sizeof(char)); // vai aumentar o tamanho da alocação em 1
		if(texto != NULL) { // caso a alocação tenha sido bem sucedida
			if(entrada == '\n') {
				texto[tamanho - 1] = '\0';				
			}
			else
				texto[tamanho - 1] = entrada;
		}
		else { //realloc não funcionou
			printf("Task failed successfully!\n");
			free(texto);
			exit(1);
		}
	} while(entrada != '\n');

	return texto;
}

void imprimirFichaAluno(aluno *alunos, int i) { // imprime a ficha completa do aluno selecionado
	printf("Nome: %s\n", alunos[i].nome);
	printf("Curso: %s\n", alunos[i].curso);
	printf("N USP: %d\n", alunos[i].id);
	printf("IDADE: %d\n", alunos[i].idade);
	printf("\n");
}

int main() { // main em duas partes - primeiro receber indefinidas entradas de cadastro de alunos
			 // 					  depois receber indefinidos comandos e por fim limpar as alocações
	int entrada, qtdAlunos = 0;
	aluno *alunos = malloc(0 * sizeof(aluno));

	while(1) {
		scanf("%d", &entrada);
		if(entrada == -1) {
			break;
		}
		qtdAlunos++;
		alunos = realloc(alunos, qtdAlunos * sizeof(aluno));

		alunos[qtdAlunos - 1].id = entrada;
		scanf("%*[\r\n]s");

		alunos[qtdAlunos - 1].nome = readLine();
		alunos[qtdAlunos - 1].curso = readLine();
		scanf("%d", &alunos[qtdAlunos - 1].idade);

	}

	while(1) {
		scanf("%d", &entrada);
		if(entrada == -1) {
			break;
		}
		else if(entrada == 1) {
			int idEntrada;
			scanf("%d", &idEntrada);

			for(int i = 0; i < qtdAlunos; i++) {
				if(idEntrada == alunos[i].id) {
					imprimirFichaAluno(alunos, i);
					break;
				}
			}
		}
		else if(entrada == 2) {
			char *cursoEntrada = readLine();

			for(int i = 0; i < qtdAlunos; i++) {
				if(strcmp(cursoEntrada, alunos[i].curso) == 0) {
					imprimirFichaAluno(alunos, i);
				}
			}
			free(cursoEntrada);
		}
		else {
			for(int i = 0; i < qtdAlunos; i++) {
				imprimirFichaAluno(alunos, i);
			}
		}
	}

	for(int i = 0; i < qtdAlunos; i++) {
		free(alunos[i].nome);
		free(alunos[i].curso);
	}
	free(alunos);


	return 0;
}