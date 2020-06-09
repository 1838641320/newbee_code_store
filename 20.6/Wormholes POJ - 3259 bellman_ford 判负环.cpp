//#include"s.h"
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=500+9;
typedef long long ll;
int n,m,w;
struct Edge{ 
	int f,t,w;
	Edge(int a,int b,int c):f(a),t(b),w(c){}
};
vector<Edge> G;
int bellman_ford(){
	int dist[maxn];
	mem(dist,0x3f);dist[1]=0;
	rep(i,0,n){
		int f=0;
		rep(j,0,G.size()){
			if(dist[G[j].t]>dist[G[j].f]+G[j].w)
				dist[G[j].t]=dist[G[j].f]+G[j].w,
				f=1;
		}
		if(!f) return 0;
	}
	return 1;
}
int main(){
	int f;cin>>f;
	while(f--) {
		int s,e,t;
		cin>>n>>m>>w;
		G.clear();
		rep(i,0,m){
			scanf("%d%d%d",&s,&e,&t);
			G.push_back(Edge(s,e,t));
			G.push_back(Edge(e,s,t));
		}
		rep(i,0,w){
			scanf("%d%d%d",&s,&e,&t);
			G.push_back(Edge(s,e,-t));
		}
		puts(bellman_ford()?"YES":"NO");
	}
}