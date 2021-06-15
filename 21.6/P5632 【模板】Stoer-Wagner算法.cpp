#include<iostream>
#include<algorithm>
#include<cstring>
#include<complex>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn=6e2+9;
int n,m;
int dis[maxn],g[maxn][maxn];
int stoer_wagner(){
	bool vis[maxn],bin[maxn]={};
	int ret=0x3f3f3f3f,now,s=1,t=n;
	for(int i=1;i<n&&ret>0;i++){
		mem(dis,0);memcpy(vis,bin,sizeof(vis));
		for(int i=1,k;i<=n;i++){
			k=-1;
			for(int j=1,di=-1;j<=n;j++)
				if(!vis[j]&&dis[j]>di)
					k=j,di=dis[k];
			if(k==-1) break;
			s=t,t=k;
			now=dis[t];vis[t]=1;
			for(int j=1;j<=n;j++) if(!vis[j])
				dis[j]+=g[t][j];
		}
		bin[t]=1;
		ret=min(ret,now);
		for(int j=1;j<=n;j++) if(!bin[j]) 
			g[s][j]=(g[j][s]+=g[j][t]);
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		g[u][v]+=w,g[v][u]+=w;
	}
	printf("%d\n",stoer_wagner());
}