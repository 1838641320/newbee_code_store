#include"s.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
const int maxn=1e5+9;
const ll save=1e8;
int n,a[maxn];
bool vis[maxn];
vector<ll> res;
map<ll,int> factors;
void getfactors(ll n){
    for(ll i=2;i*i<=n;i++){
        if(n%i) continue;
        int t=0;
        while(n%i==0) n/=i,t++;
        factors[i]=max(factors[i],t);
    }
    if(n>1) factors[n]=max(factors[n],1);
}
int main(){
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d",a+i);
    rep(i,1,n+1){
        if(vis[i]) continue;
        ll loop=1;
        for(int j=a[i];j!=i;j=a[j]) loop++,vis[j]=1;
        getfactors(loop);
    }
    res.push_back(1);
    for(auto fa:factors){
        ll base=fa.first,times=fa.second;
        ll t=1;while(times--) t*=base;
        ll rem=0;
        for(int i=0;i<res.size();i++){
            res[i]=res[i]*t+rem;
            rem=res[i]/save;
            res[i]%=save;
        }
        if(rem) res.push_back(rem);
    }
    printf("%lld",res.back());
    for(int i=res.size()-2;~i;i--) printf("%08lld",res[i]);
}