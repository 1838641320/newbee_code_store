#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
#define lch in*2
#define rch in*2+1
#define mid (l+r)/2
using namespace std;
typedef long long ll;
const int maxn=5e4+9;
int n,m,L,R,D=2,delta[maxn];
ll lz[maxn*4],tr[maxn*4];
int dfn[maxn],idCount,top[maxn],deep[maxn],par[maxn]={},hc[maxn],szt[maxn];
vector<int> g[maxn]={};
void dfs(int x){
    szt[x]=1;hc[x]=0;
    for(int i:g[x]) if(i!=par[x]){
        par[i]=x,deep[i]=deep[x]+1;
        dfs(i),szt[x]+=szt[i];
        if(hc[x]==0||szt[i]>szt[hc[x]]) hc[x]=i;
    }
}
void ddfs(int x){
    dfn[x]=idCount++;
    if(hc[x]==0) return;
    top[hc[x]]=top[x],ddfs(hc[x]);
    for(int i:g[x]) if(i!=hc[x]&&i!=par[x])
        top[i]=i,ddfs(i);
}
void pushdown(int in,int l,int r){
    ll la=lz[in];lz[in]=0;
    tr[lch]+=(mid-l+1ll)*la,tr[rch]+=(r-mid)*la;
    lz[lch]+=la,lz[rch]+=la;
}
void update(int in=1,int l=1,int r=n){
    if(l>R||r<L) return;
    if(l>=L&&r<=R){
        lz[in]+=D;tr[in]+=(r-l+1ll)*D;
        return ;
    }
    if(lz[in]) pushdown(in,l,r);
    update(lch,l,mid),update(rch,mid+1,r);
    tr[in]=tr[lch]+tr[rch];
}
ll query(int in=1,int l=1,int r=n){
    if(l>R||r<L) return 0;
    if(l>=L&&r<=R) return tr[in];
    if(lz[in]) pushdown(in,l,r);
    return query(lch,l,mid)+query(rch,mid+1,r);
}
void solve(){
    scanf("%d%d",&n,&m);
    mem(tr,0);mem(delta,0);mem(lz,0);
    for(int i=1;i<=n;i++) g[i].clear();
    rep(i,1,n){
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
            for(;x;x=par[top[x]])
                L=dfn[top[x]],R=dfn[x],update();
        }
        else {
            ll res=base+delta[x]+deep[x]*times;
            for(int i=x;i;i=par[top[i]])
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