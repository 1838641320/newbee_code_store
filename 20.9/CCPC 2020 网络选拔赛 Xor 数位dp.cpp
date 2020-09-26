#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
using namespace std;
ll dp[36][3][3][2][2][2];
int a,b,k,w;
int bia[36],bib[36],bik[36],biw[36];
void getbit(int a[],int x){
    rep(i,0,36) a[i]=(bool)(x&(1ll<<i));
}
ll dfs(int pos,int c1,int c2,int l1,int l2,int l3){
    if(pos==-1) return c1>=0&&c2>=0;
    ll &DP=dp[pos][c1+1][c2+1][l1][l2][l3];
    if(DP!=-1) return DP;
    DP=0;
    int upa=l1?bia[pos]:1;
    int upb=l2?bib[pos]:1;
    int upw=l3?biw[pos]:1;
    for(int i=0;i<=upa;i++){
        for(int j=0;j<=upb;j++){
            int nc1=c1*2+(i-j)+bik[pos],
                nc2=c2*2+(j-i)+bik[pos];
            if(nc1<-1||nc2<-1||(i^j)>upw) continue;
            DP+=dfs(pos-1,min(nc1,1),min(nc2,1),l1&&i==upa,l2&&j==upb,l3&&(i^j)==upw);
        }
    }
    return DP;
}
void solve(){
    mem(dp,-1);
    scanf("%d%d%d%d",&a,&b,&k,&w);
    getbit(bia,a);getbit(bib,b);getbit(bik,k);getbit(biw,w);
    printf("%lld\n",dfs(35,0,0,1,1,1));
}
int main() {
    int t;scanf("%d",&t);
    while(t--) solve();
}