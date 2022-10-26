#include<stdio.h>
#include<string.h>
int main() {
	int n, i;
	long long sum;
	while (scanf("%d", &n) != -1) {
		sum = 0;
		long long an = 1;
		for (i = 1; i <= n; i++) {
			an *= i;
			sum += an;
		}
		printf("%lld\n", sum);
	}
}