#include<stdio.h>
#include<math.h>
int main() {
	int a, b, k, not_prime, i, ti;
	scanf("%d%d", &a, &b);
	if (a > b) a ^= b ^= a ^= b;
	for (i = a; i <= b; i++) {
		not_prime = 0;
		ti = i;
		printf("%d=", i);
		for (k = 2; k < ti &&k <= i / 2;) {
			if (ti%k == 0) {
				not_prime++;
				if (not_prime == 1) printf("%d", k);
				else printf("*%d", k);
				ti /= k;
			}
			else k++;
			if (not_prime == 0 && k > sqrt(i)) break;
		}
		if (not_prime) printf("*%d\n", k);
		else printf("%d\n", i);
	}
}
