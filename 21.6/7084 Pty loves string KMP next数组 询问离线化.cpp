#include<iostream>
#include<algorithm>
#include<cstring>
#include<complex>
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn=2e5+9;
#include<queue>
int bi[maxn];
void add(int p,int x){while(p<maxn) bi[p]+=x,p+=p&-p;}
int sum(int p){
    int ret=0;
    while(p>0) ret+=bi[p],p-=p&-p;
    return ret;
}
vector<int> g1[maxn],g2[maxn];
struct qrs{int y,in;};
vector<qrs> Qs[maxn];
int L[maxn],R[maxn],nc;
int ans[maxn];
void dfs1(int x){
    L[x]=nc++;
    for(int i:g2[x]) dfs1(i);
    R[x]=nc-1;
}
void dfs2(int x){
    for(auto q:Qs[x])
        ans[q.in]-=sum(R[q.y]+1)-sum(L[q.y]);
    add(L[x+1]+1,1);
    for(int i:g1[x]) dfs2(i);
    for(auto q:Qs[x])
        ans[q.in]+=sum(R[q.y]+1)-sum(L[q.y]);
}
int pre[maxn],suf[maxn],nex[maxn];
void getnex(char *s,int n){
    for(int i=0,j=nex[0]=-1;i<=n;){
        if(j==-1||s[i]==s[j]) nex[++i]=++j;
        else j=nex[j];
    }
}
char s[maxn];
void solve(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<=n+1;i++) g1[i].clear(),g2[i].clear(),Qs[i].clear();
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
    rep(i,0,q){
        int x,y;scanf("%d%d",&x,&y);
        Qs[x].push_back({n+1-y,i});
    }
    nc=0;mem(bi,0);mem(ans,0);
    dfs1(n+1);
    dfs2(0);
    rep(i,0,q) printf("%d\n",ans[i]);
}// save cpp
int main(){
    int t;scanf("%d",&t);
    while(t--) 
        solve();
}