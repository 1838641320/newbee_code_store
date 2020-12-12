#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
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
#include<queue>
using namespace std;
const int maxn=8e2+9,dd[4][2]={1,0,0,1,-1,0,0,-1};
char s[maxn][maxn]={};
struct pii{int x,y;};
int n,m,mintime,timetag;
pii a,b,c,d;
char vis[2][maxn][maxn];
queue<pii> qa,qb;
int check(int x,int y,int ty){
	if(x<0||y<0||x>=n||y>=m||vis[ty][x][y]||s[x][y]=='X') return 0;
	return 1;
}
int ch1(int x,int y){
	if(abs(x-c.x)+abs(y-c.y)<=2*timetag) return 0;
	if(abs(x-d.x)+abs(y-d.y)<=2*timetag) return 0;
	return 1;
}
void go(pii n,int ty,queue<pii>&q){
	if(!ch1(n.x,n.y)) return;
	for(auto i:dd) {
		int dx=n.x+i[0],dy=n.y+i[1];
		if(check(dx,dy,ty)) {
			q.push({dx,dy});
			vis[ty][dx][dy]=1;
			if(ch1(dx,dy)&&vis[ty^1][dx][dy]) {mintime=timetag;return;}
		}
	}
}
int bfs(){
	mem(vis,0);
	while(qa.size()) qa.pop();
	while(qb.size()) qb.pop();
	qa.push(a),qb.push(b);
	vis[0][a.x][a.y]=1,vis[1][b.x][b.y]=1;
	timetag=1;
	while(qa.size()&&qb.size()){
		rep(tt,0,3) for(int b=qa.size();b--;){
			auto pa=qa.front();qa.pop();
			go(pa,0,qa);
			if(mintime!=-1) return mintime;
		}
		for(int b=qb.size();b--;){
			auto pb=qb.front();qb.pop();
			go(pb,1,qb);
			if(mintime!=-1) return mintime;
		}
		timetag++;
	}
	return -1;
}
void solve(){
	mintime=-1;
	scanf("%d%d",&n,&m);
	rep(i,0,n) scanf("%s",s[i]);
	rep(i,0,n) rep(j,0,m){
		if(s[i][j]=='D') d={i,j};
		if(s[i][j]=='C') c={i,j};
		if(s[i][j]=='A') a={i,j};
		if(s[i][j]=='B') b={i,j};
	}
	printf("%d\n",bfs());
}
int main(){
	int t;scanf("%d",&t);
	while(t--) solve();
}