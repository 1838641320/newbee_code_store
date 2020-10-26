#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,a,b) for(int i=a,bb=b;i<bb;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
template<class ty>void read(ty&a){
	a=0;int f=0,c=getchar();
	for(;!isdigit(c)&&~c;c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+(c^48);
	if(f) a=-a;
}
template<class a,class ...b>void read(a&A,b&...B){read(A);read(B...);}
//-----------------------
#include<queue>
using namespace std;
const int maxn=2e4+9;
int n,m;
int dfn[maxn]={},low[maxn]={},dfscnt=0;
bool f[maxn]={};
vector<int> g[maxn],res;
void tarjan(int u,int p){
	dfn[u]=low[u]=++dfscnt;
	int ch=0;
	for(int i:g[u]){
		if(!dfn[i]){
			ch++;
			tarjan(i,u);
			low[u]=min(low[u],low[i]);
			if(u!=p&&low[i]>=dfn[u]) f[u]=1;
		}
		else if(u!=p)
			low[u]=min(low[u],dfn[i]);
	}
	if(u==p&&ch>1) f[u]=1;
}
int main(){
	read(n,m);
	rep(i,0,m){
		int u,v;read(u,v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++) 
		if(!dfn[i]) tarjan(i,i);
	for(int i=1;i<=n;i++) if(f[i]) res.push_back(i);
	printf("%d\n",res.size());
	for(int i:res) printf("%d ",i);
}