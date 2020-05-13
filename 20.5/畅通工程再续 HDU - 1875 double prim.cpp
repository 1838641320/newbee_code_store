#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
const int maxn=100+9;
int n;
double G[maxn][maxn];
pair<double,double> P[maxn]={};
double prim() {
	double d[maxn]={},ans=0;char vis[maxn]={};
	rep(i,0,n+5) d[i]=1e50;d[0]=0;
	while (1) {
		int v=-1;
		rep(i,0,n)
			if (vis[i]==0&&(v==-1||d[i]<d[v])) v=i;
		if (v==-1) return ans;
		vis[v]=1;ans+=d[v];
		rep(i,0,n) d[i]=min(d[i],G[v][i]);
	}
}
double dist(int i,int j) {
	double x=P[i].first-P[j].first,y=P[i].second-P[j].second;
	double res=sqrt(x*x+y*y);
	return (res>=10&&res<=1000)?res:1e50;
}
int main() {
	int test;cin>>test;
	while (test--) {
		cin>>n;
		rep(i,0,n) scanf("%lf %lf",&P[i].first,&P[i].second);
		rep(i,0,n) rep(j,0,i) 
			G[i][j]=G[j][i]=dist(i,j);
		double res=prim();
		if (res>1e49) puts("oh!");
		else printf("%.1lf\n",res*100);
	}
}