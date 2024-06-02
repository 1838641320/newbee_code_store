template<typename ty>
struct my_queue{
    vector<ty> a,b;
    ty (*op)(ty,ty);
    int m=0,l=0;//左闭区间
    int size(){return b.size()-l;}
    ty get(){
        if((int)b.size()<=m) return b[l];//没有右边一段
        if(l>=m) return b.back();//没有左边一段
        return op(b.back(),b[l]);
    }
    void push(ty x){
        a.push_back(x);
        if((int)b.size()>m) x=op(x,b.back());//有右边一段
        b.push_back(x);
    }
    void pop(){
        if(l>=m){//没有左边一段了
            b.back()=a.back();
            for(int i=b.size()-2;i>=m;i--)
                b[i]=op(a[i],b[i+1]);
            m=b.size();
        }
        l++;
    }
};
class Solution {
public:
    int minimumDifference(vector<int>& a, int k) {
        int ans=1<<30;
        my_queue<int> q;
        q.op=[](int x,int y){return x&y;};
        for(auto i:a) {
            ans=min(ans,abs(i-k));
            q.push(i);
            ans=min(ans,abs(q.get()-k));
            while(i>k&&q.size()&&q.get()<k) {
                q.pop();
                ans=min(ans,abs(q.get()-k));
            }
        }
        return ans;
    }
};
