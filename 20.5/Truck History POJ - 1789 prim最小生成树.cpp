#include<cstdio>
#include<iostream>
#include<cstring>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn=2000+9;
char in[maxn][8];
int n,g[maxn][maxn],dist[maxn];
int prim() {
	int ans=0;
	memset(dist,0x3f,sizeof dist);
	char used[maxn]={};
	dist[0]=0;
	while (1) {
		int v=-1;
		rep(i,0,n)
			if (used[i]==0&&(v==-1||dist[i]<dist[v])) v=i;
		if (v==-1) return ans;
		used[v]=1;
		ans+=dist[v];
		rep(i,0,n) dist[i]=min(dist[i],g[v][i]);
	}
}
int main() {
	while (cin>>n,n) {
		rep(i,0,n) scanf("%s",in[i]);
		rep(i,0,n) rep(j,0,i) {
			g[i][j]=0;
			rep(k,0,8) if (in[i][k]!=in[j][k]) g[i][j]++;
			g[j][i]=g[i][j];
		}
		printf("The highest possible quality is 1/%d.\n",prim());
	}
}