#include <iostream>
#include <algorithm>
#include<cstring>
using namespace std;
using ll = long long;
#include<queue>
using lll= __int128;
using pii=pair<int,int>;
const int maxn=1.1e7+9;
template<class ty=int,ty mod1=ty(1e9)+97,ty mod2=ty(1e9)+93,int base=233>
struct hash_space{
    //start
    using hat=pii;//hash type
    using lt=ll;  //bigger type to fit multiply result
    #define x first
    #define y second
    static hat mul(const hat&a,ty v,ty c={}){return mul(a,{v,v},{c,c});}
    static hat mul(const hat&a,hat v,hat c={}){
        return {(c.x+lt(a.x)*v.x)%mod1,
                (c.y+lt(a.y)*v.y)%mod2};
    }
    static hat sub(hat a,hat v,hat c={}){
        hat ret={(c.x-lt(a.x)*v.x)%mod1,
                (c.y-lt(a.y)*v.y)%mod2};
        if(ret.x<0) ret.x+=mod1;
        if(ret.y<0) ret.y+=mod2;
        return ret;
    }//end
    #undef x
    #undef y
    vector<hat> pb,ha;
    hash_space(const char *s,int n){
        pb.resize(n+1);
        ha.resize(n+1);
        pb[0]={1,1};//and here
        for(int i=1;i<=n;i++){
            pb[i]=mul(pb[i-1],base);
            ha[i]=mul(ha[i-1],base,s[i-1]);
        }
    }
    struct node{
        hat ha={};int len=0;
        node operator+(const node&a)const{
            return {mul(ha,pb[a.len],a.ha),len+a.len};
        }
        bool operator==(const node&a)const{
            return ha==a.ha&&len==a.len;
        }
    };
    node get(int l,int r){
        l=max(l,1),r=min(r,(int)ha.size()-1);
        if(l>r) return {{},0};
        return {sub(ha[l-1],pb[r-l+1],ha[r]),r-l+1};
    }
};

char s[maxn],s1[maxn];
int r[maxn];
void solve(){
    scanf("%s",s);
    int n=strlen(s);
    memcpy(s1,s,n);
    reverse(s1,s1+n);
    hash_space<int> ha1(s,n),ha2(s1,n);
    int ans=1;
    r[0]=1;
    for(int i=1;i<n;i++){
        r[i]=min(r[i-1]+2,i+1);
        while(1){
            auto r1=ha1.get(i+1-r[i]+1,i+1);
            auto r2=ha2.get(n-(i+1)+1,n-(i-r[i]+2)+1);
            if(r1==r2) break;
            r[i]--;
        }
        ans=max(ans,r[i]);
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;
    // cin>>t;
    while(t--) solve();
}
