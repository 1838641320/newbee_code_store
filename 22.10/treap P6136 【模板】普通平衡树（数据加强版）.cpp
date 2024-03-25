#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
using ll=long long;
#include<random>
#include<array>
template<class ty>
struct treap{
private:
    mt19937 rd;
    vector<array<int,2>> ch;
    vector<int> sz,pri;
    vector<ty> val;
    int n,root,L,R,M;
    int newnode(ty v){
        ch[++n]={};sz[n]=1;val[n]=v;pri[n]=rd();
        return n;
    }
    void update(int u){sz[u]=sz[ch[u][0]]+sz[ch[u][1]]+1;}
    int merge(int l,int r){//return new root;
        if((ll)l*r==0) return l+r;//null return;
        if(pri[l]<pri[r])
            return ch[l][1]=merge(ch[l][1],r),update(l),l;
        else 
            return ch[r][0]=merge(l,ch[r][0]),update(r),r;
    }
    void split(ty v,int in,int&l,int&r){//l<=v,r>v
        if(!in) return void(l=r=0);
        if(val[in]<=v)
            l=in,split(v,ch[in][1],ch[in][1],r);
        else 
            r=in,split(v,ch[in][0],l,ch[in][0]);
        update(in);
    }
public:
    treap(size_t n):rd(time(0)),ch(n+1),sz(n+1),pri(n+1),val(n+1){
        this->n=this->root=0;
    }
    int get_kth(int k){
        for(int in=root;;){
            int t=sz[ch[in][0]];
            if(k<=t) in=ch[in][0];
            else if(k==t+1) return val[in];
            else k-=t+1,in=ch[in][1];
        }
    }
    void insert(ty v){
        split(v,root,L,R);
        root=merge(L,merge(newnode(v),R));
    }
    void erase(ty v){
        split(v-1,root,L,R);
        split(v,R,M,R);
        M=merge(ch[M][0],ch[M][1]);
        root=merge(L,merge(M,R));
    }
    int get_rank(ty v){
        split(v-1,root,L,R);
        int ret=sz[L]+1;
        root=merge(L,R);
        return ret;
    }
    void print(int in=0);
};
#include<format>
template<class ty>
void treap<ty>::print(int in){
    if(!in) in=root;
    if(ch[in][0]) print(ch[in][0]);
    cout<<format(" ({},{}) ",val[in],sz[in]);
    if(ch[in][1]) print(ch[in][1]);
    if(in==root) cout<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int op,x,ans=0,n,m,res=0;
    cin>>n>>m;
    treap<int> tr(n+m);
    for(int i=0;i<n;i++) cin>>x,tr.insert(x);
    // tr.print();
    while(m--){
        cin>>op>>x;
        x^=ans;
        if(op==1) tr.insert(x);
        else if(op==2) tr.erase(x);
        else if(op==3) ans=tr.get_rank(x);
        else if(op==4) ans=tr.get_kth(x);
        else if(op==5) ans=tr.get_kth(tr.get_rank(x)-1);
        else if(op==6) ans=tr.get_kth(tr.get_rank(x+1));
        if(op>2) res^=ans;
    }
    cout<<res<<"\n";
}
