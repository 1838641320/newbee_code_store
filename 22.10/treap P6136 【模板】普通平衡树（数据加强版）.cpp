#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
using ll=long long;
#include<random>
#include<array>
template<class ty>
struct treap{
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
    void down(int u){
        // if(ch[u][0]) val[ch[u][0]].sub+=val[u].sub;
        // if(ch[u][1]) val[ch[u][1]].sub+=val[u].sub;
        // val[u].val-=val[u].sub;
        // val[u].sub=0;
    }
    int merge(int l,int r){//return new root;
        if((ll)l*r==0) return l+r;//null return;
        if(pri[l]<pri[r])
            return down(l),ch[l][1]=merge(ch[l][1],r),update(l),l;
        else 
            return down(r),ch[r][0]=merge(l,ch[r][0]),update(r),r;
    }
    void split_by_val(ty v,int in,int&l,int&r){//l<=v,r>v
        if(!in) return void(l=r=0);
        down(in);
        if(!(v<val[in])) //v>=val[in]
            l=in,split_by_val(v,ch[in][1],ch[in][1],r);
        else 
            r=in,split_by_val(v,ch[in][0],l,ch[in][0]);
        update(in);
    }
    void split_by_rank(int rk,int in,int&l,int&r){//l<=v,r>v
        if(!in) return void(l=r=0);
        down(in);
        if(sz[ch[in][0]]<rk)
            l=in,split_by_rank(rk-sz[ch[in][0]]-1,ch[in][1],ch[in][1],r);
        else 
            r=in,split_by_rank(rk,ch[in][0],l,ch[in][0]);
        update(in);
    }
//----------------------------------------------------------------
    treap(size_t n):rd(time(0)),ch(n+1),sz(n+1),pri(n+1),val(n+1){
        this->n=this->root=0;
    }
    void insert(ty v){
        split_by_val(v,root,L,R);
        root=merge(L,merge(newnode(v),R));
    }
    void erase(ty v){
        split_by_val(v-1,root,L,R);
        split_by_val(v,R,M,R);
        M=merge(ch[M][0],ch[M][1]);
        root=merge(L,merge(M,R));
    }
    int get_rank(ty v,int res=1){
        for(int in=root;in;){
            if(v<=val[in]) in=ch[in][0];
            else res+=sz[ch[in][0]]+1,in=ch[in][1];
        }
        return res;
    }
    int get_kth(int k){
        for(int in=root;;){
            int t=sz[ch[in][0]];
            if(k<=t) in=ch[in][0];
            else if(k==t+1) return val[in];
            else k-=t+1,in=ch[in][1];
        }
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
        // cout<<format("{} {} ;\n",op,x);
        if(op==1) tr.insert(x);
        else if(op==2) tr.erase(x);
        else if(op==3) ans=tr.get_rank(x);
        else if(op==4) ans=tr.get_kth(x);
        else if(op==5) ans=tr.get_kth(tr.get_rank(x)-1);
        else if(op==6) ans=tr.get_kth(tr.get_rank(x+1));
        // cout<<format("ans {}\n",ans);
        if(op>2) res^=ans;
    }
    cout<<res<<"\n";
}
