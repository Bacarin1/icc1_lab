#include<stdio.h>

void converter(int valorInicial, int *umReal,
				int *cinquenta, int *vinteecinco,
				int *dez, int *cinco, int *um) {
	*umReal = valorInicial / 100;
	valorInicial = valorInicial - *umReal * 100;

	*cinquenta = valorInicial / 50;
	valorInicial = valorInicial - *cinquenta * 50;

	*vinteecinco = valorInicial / 25;
	valorInicial = valorInicial - *vinteecinco * 25;

	*dez = valorInicial / 10;
	valorInicial = valorInicial - *dez * 10;

	*cinco = valorInicial / 5;
	valorInicial = valorInicial - *cinco * 5;

	*um = valorInicial;

}

int main() {
	int umReal, cinquenta, vinteecinco, dez, cinco, um, valorInicial;
	scanf("%d", &valorInicial);

	converter(valorInicial, &umReal, &cinquenta, &vinteecinco, &dez, &cinco, &um);

	printf("O valor consiste em %d moedas de 1 real\nO valor consiste em %d moedas de 50 centavos\nO valor consiste em %d moedas de 25 centavos\nO valor consiste em %d moedas de 10 centavos\nO valor consiste em %d moedas de 5 centavos\nO valor consiste em %d moedas de 1 centavo\n", 
			umReal, cinquenta, vinteecinco, dez, cinco, um);



	return 0;
}