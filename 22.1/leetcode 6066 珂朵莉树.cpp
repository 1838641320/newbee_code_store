#include<bits/stdc++.h>
using namespace std;
class CountIntervals {
public:
    map<int,pair<int,int>> mp;//[,)
    int ans=0;
    CountIntervals() {mp[0]={1<<30,0};}
    auto split(int x){
        auto it=--mp.upper_bound(x);
        if(it->first==x) return it;
        auto t=it->second;
        it->second.first=x-1;
        return mp.insert({x,t}).first;
    }
    void add(int l, int r) {
        auto rn=split(r+1);
        auto ln=split(l);
        for(auto a=ln;a!=rn;a=mp.erase(a)){
            if(a->second.second==0) ans+=a->second.first-a->first+1;
        }
        mp[l]={r,1};
    }
    int count() {return ans;}
};