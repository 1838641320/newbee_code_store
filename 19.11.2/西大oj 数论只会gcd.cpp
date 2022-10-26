#include<stdio.h>
#define swap(a,b) a^=b^=a^=b;
int main() {
	int T,turn;
	long long A,B;
	scanf("%d",&T);
	while(T--) {
		scanf("%lld%lld",&A,&B);
		turn=1;
		if(B>A) swap(A,B);
		while(A%B&&A<2*B) {
			A-=B;
			swap(A,B);
			turn=1-turn;
		}
		if(turn) puts("wula");
		else puts("mmp");
	}
}
