//#include"s.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=1e7+9;
bool notp[maxn]={};
void shai(){
    notp[1]=notp[0]=1;
    int n=maxn-4,ed=sqrt(n);
    for(int i=2;i<=ed;i++){
        if(notp[i]==0)
            for(int j=i*i;j<=n;j+=i)
                notp[j]=1;
    }
}
int cnt[maxn]={};
int main(){
    shai();
    for(int i=2;i<maxn;i++) cnt[i]=cnt[i-1]+!notp[i];
    int t;scanf("%d",&t);
    while(t--){
        int l,r;scanf("%d%d",&l,&r);
        printf("%d\n",cnt[r]-cnt[l-1]);
    }
}