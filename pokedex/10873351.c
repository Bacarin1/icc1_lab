/*Bloco 6 - Pokedex
Alunp Gabriel Bacarin N 10873351*/

#include<stdio.h>
#include<stdlib.h>

typedef struct status {
	int hp;
	int atq;
	int def;
	int sAtq;
	int sDef;
	int vel;
} status;

typedef struct attack {
	char nomeAtq[20];
	int poderBase;
	float acc;
	char classe;
} attack;

typedef struct pokemon {
	char nome[50];
	char tipoPri[20];
	char tipoSec[20];
	status atributos;
	attack ataques[4];
} pokemon;

pokemon incluirPokemon() { // preencher os dados de um novo pokémon e retornar
	pokemon novoPoke;
	scanf("%s", novoPoke.nome);
	scanf("%s", novoPoke.tipoPri);
	scanf("%s", novoPoke.tipoSec);
	scanf("%d %d ", &novoPoke.atributos.hp, &novoPoke.atributos.atq);
	scanf("%d %d ", &novoPoke.atributos.def, &novoPoke.atributos.sAtq);
	scanf("%d %d", &novoPoke.atributos.sDef, &novoPoke.atributos.vel);
	return novoPoke;
}

attack incluirAtaque() { // preencher um ataque e retornar ele
	attack ataque;
	scanf("%s", ataque.nomeAtq);
	scanf("%d %f %c", &ataque.poderBase, &ataque.acc, &ataque.classe);
	return ataque;
}

void imprimirPokemon(pokemon poke) { // imprimir dados de um pokémon dado
	printf("Nome do Pokemon: %s\n", poke.nome);
	printf("Tipo primario: %s\n", poke.tipoPri);
	printf("Tipo secundario: %s\n", poke.tipoSec);
	printf("Status:\n");
	printf("\tHP: %d\n", poke.atributos.hp);
	printf("\tAtaque: %d\n", poke.atributos.atq);
	printf("\tDefesa: %d\n", poke.atributos.def);
	printf("\tAtaque Especial: %d\n", poke.atributos.sAtq);
	printf("\tDefesa Especial: %d\n", poke.atributos.sDef);
	printf("\tVelocidade: %d\n\n", poke.atributos.vel);
}

void imprimirAtaque(attack ataque) { // imprimir um ataque específico de um pokémon específico
	printf("Nome do Ataque: %s\n", ataque.nomeAtq);
	printf("Poder base: %d\n", ataque.poderBase);
	printf("Acuracia: %f\n", ataque.acc);
	printf("Classe: %c\n\n", ataque.classe);
}

int main() {
	int comando, qtdPoke = 0;
	pokemon *poke = malloc(0 * sizeof(pokemon));

	while(1) {
		scanf("%d", &comando);
		if(comando == 0) { //encerrar pokedex
			break;
		}
		if(comando == 1) { //cadastrar pokémon
			qtdPoke++;
			poke = realloc(poke, qtdPoke * sizeof(pokemon));
			poke[qtdPoke - 1] = incluirPokemon();
		}
		if(comando == 2) { //cadastrar ataque em pokémon existente
			int indexPoke, indexAtq;
			scanf("%d %d", &indexPoke, &indexAtq);
			poke[indexPoke].ataques[indexAtq] = incluirAtaque();
		}
		if(comando == 3) { //imprimir dados de pokémon
			int indexPoke;
			scanf("%d", &indexPoke);
			imprimirPokemon(poke[indexPoke]);
		}
		if(comando == 4) { //imprimir dados de um ataque
			int indexPoke, indexAtq;
			scanf("%d %d", &indexPoke, &indexAtq);
			imprimirAtaque(poke[indexPoke].ataques[indexAtq]);
		}
	}

	free(poke);

	return 0;
}