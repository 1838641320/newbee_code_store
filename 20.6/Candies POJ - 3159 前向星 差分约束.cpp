#include"s.h"
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn=30000+9,maxe=150009;
struct edge{ 
	int t,c,nex;
	edge(int t,int c,int nex):t(t),c(c),nex(nex){}
	edge(){}
} G[maxe];
typedef pair<int,int> pii;
int n,m,head[maxn],sz;
int dijkstra(){
	int d[maxn];memset(d,0x3f,sizeof d);
	priority_queue<pii,vector<pii>,greater<pii> > q;
	d[1]=0;q.push(pii(0,1));
	while(!q.empty()){
		int v=q.top().second,cv=q.top().first;q.pop();
		if(d[v]<cv) continue;
		for(int i=head[v];~i;i=G[i].nex){
			int u=G[i].t,w=G[i].c;
			if(d[u]>d[v]+w){
				d[u]=d[v]+w;
				q.push(pii(d[u],u));
			}
		}
	}
	return d[n];
}
int main(){
	memset(head,-1,sizeof head);
	sz=0;
	scanf("%d%d",&n,&m);
	while(m--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		G[sz]=edge(b,c,head[a]);
		head[a]=sz++;
	}
	printf("%d",dijkstra());
}
