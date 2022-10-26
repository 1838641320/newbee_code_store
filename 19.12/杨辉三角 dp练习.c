#include<stdio.h>
typedef long long ll;
ll f[200][200]= {0},n;
ll Pascal(int a,int b) {
	if(a==b||!b) return (f[a][b]=1);
	else return f[a][b]?f[a][b]:(f[a][b]=Pascal(a-1,b)+Pascal(a-1,b-1));
}
int main() {
	while(~scanf("%lld",&n))
		for(int i=0; i<n; i++) {
			for(int j=0; j<i; j++) {
				printf("%lld ",Pascal(i,j));
			}
			printf("%lld\n",Pascal(i,i));
		}
}
