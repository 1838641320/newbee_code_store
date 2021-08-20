#include<iostream>
#include<algorithm>
#include<cstring>
#include<complex>
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn=2e5+9;
int n,q;
char s[maxn];
int pre[maxn],suf[maxn],nex[maxn];
#include<queue>
vector<int> g1[maxn],g2[maxn];
int dfn1[maxn],dfn2[maxn],sz1[maxn],sz2[maxn];
int nc1,nc2,rdfn[maxn];
void getnex(char *s,int n){
    for(int i=0,j=nex[0]=-1;i<=n;){
        if(j==-1||s[i]==s[j]) nex[++i]=++j;
        else j=nex[j];
    }
}
void dfs(int&nc,vector<int> g[],int *dfn,int *sz,int x){
    rdfn[nc]=x;
    dfn[x]=nc++;
    sz[x]=1;
    for(int i:g[x]){
        dfs(nc,g,dfn,sz,i);
        sz[x]+=sz[i];
    }
}
#define mid ((l+r)>>1)
int tr[maxn],ch[maxn*40][2],sm[maxn*40],tot;
void insert(int&rt,int l,int r,int x){
    tot++;sm[tot]=sm[rt]+1;
    ch[tot][0]=ch[rt][0],ch[tot][1]=ch[rt][1],rt=tot;
    if(l==r) return;
    if(x<=mid) insert(ch[rt][0],l,mid,x);
    else insert(ch[rt][1],mid+1,r,x);
}
int query(int lr,int rr,int l,int r,int L,int R){
    if(r<L||l>R||sm[rr]-sm[lr]==0) return 0;
    if(L<=l&&r<=R) return sm[rr]-sm[lr];
    return query(ch[lr][0],ch[rr][0],l,mid,L,R)+
        query(ch[lr][1],ch[rr][1],mid+1,r,L,R);
}
void solve(){
    scanf("%d%d",&n,&q);
    for(int i=0;i<=n+1;i++) g1[i].clear(),g2[i].clear();
    scanf("%s",s);
    getnex(s,n);
    for(int i=1;i<=n;i++) pre[i]=nex[i];
    reverse(s,s+n);
    getnex(s,n);
    for(int i=1;i<=n;i++) suf[i]=n+1-nex[n+1-i];
    suf[n]=n+1;
    for(int i=1;i<=n;i++) 
        g1[pre[i]].push_back(i);
    for(int i=1;i<=n;i++) 
        g2[suf[i]].push_back(i);
    tot=nc1=nc2=0;
    dfs(nc2,g2,dfn2,sz2,n+1);
    dfs(nc1,g1,dfn1,sz1,0);
    for(int i=0,nd;i<=n;i++){
        if(i) tr[i]=tr[i-1];
        nd=dfn2[rdfn[i]+1]+1;
        insert(tr[i],1,n+1,nd);
    }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        y=n+1-y;
        int lr=tr[dfn1[x]-1],rr=tr[dfn1[x]+sz1[x]-1],L=dfn2[y]+1,R=dfn2[y]+sz2[y];
        int ans=L<=R?query(lr,rr,1,n+1,L,R):0;
        printf("%d\n",ans);
    }
}// save cpp
int main(){
    // freopen("1008.in","r",stdin);
    // freopen("1.out","w",stdout);
    int t;scanf("%d",&t);
    while(t--) 
        solve();
}