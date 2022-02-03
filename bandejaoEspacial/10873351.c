#include<stdio.h>
#include<string.h>

void converter(long long unsigned int segundosViagem,
					long long unsigned int *dias,
					long long unsigned int *horas,
					long long unsigned int *minutos,
					long long unsigned int *segundos,
					char nomePlaneta[]) {
	// 1 dia na Terra = 86400 segundos
	// 1 hora = 3600 segundos
	// 1 minuto = 60 segundos
	if(strcmp(nomePlaneta, "Terra") == 0) {
		*dias = segundosViagem / 86400;
		segundosViagem = segundosViagem - (*dias * 86400);
	}
	else if(strcmp(nomePlaneta, "Venus") == 0) {
		*dias = segundosViagem / 20995200; //243 dias terrestres em segundos
		segundosViagem = segundosViagem - (*dias * 20995200);
	}
	else if(strcmp(nomePlaneta, "Mercurio") == 0) {
		*dias = segundosViagem / 5068800; //58 dias terrestres e 16 horas em segundos
		segundosViagem = segundosViagem - (*dias * 5068800);
	}
	else { // Jupiter
		*dias = segundosViagem / 35760; // 9 horas e 56 minutos em segundos
		segundosViagem = segundosViagem - (*dias * 35760);
	}

	*horas = segundosViagem / 3600;
	segundosViagem = segundosViagem - (*horas * 3600);

	*minutos = segundosViagem / 60;
	segundosViagem = segundosViagem - (*minutos * 60);

	*segundos = segundosViagem;
}

int main() {
	char nomePlaneta[10] = {};
	long long unsigned int segundosViagem, dias, horas, minutos, segundos;

	scanf("%llu %s", &segundosViagem, nomePlaneta);

	converter(segundosViagem, &dias, &horas, &minutos, &segundos, nomePlaneta);

	printf("%llu segundos no planeta %s equivalem a:\n%llu dias, %llu horas, %llu minutos e %llu segundos\n", 
			segundosViagem, nomePlaneta, dias, horas, minutos, segundos);

	return 0;
}