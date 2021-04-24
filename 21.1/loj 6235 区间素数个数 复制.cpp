#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=6e6;
bool p[maxn+5];
int np[maxn/10+5],ps;
int mnp[maxn+5];
int mu[maxn+5],pi[maxn+5];
void make_prime(int n){
	p[0]=p[1]=1; mu[1]=1; mnp[1]=1<<30;
	for(int i=2;i<=n;i++){
		pi[i]=pi[i-1];
		if(!p[i]) mnp[i]=np[++ps]=i,mu[i]=-1,pi[i]++;
		for(int j=1;i*np[j]<=n;j++){
			p[i*np[j]]=1; mnp[i*np[j]]=np[j];
			if(i%np[j]) mu[i*np[j]]=-mu[i];
			else break;
		}
	}
}
ll x,ans;
int x2;
int g[maxn+5];
int main(){
	scanf("%lld",&x);
	x2=(int)sqrt(x*1.0);
	make_prime(x2);
	ans=pi[x2]-1;
	for(int i=1;i<=x2;i++) g[i]=i;
	for(int i=1;i<=x2;i++) ans+=mu[i]*(x/i);
	for(int i=1;i<=ps;i++){
		ll tx=x/np[i];
		if(1ll*np[i]*np[i]<=x2){
			for(int j=x2/np[i]+1;j<=x2;j++){
				if(mnp[j]<=np[i]||mu[j]==0) continue;
				ans-=mu[j]*(g[tx/j]-i+1);
			}
			for(int j=x2;j>=np[i]*np[i];j--) g[j]-=g[j/np[i]]-i;
			continue;
		}
		for(int j=i+1;j<=ps;j++){
			if(tx/np[j]<np[i]) break;
			ans+=pi[tx/np[j]]-i+2;
		}
		int l=max((int)(tx/np[i]),np[i]);
		ans+=pi[x2]-pi[l];
	}
	printf("%lld\n",ans);
	return 0;
}