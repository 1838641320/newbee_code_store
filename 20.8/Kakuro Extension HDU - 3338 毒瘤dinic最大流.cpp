#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=2e4+9,inf=1e9;
int head[maxn],sz,dis[maxn];
struct {int nex,t,cap;} g[maxn*8];
void addedge(int f,int t,int cap){
	g[sz]={head[f],t,cap};
	head[f]=sz++;
	g[sz]={head[t],f,0};
	head[t]=sz++;
}
int Q[maxn];
int bfs(int s,int t){
	int l=0,r=0;Q[r++]=s;
	mem(dis,0);dis[s]=1;
	while(l<r) 
		for(int u=Q[l++],i=head[u];~i;i=g[i].nex){
			int v=g[i].t;
			if(g[i].cap&&!dis[v]){
				dis[v]=dis[u]+1;
				if(t==v) return 1;
				Q[r++]=v;
			}
		}
	return 0;
}
int dfs(int s,int t,int cap,int flow=0){
	if(s==t) return cap;
	for(int i=head[s];~i;i=g[i].nex){
		auto &e=g[i];
		if(dis[s]+1==dis[e.t]&&e.cap){
			int di=dfs(e.t,t,min(e.cap,cap-flow));
			if(di) flow+=di,
				e.cap-=di,g[i^1].cap+=di;
			else dis[e.t]=-9;
			if(flow==cap) break;
		}
	}
	return flow;
}
int dinic(int s,int t){
	int ans=0;
	while(bfs(s,t)) ans+=dfs(s,t,inf);
	return ans;
}
char grid[109][109]={};
int caps[109][109][2]={},c,l;
void solve(){
	mem(head,-1);sz=0;
	rep(i,0,l) rep(j,0,c){
		char in[9]={};
		scanf("%s",in);
		if(in[0]=='.') grid[i][j]=0;
		else{
			grid[i][j]=1;
			caps[i][j][0]=atoi(in);
			caps[i][j][1]=atoi(in+4);
		}
	}
	rep(i,0,l) for(int p=0,j=0;j<c;j++){
		if(grid[i][j]==0) 
			addedge(2*(i*c+p),2*(i*c+j),8),
			caps[i][p][1]--;
		else p=j;
	}
	rep(j,0,c) for(int p=0,i=0;i<l;i++){
		if(grid[i][j]==0) 
			addedge(2*(i*c+j),2*(p*c+j)+1,8),
			caps[p][j][0]--;
		else p=i;	
	}
	int s=2*c*l+1,t=2*c*l+2;
	rep(i,0,l) rep(j,0,c) if(grid[i][j]){
		if(caps[i][j][1]) 
			addedge(s,2*(i*c+j),caps[i][j][1]);
		if(caps[i][j][0]) 
			addedge(2*(i*c+j)+1,t,caps[i][j][0]);
	}
	dinic(s,t);
	rep(i,0,l) {
		rep(j,0,c){
			if(grid[i][j]) putchar('_');
			else for(int t=head[2*(i*c+j)];~t;t=g[t].nex){
				int ll=g[t].t/2/c,cc=g[t].t/2%c;
				if(g[t].t%2==0&&grid[ll][cc]) {
					printf("%d",g[t].cap+1);
					break;
				}
			}
			putchar(' ');
		}
		puts("");
	}
}
int main(){
	while(~scanf("%d%d",&l,&c)) solve();
}