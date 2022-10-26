#include<stdio.h>
main() {
	long long T,n,m;
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&n,&m);
		if (n%(m+1)) puts("YES");
		else puts("NO");
	}
}
