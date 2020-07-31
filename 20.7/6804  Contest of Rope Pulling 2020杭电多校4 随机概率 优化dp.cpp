#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn=1e3+9,mid=4.5e4+9;
struct {int f,b;} vec[maxn*2];
int n,m,f,b,sz;
long long dp[mid*2];
void solve(){
	memset(dp,0xac,sizeof dp);
	scanf("%d%d",&n,&m);
	sz=0;
	memset(vec,0,sizeof vec);
	rep(i,0,n)
		scanf("%d%d",&f,&b),vec[sz++]={f,b};
	rep(i,0,m)
		scanf("%d%d",&f,&b),vec[sz++]={-f,b};
	random_shuffle(vec,vec+sz);
	int top=mid*2;dp[mid]=0;
	rep(i,0,sz){
		f=vec[i].f;b=vec[i].b;
		if(f>0) for(int j=top-1;j>f;j--) 
			dp[j]=max(dp[j],dp[j-f]+b);
		else for(int j=0;j<top+f;j++) 
			dp[j]=max(dp[j],dp[j-f]+b);
	}
	printf("%lld\n",dp[mid]);
}
int main(){
	int t;scanf("%d",&t);
	while(t--) solve();
}