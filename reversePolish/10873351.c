/*Bloco 5 - Notação Polonesa Reversa
Alunp Gabriel Bacarin, N 10873351
esse programa funciona com um buffer, entrada, que tem como tamanho máximo o tamanho de um double
o programa vai lendo a entrada caracter a caracter;
	se o caracter é um número, ele é carregado no buffer
	se o caracter é uma operação, ela será executada a seguir
	se o caracter é um espaço, significa que o número digitado acabou e é hora de coloca-lo completo na stack, OU
							   significa que é hora de realizar uma operação

o uso de uma stack se dá por um vetor alocado dinamicamente e um apontador que fica apontando a próxima posição disponível da stack
*/

#include<stdio.h>
#include<stdlib.h>

double realizarOperacao(double *stack, int apontador, char op) {
	double num1 = stack[apontador - 2], num2 = stack[apontador - 1];
	double resposta;
	if(op == '+') {
		resposta = num1 + num2;
	}
	else if(op == '-') {
		resposta = num1 - num2;
	}
	else if(op == '*') {
		resposta = num1 * num2;
	}
	else {
		resposta = num1 / num2;
	}
	return resposta;
}

int main() {
	char entrada[sizeof(double)], ch;
	double numero;
	int i = 0, isEOF = 0;
	double *stack = malloc(0 * sizeof(double));
	int apontador = 0;

	while(1) {
		ch = fgetc(stdin);

		if(ch == EOF || ch == '\n') {
			isEOF = 1;
		}
		if(ch == ' ' || ch == EOF || ch == '\n') { //instrução atual acabou
			//analisar o que foi inserido
			entrada[i] = '\0';
			if(entrada[i - 1] == '+' || entrada[i - 1] == '-' || entrada[i - 1] == '*' || entrada[i - 1] == '/') { // será feita uma operação
				double append = realizarOperacao(stack, apontador, entrada[i - 1]);
				
				// poppar os dois últimos números da stack
				apontador = apontador - 1;
				stack = realloc(stack, apontador * sizeof(double));
				// pushar valor calculado
				stack[apontador - 1] = append;
			}
			else { // entrada foi um número
				numero = atof(entrada); //converte a entrada de string para float
				apontador++;
				stack = realloc(stack, (apontador) * sizeof(double));
				// push desse numero para o topo da stack
				stack[apontador - 1] = numero;
			}
			i = 0;
			if(isEOF == 1) {
				break;
			}
		}
		else { 
			entrada[i] = ch; // continua incrementando a entrada
			i++; 
		}
		
	}

	printf("Resultado: %.6f\n", stack[apontador - 1]);

	// libera o que foi alocado dinamicamente
	for(int j = 0; j < apontador; j++) {
		free(&stack[j]);
	}

	return 0;
}