#include<stdio.h>
#include<string.h>
int main() {
	int n, m, i, j, a, b, c;
	long long sum;
	char choice[5];
	scanf("%d%d", &n, &m);
	int array[n + 6];
	memset(array, 0, 4 * (n + 6));
	for (i = 1; i <= n; i++) scanf("%d", &array[i]);
	for (i = 1; i <= m; i++) {
		int i1 = 0;
		memset(choice, 0, 5);
		scanf("%s%d%d", choice, &a, &b);
		if (a>b) a ^= b ^= a ^= b;
		switch (choice[0]) {
			case 'S':
				sum = 0;
				for (j = a; j <= b; j++) sum += array[j];
				printf("%lld\n", sum);
				break;
			case 'O':
				scanf("%d", &c);
				for (j = a; j <= b; j++) array[j] |= c;
		}
	}
}
