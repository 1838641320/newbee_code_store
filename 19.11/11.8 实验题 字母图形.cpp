#include<stdio.h>
#include<math.h>
int main() {
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			printf("%c", 'A' + (abs(j - i) % 26));
		printf("\n");
	}
}