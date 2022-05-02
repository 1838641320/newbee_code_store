#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#include<queue>
#include<numeric>
typedef long long ll;
const ll mod=998244353;

ll qpow(ll x,ll n,ll c=1){
	for(;n;n/=2,x=x*x%mod) if(n&1) c=c*x%mod;
	return c;
}
struct chazhi{
	ll n;
	vector<ll> res;
	ll calc(ll x){
		ll ret=0,var=1;
		for(ll i=0;i<n;var=var*x%mod,i++)
			ret=(ret+var*res[i])%mod;
		return ret;
	}
	void main(vector<ll> x,vector<ll> y){//index from 1
		n=x.size()-1;
		vector<ll> tp(n+1),inv(n+1),num(n+1);
		res.resize(n+1);
		num[0]=1;
		for(ll i=1;i<=n;swap(num,tp),i++){
			tp[0]=0;inv[i]=qpow(mod-x[i],mod-2);
			for(ll j=1;j<=i;j++) tp[j]=num[j-1];
			for(ll j=0;j<=i;j++) tp[j]=(tp[j]+num[j]*(mod-x[i]))%mod;
		}
		for(ll i=1;i<=n;i++) {
			ll den=1,ls=0;
			for(ll j=1;j<=n;j++)
				if(i!=j) den=den*(x[i]-x[j]+mod)%mod;
			den=y[i]*qpow(den,mod-2)%mod;
			for(ll j=0;j<n;j++){
				tp[j]=(num[j]-ls+mod)*inv[i]%mod;
				res[j]=(res[j]+den*tp[j])%mod;
				ls=tp[j];
			}
		}
	}
};
void solve(){
	int n,k;
	cin>>n>>k;
	vector<ll> x(1),y(1);
	for(int i=1;i<=n;i++){
		int xi,yi;cin>>xi>>yi;
		x.push_back(xi);
		y.push_back(yi);
	}
	chazhi func;func.main(x,y);
	cout<<func.calc(k);
}
int main(){
	int t=1;
	// cin>>t;
	while(t--)
		solve();
}