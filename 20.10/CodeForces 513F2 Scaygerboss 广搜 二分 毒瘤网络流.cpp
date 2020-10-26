#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
ll gcd(ll x,ll y){while(y^=x^=y^=x%=y);return x;}
using namespace std;
//-----------------
const int maxn=2e3+9,dx[]={0,0,1,-1},dy[]={1,-1,0,0};
struct {int nex,t,cap;}g[maxn*800]={};
int head[maxn],sz,iter[maxn],dis[maxn];
void addedge(int f,int t,int cap){
	g[sz]={head[f],t,cap};
	head[f]=sz++;
	g[sz]={head[t],f,0};
	head[t]=sz++;
}
int Q[maxn];
int bfs(int s,int t){
	int l=0,r=0;Q[r++]=s;
	mem(dis,0);dis[s]=1;iter[s]=head[s];
	while(l<r)
		for(int u=Q[l++],i=head[u];~i;i=g[i].nex){
			int v=g[i].t;
			if(g[i].cap&&!dis[v]){
				dis[v]=dis[u]+1;
				iter[v]=head[v];
				if(t==v) return 1;
				Q[r++]=v;
			}
		}
	return 0;
}
int dfs(int s,int t,int cap,int flow=0){
	if(s==t) return cap;
	for(int &i=iter[s];~i;i=g[i].nex){
		auto &e=g[i];
		if(e.cap&&dis[e.t]==dis[s]+1){
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
	while(bfs(s,t)) ans+=dfs(s,t,99999);
	return ans;
}
int n,m,ma,fe,vtx;
char mp[25][25]={};
struct pii{ll x,y;}peo[2][500];
ll ti[2][500]={};
vector<pii> dis2[2][500];
void bfs2(int ty,int in){
	int dis[25][25]={};mem(dis,-1);
	int nx=peo[ty][in].x-1,ny=peo[ty][in].y-1,x,y;
	auto &dis3=dis2[ty][in];
	queue<int> Q;
	Q.push(nx*m+ny);
	dis[nx][ny]=0;
	dis3.push_back({nx*m+ny,0});
	while(Q.size()){
		nx=Q.front()/m,ny=Q.front()%m;Q.pop();
		rep(i,0,4){
			x=nx+dx[i],y=ny+dy[i];
			if(x<0||y<0||x>=n||y>=m
				||mp[x][y]!='.'||~dis[x][y]) continue;
			dis[x][y]=dis[nx][ny]+1;
			dis3.push_back({x*m+y,dis[x][y]*ti[ty][in]});
			Q.push(x*m+y);
		}
	}
}
int s=2001,t=2002,mal=0,gd1=500,gd2=1000,fem=1500;
int judge(ll ans){
	mem(head,-1),sz=0;
	int flows=0;
	rep(i,0,vtx) addedge(s,mal+i,1);
	rep(i,0,vtx) addedge(fem+i,t,1);
	rep(i,0,n*m) addedge(gd1+i,gd2+i,1);
	rep(i,0,vtx) for(auto &j:dis2[0][i]){
		if(j.y<=ans) addedge(mal+i,gd1+j.x,1);
	}
	rep(i,0,vtx) for(auto &j:dis2[1][i]){
		if(j.y<=ans) addedge(gd2+j.x,fem+i,1);
	}
	return dinic(s,t)>=vtx;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&ma,&fe);
	rep(i,0,n) scanf("%s",mp[i]);
	int ox,oy,ot;
	scanf("%d%d%d",&ox,&oy,&ot);
	rep(i,0,ma) 
		scanf("%d%d%d",&peo[0][i].x,&peo[0][i].y,&ti[0][i]);
	rep(i,0,fe) 
		scanf("%d%d%d",&peo[1][i].x,&peo[1][i].y,&ti[1][i]);
	if(ma>fe)
		peo[1][fe]={ox,oy},ti[1][fe++]=ot;
	else
		peo[0][ma]={ox,oy},ti[0][ma++]=ot;
	if(ma!=fe) 
		return puts("-1"),0;
	vtx=ma;
	rep(i,0,vtx) bfs2(0,i);
	rep(i,0,vtx) bfs2(1,i);
	ll lb=-1,ub=1e13,mid;
	while(ub>lb+1){
		mid=lb+ub>>1;
		if(judge(mid)) ub=mid;
		else lb=mid;
	}
	if(ub==(ll)1e13) puts("-1");
	else printf("%lld\n",ub);
}