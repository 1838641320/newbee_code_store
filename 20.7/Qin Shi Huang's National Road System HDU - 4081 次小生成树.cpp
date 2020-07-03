#include"s.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=1e3+9;
struct City{ double x,y,p; }ci[maxn];
double mp[maxn][maxn]={};
int n;
double maxe[maxn][maxn],d[maxn];
bool mst[maxn][maxn],used[maxn];
int pre[maxn];
double prim(){
	double res=0;
	mem(used,0),mem(mst,0);mem(maxe,0);mem(pre,0);
	rep(i,0,n) d[i]=1e20;
	d[0]=0;
	while(1){
		int v=-1;
		rep(i,0,n)
			if(!used[i]&&(v==-1||d[i]<d[v])) v=i;
		if(v==-1) return res;
		used[v]=1;res+=d[v];
		mst[v][pre[v]]=mst[pre[v]][v]=1;
		rep(u,0,n){
			if(used[u]&&u!=v)
				maxe[u][v]=maxe[v][u]=max(maxe[pre[v]][u],d[v]);
			if(mp[v][u]<d[u])
				d[u]=mp[v][u],
				pre[u]=v;
		}
	}
}
double solve(){
	scanf("%d",&n);
	double ans=0;
	rep(i,0,n) scanf("%lf%lf%lf",&ci[i].x,&ci[i].y,&ci[i].p);
	rep(i,0,n) rep(j,i+1,n)
		mp[i][j]=mp[j][i]=hypot(ci[i].x-ci[j].x,ci[i].y-ci[j].y);
	rep(i,0,n) mp[i][i]=1e20;
	double B=prim(),A;
	rep(i,0,n) rep(j,i+1,n){
		A=ci[i].p+ci[j].p;
		if(mst[i][j])
			ans=max(ans,A/(B-mp[i][j]));
		else
			ans=max(ans,A/(B-maxe[i][j]));
	}
	return ans;
}
int main(){
	int ___;scanf("%d",&___);
	while(___--) printf("%.2lf\n",solve());
}