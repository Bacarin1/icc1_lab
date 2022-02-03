#include<stdio.h>

int main() {
	char alfabeto[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
							't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char upcaseAlfabeto[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
							'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	char caractere;

	int rotor1[26], rotor2[26], rotor3[26];
	int i = 0, rot1 = 0, rot2 = 0, rot3 = 0;

	scanf("%*[^\r\n]s");
	for(int i = 0; i < 26; i++) {
		scanf(" %d", &rotor1[i]);
	}
	for(int i = 0; i < 26; i++) {
		scanf(" %d", &rotor2[i]);
	}
	for(int i = 0; i < 26; i++) {
		scanf(" %d", &rotor3[i]);
	}

	scanf("%*[\r\n]s");	
	scanf("%*[^\r\n]s");
	scanf("%*[\r\n]s");

	while(scanf("%c", &caractere) != EOF) {
		i = 0;
		if(caractere >= 'a' && caractere <= 'z') {
			while(caractere != alfabeto[i]) {i++;}
			i = rotor3[rotor2[rotor1[i]]];
			printf("%c", alfabeto[i]);
		}
		else if(caractere >= 'A' && caractere <= 'Z') {
			while(caractere != upcaseAlfabeto[i]) {i++;}
			i = rotor3[rotor2[rotor1[i]]];
			printf("%c", upcaseAlfabeto[i]);
		}
		else {
			printf("%c", caractere);
			continue;
		}

		rot1++;

		int temp = rotor1[0];
		for(int i = 0; i < 25; i++) {
			rotor1[i] = rotor1[i + 1];
		}
		rotor1[25] = temp;

		if(rot1 == 26) {
			rot2++;
			rot1 = 0;

			temp = rotor2[0];
			for(int i = 0; i < 25; i++) {
				rotor2[i] = rotor2[i + 1];
			}
			rotor2[25] = temp;
			
			if(rot2 == 26) {
				rot3++;
				rot2 = 0;

				temp = rotor3[0];
				for(int i = 0; i < 25; i++) {
					rotor3[i] = rotor3[i + 1];
				}
				rotor3[25] = temp;

				if(rot3 == 26)
					rot3 = 0;
			}
		}

	}


	/*for(int i = 0; i < 26; i++) {
		printf(" %d", rotor1[i]);
	}*/

	return 0;
}