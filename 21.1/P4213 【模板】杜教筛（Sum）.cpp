#include<iostream>
#include<algorithm>
#include<cstring>
#include<complex>
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
#include<vector>
#include<unordered_map>
using namespace std;
const int maxn=6e6+9;
bool vis[maxn];
int mu[maxn],phi[maxn];
vector<int> pri;
ll sum_mu[maxn],sum_phi[maxn];
void euler(){
	vis[1]=vis[0]=1;
	mu[1]=1;phi[1]=1;
	for(int i=2;i<maxn;i++){
		if(!vis[i]) {
			pri.push_back(i);
			mu[i]=-1;phi[i]=i-1;
		}
		for(int j:pri){
			if(j*i>=maxn) break;
			vis[j*i]=1;
			if(i%j){//gcd==1
				mu[i*j]=-mu[i];
				phi[i*j]=phi[i]*(j-1);
			}
			else {
				phi[i*j]=phi[i]*j;
				break;
			}
		}
	}
	for(int i=1;i<maxn;i++) 
		sum_mu[i]=sum_mu[i-1]+mu[i],
		sum_phi[i]=sum_phi[i-1]+phi[i];
}
unordered_map<ll,ll> mp_mu;
ll S_mu(ll x){//miu * 1
	if(x<maxn) return sum_mu[x];
	if(mp_mu.count(x)) return mp_mu[x];
	ll res=1;
	for(ll l=2,r;l<=x;l=r+1){
		r=x/(x/l);
		res-=(r-l+1)*S_mu(x/l);
	}
	return mp_mu[x]=res;
}
unordered_map<ll,ll> mp_phi;
ll S_phi(ll x){//phi * 1
	if(x<maxn) return sum_phi[x];
	if(mp_phi.count(x)) return mp_phi[x];
	ll res=x*(x+1)/2;
	for(ll l=2,r;l<=x;l=r+1){
		r=x/(x/l);
		res-=(r-l+1)*S_phi(x/l);
	}
	return mp_phi[x]=res;
}
int main(){
	euler();
	int __t;scanf("%d",&__t);
	while(__t--){
		ll n;
		scanf("%lld",&n);
		printf("%lld %lld\n",S_phi(n),S_mu(n));
	}
}