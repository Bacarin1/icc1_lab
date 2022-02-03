#include<stdio.h>

int main() {
	int x = 0, y = 0;
	char input;

	for(int i = 0; i < 6; i++) {
		scanf("%c", &input);
		switch(input) {
			case 'W' : y++;
			break;
			case 'A' : x--;
			break;
			case 'S' : y--;
			break;
			case 'D' : x++;
		}
	}

	printf("%d %d\n", x, y);

	return 0;
}