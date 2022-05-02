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
namespace linear{
ll qpow(ll x,ll n){
	ll c=1;
	for(;n;n/=2,x=x*x%mod) if(n&1) c=c*x%mod;
	return c;
}//              inital value
vector<ll> BM(const vector<ll>&s){
	int n=s.size(),L=0,m=0;
	vector<ll> C(n),B(n),T;
	C[0]=B[0]=1;
	ll b=1,d;
	for(int i=0;i<n;i++){
		m++;d=s[i];
		for(int j=1;j<=L;j++) 
			d=(d+C[j]*s[i-j])%mod;
		if(!d) continue;
		T=C;ll coef=d*qpow(b,mod-2)%mod;
		for(int j=m;j<n;j++) 
			C[j]=(C[j]+mod-coef*B[j-m]%mod)%mod;
		if(2*L>i) continue;
		L=i+1-L;B=T,b=d;m=0;
	}
	C.resize(L+1),C[0]=0;
	for(ll&i:C) i=(mod-i%mod)%mod;
	return C;
}
void mul(vector<ll>&rec,ll a[],ll b[],int k){
	ll c[2*k]={};
	rep(i,0,k) rep(j,0,k) 
		c[i+j]=(c[i+j]+a[i]*b[j])%mod;
	for(int i=k*2-2;i>=k;i--)
		for(int j=1;j<=k;j++)//use recursion to go back
			c[i-j]=(c[i-j]+rec[j]*c[i])%mod;
	rep(i,0,k) a[i]=c[i];
}//   recursion   initial value   nth item
ll linear(vector<ll>&a,vector<ll>&b,ll n){
	int k=a.size()-1;k=max(k,2);
	ll res[2*k]={},c[2*k]={},ret=0;
	c[1]=res[0]=1;
	for(;n;n/=2,mul(a,c,c,k))
		if(n&1) mul(a,res,c,k);
	rep(i,0,k) ret=(ret+b[i]*res[i])%mod;
	return ret;
}
}
ll dp[59][12][12][59]={};
ll ans[59][12][12]={};
vector<ll> rx[12][12],tp[12][12];
int n,x,k;
void solve(){
	cin>>n>>k>>x;
	cout<<linear::linear(rx[k][x],tp[k][x],n)<<"\n";
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
		for(int k=0;k<50;k++) tp[i][j].push_back(ans[k][i][j]);
		rx[i][j]=linear::BM(tp[i][j]);
	}
	int t=1;
	cin>>t;
	while(t--)
		solve();
}