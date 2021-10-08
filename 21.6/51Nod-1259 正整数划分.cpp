#include<iostream>
#include<algorithm>
#include<cstring>
#include<complex>
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn=1e5+9;
const ll mod=1e9+7;
ll dp[maxn];int n=100000;
void solve(){//51Nod-1259
	dp[0]=1;
	for(int i=1;i<=n;i++) for(int j=1;;j++){
		if(i>=j*(j*3-1)/2)
			dp[i]=(dp[i]+((j&1)*2-1)*dp[i-j*(j*3-1)/2]+mod)%mod;
		if(i>=j*(j*3+1)/2)
			dp[i]=(dp[i]+((j&1)*2-1)*dp[i-j*(j*3+1)/2]+mod)%mod;
		else break;
	}//dp[i]:=i个相同物品划分成不超过i组(正整数可重拆分)
}
void solve2(){
	const int n=1000;
	long long dp[n+1][n+1];dp[0][0]=1;
	for(int i=1;i<=n;i++) for(int j=0;j<=n;j++){
		dp[i][j]=dp[i-1][j];
		if(j>=i)(dp[i][j]+=dp[i][j-i])%=mod;
	}//dp[i][j]:=j个相同物品划分成不超过i组
	//如果要求j的i划分，做差分即可
	//j个相同球放到i个相同盒子，有无空盒
}
int main(){
	solve();
	scanf("%d",&n);
	printf("%lld\n",dp[n]);
}