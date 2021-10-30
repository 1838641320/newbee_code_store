#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#include<queue>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=1e5+9;
vector<int> g[maxn];
int lx[maxn],ly[maxn],dx[maxn],dy[maxn],dis;
int lsz;
int q[maxn*2];
int bfs(){
	mem(dx,-1),mem(dy,-1);
	int l=0,r=0;dis=1e9;
	rep(x,0,lsz) if(lx[x]==-1)
		q[r++]=x,dx[x]=0;
	while(l<r){
		int x=q[l++];
		if(dx[x]>dis) break;
		for(int y:g[x]){
			if(dy[y]!=-1) continue;
			dy[y]=dx[x]+1;
			if(ly[y]==-1) dis=dy[y];
			else dx[ly[y]]=dy[y]+1,q[r++]=ly[y];
		}
	}
	return dis!=1e9;
}
bool vis[maxn];
int dfs(int x){
	for(int y:g[x]){
		if(vis[y]||dy[y]!=dx[x]+1) continue;
		vis[y]=1;
		if(ly[y]!=-1&&dy[y]>dis) break;
		if(ly[y]==-1||dfs(ly[y]))
			return ly[y]=x,lx[x]=y,1;
	}
	return 0;
}
int hk(int lsz_){
	lsz=lsz_;int ans=0;
	mem(lx,-1),mem(ly,-1);
	while(bfs()){
		mem(vis,0);
		rep(x,0,lsz) if(lx[x]==-1&&dfs(x)) ans++;
	}
	return ans;
}
bool ban[maxn];
int m,n,s;
int sum(int x){
	int ret=0;
	while(x) ret+=x%10,x/=10;
	return ret&1;
}
int sum(int a[]){
	int ret=0;
	for(int i=m-1;i>=0;i--) 
		ret=ret*10+a[i];
	return ret;
}
void build(){
	int b[8]={};
	rep(i,0,n) g[i].clear();
	rep(i,0,n)if(sum(i)&&!ban[i]){
		int p10=1;
		rep(j,0,m) {
			b[j]=i/p10%10;
			p10*=10;
		}
		rep(j,0,m) {
			b[j]=(b[j]+1)%10;
			int t=sum(b);
			if(!ban[t]&&!sum(t))
				g[i].push_back(t);
			b[j]=(b[j]+8)%10;
			t=sum(b);
			if(!ban[t]&&!sum(t))
				g[i].push_back(t);
			b[j]=(b[j]+1)%10;
		}
	}
}
void solve(){
	mem(ban,0);
	scanf("%d%d%d",&m,&n,&s);
	rep(i,0,n){
		int x;scanf("%d",&x);
		ban[x]=1;
	}
	n=1;
	rep(i,0,m) n*=10;
	build();
	// rep(i,0,n)if(g[i].size()){
	// 	printf("%d :",i);
	// 	for(int j:g[i]) printf("%d ",j);
	// 	puts("");
	// }
	int f1=hk(n);
	ban[s]=1;
	build();
	int f2=hk(n);
	if(f1==f2) puts("Bob");
	else puts("Alice");
}
int main(){
	int t=1;
	scanf("%d",&t);
	while(t--) 
		solve();
}