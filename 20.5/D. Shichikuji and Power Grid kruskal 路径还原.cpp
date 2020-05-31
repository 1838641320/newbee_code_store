#include"s.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
const int maxn=2e3+9;
ll dist[maxn]={},n,x[maxn]={},y[maxn]={},k[maxn]={};
int par[maxn]={};
struct Edge{ ll f,t,cost; };
vector<Edge> g;
int findp(int x){ return par[x]==x?x:(par[x]=findp(par[x])); }
void unite(int a,int b){
	a=findp(a),b=findp(b);
	par[a]=b;
}
vector<int> poo;
vector<pair<int,int>> link;
ll kruskal(){
	ll ans=0,ee=0;
	rep(i,0,n+2) par[i]=i;
	sort(g.begin(),g.end(),[](Edge &a,Edge &b){return a.cost<b.cost;});
	for (Edge i:g){
		int u=i.f,v=i.t;
		if (findp(u)==findp(v)) continue;
		unite(u,v);ans+=i.cost;
		if (u==0) poo.push_back(v);
		else link.push_back({u,v});
		if (++ee==n) break;
	}
	return ans;
}
int main(){
	cin>>n;
	rep(i,1,n+1) scanf("%lld %lld",x+i,y+i);
	rep(i,1,n+1) scanf("%lld",dist+i),g.push_back({0,i,dist[i]});
	rep(i,1,n+1) scanf("%lld",k+i);
	rep(i,1,n+1) rep(j,i+1,n+1) 
		g.push_back({i,j,(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]))});
	printf("%lld\n",kruskal());
	printf("%d\n",poo.size());
	for (int i:poo) printf("%d ",i);
	printf("\n%d\n",link.size());
	for (auto i:link) printf("%d %d\n",i.first,i.second);
}