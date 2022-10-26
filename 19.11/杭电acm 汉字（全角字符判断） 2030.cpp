#include<stdio.h>
int main() {
	int n;
	char c;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		int j = 0;
		while ((c = getchar()) != '\n') if (c < 0) j++;
		printf("%d\n", j / 2);
	}
}
