#include<stdio.h>
typedef long long ll;
ll n,i=1,save[40][40];
ll route(ll x,ll y){
	if(y>x) return 0;
	if(save[x][y]) return save[x][y];
	if(x&&y) return (save[x][y-1]=route(x,y-1))+(save[x-1][y]=route(x-1,y));
	if(x&&!y) return (save[x-1][y]=route(x-1,y));
	if(!x&&y) return (save[x][y-1]=route(x,y-1));
	return 1;
}
int main(){
	route(36,36);
	while(scanf("%lld",&n)&&~n) printf("%lld %lld %lld\n",i++,n,2*save[n][n]);
}
