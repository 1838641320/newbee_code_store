#include<cstring>
#include<algorithm>
#include<iostream>
#define rep(i,a,b) for(int i=a,bb=b;i<bb;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
ll gcd(ll x,ll y){while(y^=x^=y^=x%=y);return x;}
using namespace std;
//-----------------
const int maxn=6e4+9;
int n,m;
char in[maxn]={};
int tr[maxn][2],sz,ed[maxn],fa[maxn];
int insert(char a[],int len,int ty){
	int u=0,c;
	rep(i,0,len){
		c=a[i]-'0';
		if(!tr[u][c]) tr[u][c]=sz++;
		u=tr[u][c];
	}
	if(ty) ed[u]=1;
	return u;
}
void init(){
	mem(tr,0),sz=1,mem(ed,0),mem(fa,0);
}
void build(){
	int q[maxn],l=0,r=0;
	rep(i,0,2) if(tr[0][i])
		q[r++]=tr[0][i];
	while(l<r){
		int u=q[l++];
		ed[u]|=ed[fa[u]];
		rep(i,0,2){
			int ne=tr[u][i];
			if(ne) fa[ne]=tr[fa[u]][i],q[r++]=ne;
			else tr[u][i]=tr[fa[u]][i];
		}
	}
}
int q[maxn],dis[maxn];
void bfs(int s){
	mem(dis,0x3f);
	int l=0,r=0;
	q[r++]=s;dis[s]=0;
	while(l<r){
		int v=q[l++];
		rep(i,0,2){
			int u=tr[v][i];
			if(ed[u]||dis[u]<=dis[v]+1) continue;
			dis[u]=dis[v]+1;
			q[r++]=u;
		}
	}
}
const int maxp=12;
int g[maxp][maxp],pos[maxp],dp[1<<maxp][maxp],len[maxp];
int TSP(){
	mem(dp,0x3f);
	for(int i=0;i<n;i++) dp[1<<i][i]=len[i];
	rep(i,0,1<<n) rep(j,0,n) 
		if(dp[i][j]<0x3f3f3f3f) {
			rep(k,0,n) if((i&(1<<k))==0)
				dp[i|(1<<k)][k]=min(dp[i|(1<<k)][k],dp[i][j]+g[j][k]);
	}
	return *min_element(dp[(1<<n)-1],dp[(1<<n)-1]+n);
}
int main(){
	while(scanf("%d%d",&n,&m),n|m){
		init();
		rep(i,0,n){
			scanf("%s",in);
			pos[i]=insert(in,len[i]=strlen(in),0);
		}
		rep(i,0,m){
			scanf("%s",in);
			insert(in,strlen(in),1);
		}
		build();
		rep(i,0,n){
			bfs(pos[i]);
			rep(j,0,n) g[i][j]=dis[pos[j]];
		}
		printf("%d\n",TSP());
	}
}