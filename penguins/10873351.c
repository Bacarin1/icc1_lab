#include<stdio.h>
#include<stdlib.h>

int main() {
	int rodada = 1, rodadaMax, nJogadores, posicao, posat = 1;
	
	scanf("%d %d %d", &rodadaMax, &nJogadores, &posicao);
	
	int parada = 0;

	while(rodada <= rodadaMax) {
		for(int i = 0; i < rodada; i++) {
			if(posat == posicao) {
				if(rodada == 1) {
					printf("%d pinguim\n", rodada);
				}
				else
					printf("%d pinguins\n", rodada);
			}
			posat++;
			if(posat == nJogadores + 1) {
				posat = 1;
			}
			parada++;
			if(parada == rodadaMax) {
				exit(0);
			}
		}
		for(int i = 0; i < rodada; i++) {
			if(posat == posicao) {
				printf("no gelo\n");
			}
			posat++;
			if(posat == nJogadores + 1) {
				posat = 1;
			}
			parada++;
			if(parada == rodadaMax) {
				exit(0);
			}
		}
		for(int i = 0; i < rodada; i++) {
			if(posat == posicao) {
				printf("uhuu!\n");
			}
			posat++;
			if(posat == nJogadores + 1) {
				posat = 1;
			}
			parada++;
			if(parada == rodadaMax) {
				exit(0);
			}
		}
		rodada++;
	}
	return 0;
}