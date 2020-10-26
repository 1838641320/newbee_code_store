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
const int maxn=5e3+9;
int n,m,p,dfn[maxn]={},low[maxn]={},dfscnt=0,scc[maxn];
vector<int> g[maxn]={},st;
bool ins[maxn];
void unite(int u){
    scc[st.back()]=u;
    ins[st.back()]=0;
    st.pop_back();
}
void tarjan(int u){
    low[u]=dfn[u]=++dfscnt;
    st.push_back(u),ins[u]=1;
    for(int i:g[u]){
        if(!dfn[i])
            tarjan(i),low[u]=min(low[i],low[u]);
        else if(ins[i]) low[u]=min(low[u],dfn[i]);
    }
    if(dfn[u]==low[u]){
        while(st.back()!=u) unite(u);
        unite(u);
    }
}
int du[maxn]={};
int main(){
    read(n,m,p);
    rep(i,0,m){
        int u,v;scanf("%d%d",&u,&v);
        g[u].push_back(v);
    }
    mem(dfn,0),mem(low,0),dfscnt=0;
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
    mem(du,0);
    for(int i=1;i<=n;i++) for(int j:g[i]) {
		if(scc[i]!=scc[j]) du[scc[j]]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++) 
		if(scc[i]==i&&du[i]==0&&scc[i]!=scc[p]) ans++;
	printf("%d",ans);
}