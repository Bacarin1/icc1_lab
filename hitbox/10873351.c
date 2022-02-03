#include<stdio.h>
#include<stdlib.h>

int main() {
	long int xA, yA, lA, hA; // parametros do retangulo A
	long int xB, yB, lB, hB; // parâmetros do retangulo B
	long long int xInt = 0, yInt = 0, lInt = 0, hInt = 0; // parâmetros da intersecção
	int ix = 0, iy = 0; // "booleanos" que dizem se há intersecção no eixo x e no eixo y

	scanf("%ld %ld %ld %ld", &xA, &yA, &lA, &hA);
	scanf("%ld %ld %ld %ld", &xB, &yB, &lB, &hB);

	// para o eixo x
	
	if(xA < xB) { // se A está a esquerda de B
		if(abs(xA - xB) <= lA) { // se a distancia entre xA e xB for menor ou igual que a largura de A
			ix = 1; // pode acontecer interscção em x
			xInt = xB; // a intersecção começa na mesma vertical que o retangulo B
			if(xB + lB <= xA + lA) // se B termina antes que A
				lInt = lB;
			else
				lInt = (xA + lA) - xB; // o comprimento da intersecção é a distância entre o inicio de xB e o fim de xA (xA + lA)
		}
	}
	else if(xA > xB) { // se B está a esquerda de A
		if(abs(xA - xB) <= lB) { // se a distancia entre xA e xB for menor ou igual que a largura de B
			ix = 1; // pode acontecer interscção em x
			xInt = xA; // a intersecção começa na mesma vertical que o retangulo A
			if(xA + lA <= xB + lB)
				lInt = lA;
			else
				lInt = (xB + lB) - xA;
		}
	}
	else { ix = 1; xInt = xA; lInt = abs(xA - xB); } // se B está na mesma linha que A

	// para o eixo y

	if(yA < yB) { // se B está acima de A
		if(abs(yA - yB) <= hA) { // se a distancia entre A e B for menor ou igual que a altura de A
			iy = 1; // pode acontecer intersecção em B
			yInt = yB;
			if(yB + hB <= yA + hA) { // caso o B termine antes que o A
				hInt = hB;
			}
			else
				hInt = (yA + hA) - yB; // a altura da intersecção é a distância entre o inicio de yB e o fim de yA (yA + hA)
		}
	}
	else if(yA > yB) { // se A está acima de B
		if(abs(yA - yB) <= hB) { // se a distancia entre A e B for menor ou igual que a altura de B
			iy = 1; // pode acontecer intersecção em B
			yInt = yA;
			if(yA + hA <= yB + hB) { // caso o A termine antes que o B, exemplo, yA + altura de A forem menores que yB + altura de B
				// printf("aqui ó\n");
				hInt = hA;
			}
			else
				hInt = (yB + hB) - yA;
		}
	}
	else { iy = 1; yInt = yA; hInt = abs(yA - yB); }

	if(ix == 1 && iy == 1) {
		printf("HIT: %lld %lld %lld %lld\n", xInt, yInt, lInt, hInt);
	}
	else
		printf("MISS\n");

	return 0;
}