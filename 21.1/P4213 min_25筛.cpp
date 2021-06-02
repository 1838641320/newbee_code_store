#include<iostream>
#include<algorithm>
#include<cstring>
#include<complex>
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
using namespace std;
const int maxn=1e6+9;
bool vis[maxn];
ll s1[maxn];
ll pr[maxn],pcnt;
void euler(){
	vis[1]=1;
	for(int i=2;i<maxn;i++){
		if(!vis[i]) pr[++pcnt]=i;
		for(int j=1;j<=pcnt;j++){
			ll x=pr[j];
			if(i*x>=maxn) break;
			vis[i*x]=1;
			if(i%x==0) break;
		}
	}
	pr[0]=1;
	for(int i=1;i<=pcnt;i++) 
		s1[i]=s1[i-1]+pr[i];
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
		for(int i=1;i<=gcnt;i++)
			g1[i]=gs[i]*(gs[i]+1)/2-1,
			g2[i]=gs[i]-1;
		for(int i=1;i<=pcnt&&pr[i]*pr[i]<=n;i++)
			for(int j=gcnt;pr[i]*pr[i]<=gs[j];j--){
				int t=id(gs[j]/pr[i]);
				g1[j]-=pr[i]*(g1[t]-s1[i-1]),
				g2[j]-=g2[t]-(i-1);
			}
	}
	ll h1(ll x,int i){
		if(pr[i]>x) return 0;
		ll res=g1[id(x)]-s1[i]-(g2[id(x)]-i);
		for(int j=i+1;pr[j]*pr[j]<=x;j++)
			for(ll v=pr[j];v<=x;v*=pr[j])
				res+=v/pr[j]*(pr[j]-1)*(h1(x/v,j)+(v>pr[j]));
		return res;
	}
	ll h2(ll x,int i){
		if(pr[i]>x) return 0;
		ll res=-g2[id(x)]+i;
		for(int j=i+1;pr[j]*pr[j]<=x;j++) 
			res+=-h2(x/pr[j],j);
		return res;
	}
}
int main(){
	euler();
	using namespace min_25;
	int t;scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		sn=sqrt(n);
		init();
		ll resa=h1(n,0),resb=h2(n,0);
		printf("%lld %lld\n",resa+1,resb+1);
	}
}