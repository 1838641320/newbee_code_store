#include<iostream>
#include<algorithm>
#include<cstring>
#include<complex>
#define rep(i,a,b) for(int i=a,_b=b;i<_b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
template<class A>void read(A&a){
	a=0;int c=getchar(),f=0;
	for(;!isdigit(c);c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+(c^48);
	if(f) a=-a;
}
template<class A,class ...B>
void read(A&a,B&...b){read(a);read(b...);}
using namespace std;
//-------------------------------------------------
const ll mod=1e9+7;
const int maxn=1e6+9;
const __int128_t o=1;
ll qpow(ll x,ll n){
	ll c=1;
	for(;n;n/=2,x=x*x%mod) if(n&1) c=c*x%mod;
	return c;
}
const ll inv2=qpow(2,mod-2),inv6=qpow(6,mod-2);
bool vis[maxn];
ll s1[maxn],s2[maxn];
ll pr[maxn],pcnt;
void euler(){
	vis[1]=1;
	for(int i=2;i<maxn;i++){
		if(!vis[i]) pr[++pcnt]=i;
		for(int j=1;j<=pcnt;j++){
			ll x=pr[j];
			if(x*i>=maxn) break;
			vis[i*x]=1;
			if(i%x==0) break;
		}
	}
	for(int i=1;i<=pcnt;i++)
		s1[i]=(s1[i-1]+pr[i])%mod,
		s2[i]=(s2[i-1]+pr[i]*pr[i])%mod;
}
namespace min_25{
	ll n,sn;
	ll gs[maxn*2],gcnt;
	int id(ll x){return x<=sn?x:gcnt+1-n/x;}
	ll g1[maxn*2],g2[maxn*2];
	void init(){
		gcnt=0;
		for(ll l=1;l<=n;l=n/(n/l)+1) gs[++gcnt]=n/l;
		reverse(gs+1,gs+1+gcnt);
		for(ll i=1;i<=gcnt;i++){
			g1[i]=(o*gs[i]*(gs[i]+1)*inv2+mod-1)%mod,
			g2[i]=(o*gs[i]*(gs[i]+1)%mod*(2*gs[i]+1)
				*inv6+mod-1)%mod;
		}
		for(int i=1;i<=pcnt&&pr[i]*pr[i]<=n;i++)
			for(int j=gcnt;pr[i]*pr[i]<=gs[j];j--){
				int t=id(gs[j]/pr[i]);
				g1[j]-=pr[i]*(g1[t]-s1[i-1])%mod;
				g2[j]-=pr[i]*pr[i]%mod*(g2[t]-s2[i-1])%mod;
				g1[j]=(g1[j]%mod+mod)%mod;
				g2[j]=(g2[j]%mod+mod)%mod;
			}
	}
	ll h(ll x,int i){
		if(pr[i]>x) return 0;
		ll res=g2[id(x)]-s2[i]-(g1[id(x)]-s1[i]);
		res=(res%mod+mod)%mod;
		for(int j=i+1;pr[j]*pr[j]<=x;j++)
			for(ll v=pr[j];v<=x;v*=pr[j]){
				res+=(o*v*(v-1))*(h(x/v,j)+(v>pr[j]))%mod,
				res%=mod;
			}
		return res;
	}
}
int main(){
	using namespace min_25;
	euler();
	scanf("%lld",&n);
	sn=sqrt(n);
	init();
	printf("%lld\n",(h(n,0)+1)%mod);
}