#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+9;
int val[(1<<20)+9][17][2];//status array
int a[maxn],n;
vector<int> g[maxn];
int sz[maxn],hc[maxn],rdf[maxn];
int idc,Lx[maxn],Rx[maxn];
long long ans;
void predfs(int x,int pa){//轻重儿子,子树大小
	idc++;Lx[x]=idc;rdf[Lx[x]]=x;
	sz[x]=1,hc[x]=0;
	for(int i:g[x])if(i!=pa){
		predfs(i,x),sz[x]+=sz[i];
		if(hc[x]==0||sz[i]>sz[hc[x]]) hc[x]=i;
	}
	Rx[x]=idc;//子树对应的区间
}
void add(int x,int c){
	for(int i=0,v=a[x];i<17;i++)
		val[v][i][x>>i&1]+=c;
}
void cal(int x,int lcav){//u^v==lca
	for(int i=0,v=a[x]^lcav;i<17;i++)
		ans+=(1ll*val[v][i][!(x>>i&1)])<<i;
}
void dfs(int x,int pa,bool keep){
	for(int i:g[x]) if(i!=pa&&i!=hc[x])
		dfs(i,x,0);//计算轻儿子
	if(hc[x]) dfs(hc[x],x,1);//计算重儿子并保留
	for(int i:g[x]) if(i!=pa&&i!=hc[x]){
		for(int j=Lx[i];j<=Rx[i];j++)//子树形成连续区间
			cal(rdf[j],a[x]);
		for(int j=Lx[i];j<=Rx[i];j++)
			add(rdf[j],1);//添加子树节点
	}
	cal(x,a[x]),add(x,1);//添加根
	if(!keep)//删除子树贡献
		for(int j=Lx[x];j<=Rx[x];j++)
			add(rdf[j],-1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ans=0;
	predfs(1,1);
	dfs(1,1,1);
	printf("%lld\n",ans);
}