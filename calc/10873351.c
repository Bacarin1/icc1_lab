#include<stdio.h>

int main() {
	double a, b;
	char op;

	scanf("%lf %c %lf", &a, &op, &b);

	switch(op){
		case '+' : 
			printf("%.6lf\n", (a + b));
			break;
		case '-' :
			printf("%.6lf\n", (a - b));
			break;
		case '/' :
			printf("%.6lf\n", (a / b));
			break;
		case '*' :
			printf("%.6lf\n", (a * b));
			break;
		case '%' :
			printf("%.6lf\n", ((a / b) * 100));
			break;
	}

}