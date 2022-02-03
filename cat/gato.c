#include<stdio.h>

int main() {
	int pote, bolinha;
	scanf("%i %i", &bolinha, &pote);

	if(((bolinha * 5) - (pote * 3)) < 0) {
		printf("R\n");
	}
	else if(((bolinha * 5) - (pote * 3)) < 30 && ((bolinha * 5) - (pote * 3)) >= 0) {
		printf("B\n");
	}
	else {
		printf("P\n");
	}

	return 0;
}