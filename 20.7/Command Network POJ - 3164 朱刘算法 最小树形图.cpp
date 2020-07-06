#include"s.h"
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
const int maxm=1e4+9,maxn=109;
struct Edge{ int f,t;double c; }edge[maxm];
double zhuliu(int root,int n,int m){
	double res=0,in[maxn];
	int cnt,t,f,vis[maxn],id[maxn],pre[maxn];
	for(;;){
		rep(i,0,n) in[i]=1e20;
		rep(i,0,m){
			f=edge[i].f,t=edge[i].t;
			if(edge[i].c<in[t]&&f!=t){
				pre[t]=f;
				in[t]=edge[i].c;
			}
		}
		rep(i,0,n) if(i!=root&&in[i]==1e20) 
			return -1;
		cnt=0;in[root]=0;
		mem(id,-1);mem(vis,-1);
		rep(i,0,n){
			res+=in[i];
			for(t=i;vis[t]!=i&&id[t]==-1&&t!=root;t=pre[t])
				vis[t]=i;
			if(t!=root&&id[t]==-1){
				for(f=pre[t];f!=t;f=pre[f])
					id[f]=cnt;
				id[t]=cnt++;
			}
		}
		if(!cnt) break;
		rep(i,0,n) if(id[i]==-1) id[i]=cnt++;
		rep(i,0,m){
			f=edge[i].f,t=edge[i].t;
			edge[i].f=id[f];
			edge[i].t=id[t];
			if(id[t]!=id[f]) edge[i].c-=in[t];
		}
		n=cnt;root=id[root];
	}
	return res;
}
int main(){
	int n,m,f,t;
	double x[maxn],y[maxn],ans;
	while(~scanf("%d%d",&n,&m)){
		rep(i,0,n) scanf("%lf%lf",x+i,y+i);
		rep(i,0,m) {
			scanf("%d%d",&f,&t);
			edge[i].f=--f;
			edge[i].t=--t;
			edge[i].c=sqrt(pow(x[f]-x[t],2)+pow(y[f]-y[t],2));
		}
		ans=zhuliu(0,n,m);
		if(ans==-1) puts("poor snoopy");
		else printf("%.2lf\n",ans);
	}
}