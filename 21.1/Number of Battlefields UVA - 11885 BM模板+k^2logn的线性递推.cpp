#include<iostream>
#include<algorithm>
#define rep(i,a,b) for(int i=a,_b_=b;i<(int)_b_;i++)
typedef long long ll;
using namespace std;
#include<queue>
const ll mod=1e9+7,mod2=987654321;
int p,n,m;
ll qpow(ll x,ll n){
	ll c=1;
	for(;n;n/=2,x=x*x%mod) if(n&1) c=c*x%mod;
	return c;
}//inital value,  length,     result
void BM(ll a[],int n,vector<ll>&ans){
	vector<ll> lst;ans.clear();
	ll dt=0,w=0;
	for(int i=1;i<=n;i++){
		ll tmp=0;
		rep(j,0,ans.size()) tmp=(tmp+a[i-1-j]*ans[j])%mod;
		if((a[i]-tmp)%mod==0) continue;
		if(!w){//mod must be prime
			w=i;dt=a[i]-tmp;
			for(int j=i;j;j--) ans.push_back(0);
			continue;
		}
		vector<ll> now=ans;
		ll mul=(a[i]-tmp)*qpow(dt,mod-2)%mod;
		if(ans.size()<lst.size()+i-w) 
			ans.resize(lst.size()+i-w);
		ans[i-w-1]=(ans[i-w-1]+mul)%mod;
		rep(j,0,lst.size())
			ans[i-w+j]=(ans[i-w+j]-mul*lst[j])%mod;
		if(now.size()-i<lst.size()-w){
			lst=now;w=i;dt=a[i]-tmp;
		}
	}
	for(ll&i:ans) i=(i%mod+mod)%mod;
}
void mul(vector<ll>&rec,ll a[],ll b[],int k){
	ll c[2*k]={};
	rep(i,0,k) rep(j,0,k) 
		c[i+j]=(c[i+j]+a[i]*b[j])%mod2;
	for(int i=k*2-2;i>=k;i--)
		for(int j=1;j<=k;j++)//use recursion to go back
			c[i-j]=(c[i-j]+rec[j]*c[i])%mod2;
	rep(i,0,k) a[i]=c[i];
}//   recursion   initial value   nth item
ll linear(vector<ll>&a,ll b[],ll n){
	int k=a.size()-1;ll res[2*k]={},c[2*k]={};
	c[1]=res[0]=1;
	for(;n;n/=2,mul(a,c,c,k))
		if(n&1) mul(a,res,c,k);
	ll ret=0;
	rep(i,0,k) ret=(ret+b[i]*res[i])%mod2;
	return ret;
}
int main(){
	ll ve[]={2,9,29,83,226,602,1588,4171,10935,28645,75012};
	vector<ll> ans;
	BM(ve,9,ans);
	for(ll&i:ans) if(i>mod-i) i=mod2-(mod-i);
	ans.insert(ans.begin(),0);
	ll n;
	while(scanf("%lld",&n),n){
		if(n&1||n<8) {puts("0");continue;}
		n=n/2-4;
		printf("%lld\n",linear(ans,ve,n));
	}
}