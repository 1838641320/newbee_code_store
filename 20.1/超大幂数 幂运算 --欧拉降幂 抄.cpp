#include <stdio.h>
typedef unsigned long long ull;
ull mul(ull a, ull b, ull c){
	ull res = 0, tmp = a % c;
	while (b){
		if (b & 1 && (res += tmp) >= c)
			res -= c;
		if ((tmp <<= 1) >= c)
			tmp -= c;
		b >>= 1;
	}
	return res;
}
int main(){
	ull a, b, c, y;
	while (scanf("%llu %llu %llu", &a, &b, &c) != EOF){
		y = 1;
		while (b){
			if (b & 1) y = mul(y, a, c);
			a = mul(a, a, c);
			b >>= 1;
		}
		printf("%llu\n", y % c);
	}
}
