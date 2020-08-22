#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=1e5+9;
ll k[4][7]={},n;
int par[maxn],a[maxn],b[maxn];
int findp(int x){return par[x]==x?x:par[x]=findp(par[x]);}
void unite(int x,int y){
    int fa=findp(x),fb=findp(y);
    par[fa]=fb;
    a[fb]+=a[fa];
    b[fb]+=b[fa];
}
void mul(ll a,ll b){
    for(int i=3;i;i--) for(int j=6;j;j--){
        k[i][j]+=a*k[i-1][j-1]%mod;
        if(j>1) k[i][j]+=b*k[i-1][j-2]%mod;
        k[i][j]%=mod;
    }
}
void div__(ll a,ll b){
    for(int i=1;i<=3;i++) for(int j=1;j<=6;j++){
        k[i][j]-=a*k[i-1][j-1]%mod;
        if(j>1) k[i][j]-=b*k[i-1][j-2]%mod;
        k[i][j]=(k[i][j]%mod+mod)%mod;
    }
}
void solve(){
    mem(a,0),mem(b,0);
    mem(k,0),k[0][0]=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int t;scanf("%d",&t);
        par[i]=i;
        if(t==1) a[i]++;
        else b[i]++;
        mul(a[i],b[i]);
    }
    printf("%lld\n",(k[3][5]+k[3][6])%mod);
    while(--n){
        int u,v;scanf("%d%d",&u,&v);
        int fa=findp(u),fb=findp(v);
        div__(a[fa],b[fa]);div__(a[fb],b[fb]);
        unite(fa,fb);
        mul(a[fb],b[fb]);
        printf("%lld\n",(k[3][5]+k[3][6])%mod);
    }
}
int main(){
    int t;scanf("%d",&t);
    while(t--) solve();
}