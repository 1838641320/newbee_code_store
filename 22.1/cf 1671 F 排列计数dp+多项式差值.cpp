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
	ll n,k;
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
}a[15][15];
ll dp[59][12][12][59]={};
ll ans[59][12][12]={};
vector<ll> rx[12][12],tp[12][12];
int n,x,k;
void solve(){
	cin>>n>>k>>x;
	if(n<=11) cout<<ans[n][k][x]<<"\n";
	else cout<<a[k][x].calc(n)<<"\n";
}
void add(ll&a,ll b){a+=b;a%=mod;}
int main(){
	dp[1][0][0][0]=1;
	for(int l=1;l<58;l++){
		for(int i=0;i<=11;i++)
			for(int j=0;j<=min(l,11);j++)for(int ls=0;ls<=l;ls++)if(dp[l][i][j][ls]){
				int v=dp[l][i][j][ls];
				for(int k=0;k<=l;k++){
					int a=i+l-k,b=j+(k<=ls);
					if(a<=11&&b<=11)
						add(dp[l+1][a][b][k],v);
				}
			}
	}
	for(int l=1;l<58;l++){
		for(int i=0;i<=11;i++)
			for(int j=0;j<=min(l,11);j++)
				for(int ls=0;ls<=l;ls++) add(ans[l][i][j],dp[l][i][j][ls]);
	}
	for(int i=0;i<=11;i++) for(int j=0;j<=11;j++){
		vector<ll> x(1),y(1);
		for(int k=0;k<12;k++) 
			x.push_back(k+11),y.push_back(ans[k+11][i][j]);
		a[i][j].main(x,y);
	}
	int t=1;
	cin>>t;
	while(t--)
		solve();
}