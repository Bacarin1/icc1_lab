#include<stdio.h>

int main() {
	int ano;
	scanf("%i", &ano);
	if(ano % 4 == 0) {
		if(ano % 100 == 0) {
			if(ano % 400 == 0){
				printf("SIM\n");
			}
			else
				printf("NAO\n");
		}
		else {
			printf("SIM\n");
		}
	}
	else
		printf("NAO\n");

	return 0;
}