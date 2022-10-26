#include<stdio.h>
#include<string.h>
#define hannuota3
typedef long long ll;
ll n,count[99]={0};
#ifdef hannuota3
void hanio(ll n,ll* count_addr){
	if(n==1) count_addr[1]+=2;
	/*else if(count_addr[n-1]){
		count_addr[n]+=count_addr[n-1];
	}*/
	else {
		hanio(n-1,count_addr);
		count_addr[1]++;
		hanio(n-1,count_addr);
		count_addr[1]++;
		hanio(n-1,count_addr);
	};
}
#endif
#ifdef hannuota1
ll hanio(ll a,ll b,ll c,ll* count_addr){
	if(a==1) {
		(*count_addr)++;
	}
	else {
		hanio(a-1,0,0,count_addr);
		(*count_addr)++;
		hanio(a-1,0,0,count_addr);
	};
}
#endif
int main(){
	while(~scanf("%lld",&n)&&~n) {
		memset(count,0,99*8);
		#ifdef hannuota3
		hanio(n,count);
		#endif
		#ifdef hannuota1
		hanio(n,0,0,count);
		#endif
		printf("%lld",count[1]);
		puts("");
	}
}
