#include<stdio.h>
typedef long long ll;
int main(){
	ll n,R,maxR=0,i,round_sum=0;
	scanf("%lld",&n);
	for(i=0;i<n;i++){
		scanf("%lld",&R);
		if(R>maxR) maxR=R;
		round_sum+=R;
	}
	if(round_sum<=(n-1)*(maxR)) printf("%lld",maxR);
	else printf("%lld",(round_sum-1)/(n-1)+1);
}
