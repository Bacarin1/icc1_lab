#include<stdio.h>

int main() {
	int a, b, ans;
	scanf("%d %d", &a, &b);
	ans = a;
	for(int i = 1; i < b; i++) {
		ans = ans * a;
	}

	printf("%d\n", ans);

	return 0;
}