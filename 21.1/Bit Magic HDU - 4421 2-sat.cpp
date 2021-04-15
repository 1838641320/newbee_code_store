#include<iostream>
#include<cstring>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
#include<queue>
const int maxn=5e2+9;
int n;
int b[maxn][maxn];
int dfn[maxn*2],low[maxn*2],dnt,scc[maxn*2];
int st[maxn*2],top;
bool ins[maxn*2];
vector<int> g[maxn*2];//is-not
void tarjan(int u){
	low[u]=dfn[u]=++dnt;
	st[top++]=u;ins[u]=1;
	for(int i:g[u]){
		if(!dfn[i])
			tarjan(i),low[u]=min(low[u],low[i]);
		else if(ins[i]) low[u]=min(low[u],dfn[i]);
	}
	if(dfn[u]==low[u])
		for(int v=-1;v!=u;){
			v=st[--top];
			scc[v]=u,ins[v]=0;
		}
}
int test_bit(int bi){
	for(int i=0;i<2*n;i++) g[i].clear();
	rep(i,0,n) rep(j,i+1,n){
		int t=(b[i][j]>>bi)&1;
		if(i%2==1&&j%2==1){//zero -> one
			g[t?n+i:i].push_back(t?j:i+n);
			g[t?n+j:j].push_back(t?i:j+n);
		}
		else if(i%2==0&&j%2==0){
			g[t?n+i:i].push_back(t?i:n+j);
			g[t?n+j:j].push_back(t?j:n+i);
		}
		else {// i==j <==> i->j && j->i
			g[i].push_back(t?n+j:j);
			g[j].push_back(t?n+i:i);
			g[n+i].push_back(t?j:n+j);
			g[n+j].push_back(t?i:n+i);
		}
	}
	mem(dfn,0),mem(low,0);dnt=0;
	for(int i=0;i<2*n;i++) if(!dfn[i]) tarjan(i);
	for(int i=0;i<n;i++) if(scc[i]==scc[i+n]) return 0;
	return 1;
}
int main(){
	while(~scanf("%d",&n)){
		rep(i,0,n) rep(j,0,n) scanf("%d",&b[i][j]);
		int flag=1;
		rep(i,0,n) if(b[i][i]!=0) flag=0;
		rep(i,0,n) rep(j,0,n) 
			if(b[i][j]!=b[j][i]) flag=0;
		rep(i,0,31)
			if(!test_bit(i)||!flag) {
				flag=0;break;
			}
		puts(flag?"YES":"NO");
	}
}