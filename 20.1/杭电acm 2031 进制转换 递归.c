#include<stdio.h>
typedef long long ll;
t(ll N,ll R) {
	if(N) {
		t(N/R,R);
		putchar(N%R>9?N%R-10+'A':N%R+'0');
	}
}
int main(ll N,ll R) {
	while(~scanf("%lld%lld",&N,&R)) {
		if(N<0) {
			putchar('-');
			N=-N;
		}
		t(N,R);
		puts("");
	}
}
