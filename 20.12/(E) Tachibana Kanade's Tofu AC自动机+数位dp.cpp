#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
template<class ty>void read(ty&a){
	a=0;int f=0,c=getchar();
	for(;!isdigit(c);c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+(c^48);
	if(f) a=-a;
}
template<class A,class ...B>void read(A&a,B&...b){read(a);read(b...);}
//---------------------------------------------------------------------
using namespace std;
const int maxn=209;
const ll mod=1e9+7;
int tr[maxn][22]={},fail[maxn]={},ed[maxn]={},sz=0;
int li[maxn]={},ri[maxn]={},L,R;
int n,m,k;
void insert(){
	int u=0,c,x,n;
	read(n);
	rep(i,0,n){
		read(c);
		if(!tr[u][c]) tr[u][c]=++sz;
		u=tr[u][c];
	}
	read(x);ed[u]+=x;
}
void build(){
	int Q[maxn],l=0,r=0;
	rep(k,0,m) if(tr[0][k])
		Q[r++]=tr[0][k];
	while(l<r){
		int u=Q[l++];
		ed[u]+=ed[fail[u]];
		rep(i,0,m){
			int ne=tr[u][i];
			if(ne)
				fail[ne]=tr[fail[u]][i],Q[r++]=ne;
			else 
				tr[u][i]=tr[fail[u]][i];
		}
	}
}
int dp[203][203][508];
int bi[maxn]={},len;
int dfs(int pos,int sta,int ki,int lim,int pre){
	if(pos==len) return ki<=k;
	int&D=dp[pos][sta][ki],res=0;
	if(D!=-1&&!lim&&!pre) return D;
	int up=lim?bi[pos]:m-1,i,t,kii;
	for(i=0;i<=up;i++){
		if(!pre||i) t=tr[sta][i],kii=ki+ed[t];
		else kii=ki,t=sta;
		if(kii<=k) res+=dfs(pos+1,t,kii,lim&&i==up,pre&&!i);
		res%=mod;
	}
	if(!lim&&!pre) D=res;
	return res;
}
int solve(int n,int *p,int f){
	mem(dp,-1);
	rep(i,0,n) bi[i]=p[i];
	len=n;
	int res=dfs(0,0,0,1,1)%mod;
	if(f) {
		int v=0,u=0;
		rep(i,0,n) u=tr[u][bi[i]],v+=ed[u];
		res-=v<=k;
	}
	return res;
}
int main(){
	read(n,m,k);
	read(L);rep(i,0,L) read(li[i]);
	read(R);rep(i,0,R) read(ri[i]);
	rep(i,0,n) insert();
	build();
	printf("%d\n",(solve(R,ri,0)-solve(L,li,1)+mod)%mod);
}