#include<iostream>
using ll=long long;
const ll mod=1e9+7;
const int maxn=3e3+9;//hdu 7095
ll stl[maxn][maxn];//第二类斯特林数
void init(){//stl[i][j] i个不同球放到j个相同盒，盒非空
	stl[0][0]=1;
	for(int i=1;i<maxn;i++) for(int j=1;j<maxn;j++)
		stl[i][j]=(stl[i-1][j-1]+j*stl[i-1][j])%mod;
}//第i个球单独放一个盒 + 第i个球放到前j个盒*j种
int n,m,t;
void solve(){
	std::cin>>n>>m;
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=stl[n][i]*stl[m][i-1]%mod;
		ans+=stl[n][i]*stl[m][i]*2%mod;
		ans+=stl[n][i]*stl[m][i+1]%mod;
	}
	std::cout<<ans%mod<<"\n";
}
int main(){
	init();
	//题目中盒不同，所以乘以盒的阶乘
	for(int i=1;i<maxn;i++)
		for(ll j=1,f=1;j<=i;j++,f=f*j%mod) 
			stl[i][j]=f*stl[i][j]%mod;
	for(std::cin>>t;t--;) solve();
}//如果盒可以为空，则答案是n个不同球放到1,2,3...,k个盒子里