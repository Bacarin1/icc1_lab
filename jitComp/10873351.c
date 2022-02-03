/*Bloco 6 - Compilador JIT de Brainf*ck
Nome: Gabriel Bacarin N: 10873351

o programa só tem uma função que cria um arquivo e escreve um programa em C dentro dele, e depois executa o programa*/

#include<stdio.h>
#include<stdlib.h>

int main() {
	FILE *arquivo = fopen("jitGerado.c", "w");
	char entrada;

	fprintf(arquivo, "#include<stdio.h>\n#include<stdlib.h>\n\n");
	fprintf(arquivo, "int main() {\n");

	fprintf(arquivo, "int i = 0;\nchar mem[30000];\n\n");
	fprintf(arquivo, "for(int j = 0; j < 30000; j++) {\nmem[j] = 0;\n}\n");

	do {
		entrada = fgetc(stdin);
		if(entrada == '+') {
			fprintf(arquivo, "mem[i]++;\n");
		}
		else if(entrada == '-') {
			fprintf(arquivo, "mem[i]--;\n");
		}
		else if(entrada == '>') {
			fprintf(arquivo, "i++;\n");
		}
		else if(entrada == '<') {
			fprintf(arquivo, "i--;\n");
		}
		else if(entrada == '.') {
			fprintf(arquivo, "putchar(mem[i]);\n");
		}
		else if(entrada == '[') {
			fprintf(arquivo, "while(mem[i]) {\n");
		}
		else if(entrada == ']') {
			fprintf(arquivo, "}\n\n");
		}

	} while(entrada != EOF);

	fprintf(arquivo, "printf(\"\\n\");");
	fprintf(arquivo, "\nfor(int j = 0; j < 30000; j++) {\n");
	fprintf(arquivo, "if(mem[j] != 0) {\n");
	fprintf(arquivo, "printf(\"%%d \", mem[j]);");
	fprintf(arquivo, "}\n}\n");
	fprintf(arquivo, "printf(\"\\n\");");

	fprintf(arquivo, "}\n");

	fclose(arquivo);

	system("gcc jitGerado.c -o jit-exe");
	system("./jit-exe");

	return 0;
}