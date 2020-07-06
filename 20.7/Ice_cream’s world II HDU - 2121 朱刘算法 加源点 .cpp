#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxm=1e4+2000,maxn=1009;
struct Edge{ int f,t,c; }G[maxm];
pair<int,int> zhuliue(int root,int n,int m){
	int res=0,in[maxn],ori=0;
	int vis[maxn],pre[maxn],id[maxn],f,t,cnt;
	for(;;){
		mem(in,0x3f);
		rep(i,0,m){
			f=G[i].f,t=G[i].t;
			if(in[t]>G[i].c&&f!=t){
				in[t]=G[i].c,pre[t]=f;
				if(f==root) ori=i;
			}
		}
		cnt=0;in[root]=0;
		mem(vis,-1),mem(id,-1);
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
			f=G[i].f,t=G[i].t;
			G[i].f=id[f];
			G[i].t=id[t];
			if(id[t]!=id[f]) G[i].c-=in[t];
		}
		n=cnt;root=id[root];
	}
	return {res,ori};
}
int main(){
	int n,m,f,t,c;
	while(~scanf("%d%d",&n,&m)){
		int sum=0;
		rep(i,0,m) {
			scanf("%d%d%d",&f,&t,&c);
			G[i]={f,t,c};
			sum+=c;
		}
		sum++;
		rep(i,0,n)
			G[i+m]={n,i,sum};
		auto ans=zhuliue(n,n+1,m+n);
		if(ans.first>=2*sum) puts("impossible\n");
		else printf("%d %d\n\n",ans.first-sum,ans.second-m);
	}
}