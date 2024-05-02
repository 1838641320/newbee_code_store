#include <ranges>
class Solution {
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
        if(ch[u][0]) val[ch[u][0]].sub+=val[u].sub;
        if(ch[u][1]) val[ch[u][1]].sub+=val[u].sub;
        val[u].val-=val[u].sub;
        val[u].sub=0;
    }
    int merge(int l,int r){//return new root;
        if((long long)l*r==0) return l+r;//null return;
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
struct mykey{
    int val,sub;
    bool operator<(const mykey&b){
        return b.val<val;
    }
};
public:
    int maxIncreasingGroups(vector<int>& a) {
        int n=a.size();
        treap<mykey> tr(n);
        for(int i=0;i<n;i++) 
            tr.insert({a[i],0});
        auto maxx=[&](int id,int c){
            while(tr.ch[id][c]){
                tr.down(id);
                id=tr.ch[id][c];
            }
            tr.down(id);
            return tr.val[id].val;
        };
        int ans=1;
        for(int i=1;i<=n;i++){
            int L,m1,m2,R;
            tr.split_by_rank(i,tr.root,L,R);
            if(maxx(L,1)<1) break;
            ans=i;
            tr.val[L].sub+=1;
            auto k=maxx(R,0);
            tr.split_by_val({k,0},L,L,m1);
            tr.split_by_val({k,0},R,m2,R);
            tr.root=tr.merge(tr.merge(L,m2),tr.merge(m1,R));
        }
        return ans;
    }
};
