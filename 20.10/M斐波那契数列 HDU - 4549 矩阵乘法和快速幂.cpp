#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
template<class ty>void read(ty&a){
	a=0;int f=0,c=getchar();
	for(;!isdigit(c)&&~c;c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+(c^48);
	if(f) a=-a;
}
template<class a,class ...b>void read(a&A,b&...B){read(A);read(B...);}
//-----------------------
#include<vector>
using std::vector;
const ll mod=1000000007,mod2=mod-1;
typedef vector<ll> vec;
typedef vector<vec> mat;
mat mul(mat&a,mat&b){
	int la=a.size(),lb=a[0].size(),lc=b[0].size();
	mat c(la,vec(lc));
	rep(i,0,la) rep(k,0,lb) 
		if(a[i][k]) rep(j,0,lc) 
			c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod2;
	return c;
}
mat qpow(mat a,ll n){
	mat c(a.size(),vec(a.size()));
	rep(i,0,a.size()) c[i][i]=1;
	for(;n;n/=2,a=mul(a,a)) 
		if(n&1) c=mul(c,a);
	return c;
}
ll qpow(ll x,ll n){
	ll c=1;
	for(x%=mod;n;n/=2,x=x*x%mod) if(n&1) c=c*x%mod;
	return c;
}
ll a,b,n;
int main(){
	mat res(2,vec(2));
	while(~scanf("%lld%lld%lld",&a,&b,&n)){
		res[0][0]=res[0][1]=1;
		res[1][0]=1;res[1][1]=0;
		if(n==0) {printf("%lld\n",a%mod);continue;}
		res=qpow(res,n);
		printf("%lld\n",qpow(b,res[1][0])*qpow(a,res[1][1])%mod);
	}
}