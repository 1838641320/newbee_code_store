#include <iostream>
#include<queue>
#include<algorithm>
#include<random>
#include<ctime>
template<class T>
T getk_no_recursion(std::vector<T>&a,std::vector<T>&b,int k){
    if((int)b.size()>=k&&b[k-1]<=a.front()){
        return b[k-1];
    }
    int ub=a.size(),lb=0;
    while(ub>lb+1){
        int mid=(ub+lb)/2;
        if([&](int v)->bool {
            int pos=k-v-2;
            if(pos<0) return 0;
            if(pos>=(int)b.size()) return 1;
            return a[v]<=b[pos];
        }(mid)) lb=mid;
        else ub=mid;
    }
    T ans=a[lb];
    auto test=[&](T v){
        auto lb=[](auto&a,auto b){return std::lower_bound(a.begin(),a.end(),b)-a.begin();};
        return lb(a,v)+lb(b,v)+1<=k;
    };
    if(lb+1<a.size()&&test(a[lb+1]))
        ans=a[lb+1];
    if(int pos=k-lb-2;pos>=0&&pos<b.size()&&b[pos]>ans&&test(b[pos]))
        ans=b[pos];
    return ans;
}
template<class T>
T getk(std::vector<T>&a,std::vector<T>&b,int k){
    auto get=[&](auto f,T *a,int n,T *b,int m,int k)->T {
        if(n>m) return f(f,b,m,a,n,k);
        if(n==0) return b[k-1];
        if(k==1) return std::min(a[0],b[0]);
        int i=std::min(n,k/2),j=std::min(m,k/2);
        if(a[i-1]>b[j-1])
            return f(f,a,n,b+j,m-j,k-j);
        else 
            return f(f,a+i,n-i,b,m,k-i);
    };
    return get(get,a.data(),a.size(),b.data(),b.size(),k);
}
int bf(std::vector<int> a,std::vector<int> b,int k){
    std::vector<int> c(a.size()+b.size());
    std::merge(a.begin(),a.end(),b.begin(),b.end(),c.begin());
    return c[k-1];
}
int main() {
    std::mt19937 rd(time(0));
    auto gen=[&](int l,int r){return rd()%(r-l+1)+l;};
    int cnt=1;
    std::cin>>cnt;
    std::vector<int> a={2,3,5,8,9},b={0,1,2,4,7,9};  // 0,1,2,2,3,4,5,7,8,9,9
    for(int i=0;i<cnt;i++){
        int n=gen(1,20),m=gen(1,20);
        a.resize(n),b.resize(m);
        for(auto&i:a) i=gen(1,50);
        for(auto&i:b) i=gen(1,50);
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(size_t j=1;j<=a.size()+b.size();j++){
            // std::cout<<getk(a,b,j)<<"\n";
            // std::cout<<getk(b,a,j)<<"\n";
            if(bf(a,b,j)!=getk(a,b,j)){
                std::cout<<"\nfuck\n";
                {for(auto i:a) std::cout<<i<<" ";}std::cout<<" a \n";
                {for(auto i:b) std::cout<<i<<" ";}std::cout<<" b \n";
                std::cout<<j<<" k \n";
                return 0;
            }
        }
    }
}
