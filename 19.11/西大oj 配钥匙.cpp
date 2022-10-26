#include<stdio.h>
int main() {
	int i, T, n, m, A, B,set_number,money;
	scanf("%d", &T);
	for (i = 1; i <= T; i++) {
		scanf("%d%d%d%d", &n, &m, &A, &B);
		set_number = n / m;
		if ((B / m) < A){
			money = set_number*B;
			n -= set_number*m;
			if ((B > A*n)&& (n != 0))
				money += n*A;
			else if (n != 0) money += B;
		}
		else money = n*A;
		printf("%d", money);
	}
}