//#include"s.h"
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct P{
	int t;
	double r,c;
	P(int x,double r,double c):t(x),r(r),c(c){}
};
const int maxn=109;
const double ep=1e-10;
vector<P> G[maxn];
double dist[maxn]={};
int n,m,x,u,v;
double V,ruv,cuv,rvu,cvu,res;
int spfa(){
	int cnt[maxn]={};
	bool iq[maxn]={};
	dist[x]=V;
	queue<int> q;
	q.push(x);iq[x]=1;
	while(!q.empty()){
		int v=q.front();q.pop();
		iq[v]=0;
		for(int i=0;i<G[v].size();i++){
			int t=G[v][i].t;
			double cc=(dist[v]-G[v][i].c)*G[v][i].r;
			if(dist[t]>=cc) continue;
			dist[t]=cc;
			if(iq[t]==0){
				iq[t]=1;q.push(t);cnt[t]++;
				if(cnt[t]>n) return 1;
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d%d%d%lf",&n,&m,&x,&V);
	while(m--){
		scanf("%d%d%lf%lf%lf%lf",&u,&v,&ruv,&cuv,&rvu,&cvu);
		G[u].push_back(P(v,ruv,cuv));
		G[v].push_back(P(u,rvu,cvu));
	}
	puts(spfa()?"YES":"NO");
}