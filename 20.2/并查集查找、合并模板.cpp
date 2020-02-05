#include<cstdio>
constexpr int mod=1e9+7,maxn=666;
typedef long long ll;
int p[maxn];
ll PowerMod(ll a,int n,ll c=1){ for(; n; n>>=1,a=a*a%mod) if(n&1) c=c*a%mod; return c; }
int ancestor(int x){ return p[x]==x?x:(p[x]=ancestor(p[x])); }
int Union(int x,int y){
	if((x=ancestor(x))==(y=ancestor(y))) return 1;
	return p[x]=y,0;
}
int main(ll a,ll b){
	for(;~scanf("%lld%lld",&a,&b);)printf("%lld\n",PowerMod(a,b));
}