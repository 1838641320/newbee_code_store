#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
template<class ty>void read(ty&a){
	a=0;int f=0,c=getchar();
	for(;~c&&!isdigit(c);c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+(c^48);
	if(f) a=-a;
}
template<class A,class ...B>void read(A&a,B&...b){read(a);read(b...);}
//---------------------------------------------------------------------
#include<queue>
using namespace std;
const ll mod=1e9+7;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll n,k;
ll qpow(ll x,ll n){
	ll c=1;
	for(x%=mod;n;n/=2,x=x*x%mod) if(n&1) c=c*x%mod;
	return c;
}
namespace linear_seq{
	int N;
	void mul(mat&a,mat&b){
		mat c(N,vec(N));
		rep(i,0,N) rep(j,0,N) rep(k,0,N)
			(c[i][j]+=a[i][k]*b[k][j])%=mod;
		a=c;
	}
	void qpow(mat&a,ll n){
		mat gg(N,vec(N));rep(i,0,N) gg[i][i]=1;
		for(;n;n/=2,mul(a,a)) if(n&1) mul(gg,a);
		a=gg;
	}
	vec gao(vec xn){
		N=xn.size()/2;
		mat dt(N,vec(N));
		rep(i,0,N) rep(j,0,N) dt[i][j]=xn[i+j];
		int r=0,p=r;
		for(;r<N;r++){
			for(p=r;p<N;p++) if(dt[p][r]) break;
			if(p==N) break;
			swap(dt[p],dt[r]);
			ll ap=::qpow(dt[r][r],mod-2);
			rep(j,r,N) dt[r][j]=dt[r][j]*ap%mod;
			rep(i,0,N) if(i!=r){
				ap=dt[i][r];
				rep(j,r,N) dt[i][j]=((dt[i][j]-dt[r][j]*ap)%mod+mod)%mod;
			}
		}
		vec res;
		rep(i,0,r) res.push_back(dt[r-1-i][r]);
		return res;
	}
	ll solve(vec an,ll n){
		vec res=gao(an);
		N=res.size();
		if(n<N) return an[n-1];
		else {
			mat init(N,vec(N));
			rep(i,0,N) init[0][i]=res[i];
			rep(i,1,N) init[i][i-1]=1;
			qpow(init,n-N);
			ll sum=0;
			for(int i=0;i<N;i++) sum=(sum+init[0][i]*an[N-1-i])%mod;
			return sum;
		}
	}
}
ll f[30][30]={};
ll F(ll n,ll k){
    if(n==1) return 1;
    if(f[n][k]) return f[n][k];
    ll res=0;
    for(int i=1;i<n;i++) res+=F(i,k);
    return f[n][k]=(res+qpow(n,k))%mod;
}
int main(){
	while(~scanf("%lld%lld",&n,&k)){
		vec tt;
		rep(i,1,30) tt.push_back(F(i,k));
		printf("%lld\n",linear_seq::solve(tt,n));
	}
}