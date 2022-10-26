#include<stdio.h>
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main() {
	int a,p,n;
	while (~scanf("%d%d", &n,&p)) {
		while(--n) {
			scanf("%d", &a);
			p *= a/gcd(p,a);
		}
		printf("%d\n", p);
	}
}
