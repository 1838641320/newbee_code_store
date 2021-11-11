#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
char getc(){
	static char buf[1234567],*e=buf+1234567,*p=e;
	if(p==e) fread(buf,1,1234567,stdin),p=buf;
	return *p++;
	// return getchar();
}
template<class ty>
void read(ty&a){
	a=0;int c=getc(),f=0;
	while(!isdigit(c)) f|=c=='-',c=getc();
	while(isdigit(c)) a=a*10+(c^48),c=getc();
	if(f) a=-a;
}
template<class A,class ...B>
void read(A&a,B&...b){read(a);read(b...);}
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=3e3+9;
int n,m1,m2;
struct Edge{int w,t;};
vector<Edge> g[maxn];
bool check_neg(int least){
	int dis[maxn]={},cnt[maxn]={};
	bool inq[maxn]={};
	mem(dis,0x3f);
	queue<int> q;
	q.push(0);dis[0]=0;inq[0]=1;
	while(q.size()){
		int v=q.front();q.pop();
		inq[v]=0;
		for(auto e:g[v]){
			int u=e.t;
			if(dis[u]<=dis[v]+e.w) continue;
			dis[u]=dis[v]+e.w;
			cnt[u]=cnt[v]+1;
			if(cnt[u]>n) return 1;
			// if(dis[u]<0) return 1;
			if(inq[u]==0) inq[u]=1,q.push(u);
		}
	}
	return 0;
}
int op1[maxn][3],op2[maxn][3];
int check_build(int x){
	rep(i,0,n+1) {
		g[i].clear();
		if(i>0) g[i].push_back({0,i-1});
		if(i<n) g[i].push_back({1,i+1});
	}
	rep(i,0,m1){
		int b=op1[i][1],a=op1[i][0]-1,y=-op1[i][2];
		g[b].push_back({y,a});
	}
	rep(i,0,m2){
		int b=op2[i][1],a=op2[i][0]-1,y=x-op2[i][2];
		g[a].push_back({y,b});
	}
	g[0].push_back({x,n});
	g[n].push_back({-x,0});//d_n==d_0+x
	return !check_neg(x);
}
void solve(){
	read(n,m1,m2);
	rep(i,0,m1) rep(j,0,3) read(op1[i][j]);
	rep(i,0,m2) rep(j,0,3) read(op2[i][j]);
	int ub=n+1,lb=-1,mid;
	while(ub>lb+1){
		mid=(ub+lb)>>1;
		if(check_build(mid)) ub=mid;
		else lb=mid;
	}
	printf("%d\n",ub);
}
int main(){
	int t=1;
	read(t);
	while(t--) 
		solve();
}