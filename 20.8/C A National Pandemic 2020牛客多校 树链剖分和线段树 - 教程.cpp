#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
#define lch in*2
#define rch in*2+1
#define mid (l+r)/2
using namespace std;
typedef long long ll;
const int maxn=5e4+9;
int n,m,L,R,D=2,delta[maxn];//L,R,D线段树更新的三个参数,delta题意相关
ll lz[maxn*4],tr[maxn*4];//线段树两个数组
int dfn[maxn],idCount,top[maxn],deep[maxn],par[maxn]={},hc[maxn],szt[maxn];//树链剖分的各种数组
//	dfs序			重链的开头	深度		有根树的父节点 重儿子	子树大小
vector<int> g[maxn]={};//vector邻接表存图
//------------以下是树链剖分------------
void dfs(int x){//第一轮dfs，记录子树大小和重儿子，深度和父节点
	szt[x]=1;hc[x]=0;
	for(int i:g[x]) if(i!=par[x]){
		par[i]=x,deep[i]=deep[x]+1;
		dfs(i),szt[x]+=szt[i];
		if(hc[x]==0||szt[i]>szt[hc[x]]) hc[x]=i;
	}
}
void ddfs(int x){//第二轮dfs，树链剖分，剖分结果（主要）在dfn中
	dfn[x]=idCount++;//记录dfs序
	if(hc[x]==0) return;
	top[hc[x]]=top[x],ddfs(hc[x]);//优先遍历重儿子
	for(int i:g[x]) if(i!=hc[x]&&i!=par[x])
		top[i]=i,ddfs(i);
}
//---------以上是树链剖分-------------
//---------以下是线段树--------------
void pushdown(int in,int l,int r){//懒惰标记下放
	ll la=lz[in];lz[in]=0;
	tr[lch]+=(mid-l+1ll)*la,tr[rch]+=(r-mid)*la;
	lz[lch]+=la,lz[rch]+=la;
}
void update(int in=1,int l=1,int r=n){//区间加
	if(l>R||r<L) return;//区间不相交则返回
	if(l>=L&&r<=R){//完全包含区间则放置懒惰标记
		lz[in]+=D;tr[in]+=(r-l+1ll)*D;
		return ;
	} 
	if(lz[in]) pushdown(in,l,r);
	update(lch,l,mid),update(rch,mid+1,r);//递归更新
	tr[in]=tr[lch]+tr[rch];//pushup，更新父节点
}
ll query(int in=1,int l=1,int r=n){//区间和
	if(l>R||r<L) return 0;//区间不相交则返回
	if(l>=L&&r<=R) return tr[in];//完全包含区间则返回节点值
	if(lz[in]) pushdown(in,l,r);
	return query(lch,l,mid)+query(rch,mid+1,r);
}
//---------------以上是线段树------------
void solve(){
	scanf("%d%d",&n,&m);
	mem(tr,0);mem(delta,0);mem(lz,0);
	for(int i=1;i<=n;i++) g[i].clear();
	rep(i,1,n){//建图
		int x,y;scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	deep[1]=1;dfs(1);
	idCount=top[1]=1,ddfs(1);
	ll base=0,times=0,op,x,w;
	rep(i,0,m){
		scanf("%lld%lld",&op,&x);
		if(op==1){
			scanf("%lld",&w);times--;
			base+=w-deep[x];
			for(;x;x=par[top[x]])//遍历每个树链
				L=dfn[top[x]],R=dfn[x],update();
		}
		else {
			ll res=base+delta[x]+deep[x]*times;
			for(int i=x;i;i=par[top[i]])//遍历每个树链
				L=dfn[top[i]],R=dfn[i],res+=query();
			if(op==3) printf("%lld\n",res);
			else delta[x]-=max(res,0ll);
		}
	}
}
int main(){
	int t;scanf("%d",&t);
	while(t--) solve();
}