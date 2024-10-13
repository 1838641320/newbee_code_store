#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#include<queue>
template<class t>
ostream& operator<<(ostream&os,const vector<t> &a){
	for(auto i=0u;i<size(a);i++) 
		os<<",{"[!i]<<a[i];
	return os<<"}\0{}"+empty(a)*2;
}
// #include<set>
// #include<map>
//---------------------------------------------------------
class Solution {
public:
    vector<long long> findXSum(vector<int>& a, int k, int x) {
        using ll=long long;
        vector<ll> ans;
        
        return ans;
    }
};
//---------------------------------------------------------
#include<random>
char sss[1<<22];
int main(){
	// ios::sync_with_stdio(0);
	// cin.tie(0);cout.tie(0);
	freopen("2.txt","r",stdin);
	// freopen("CON","r",stdin);
	mt19937 rd(time(0));
	[[maybe_unused]] auto gen=[&](int l,int r){
		return rd()%(r-l+1)+l;
	};
	auto print=[](auto v){cout<<v<<"\n";};
	Solution s;
	{
vector<int> a={1,1,2,2,3,4,2,3};
int b=6;
int c=2;
		print(s.findXSum(a,b,c));
	}

	// for(int i=0;i<1e5;i++){
	//     int n=gen(1,10);
	//     // n=4e4;
	// }
}
// -g3 -fsanitize=address,undefined

/*
[[0,1],[0,4],[0,5],[1,7],[2,3],[2,4],[2,5],[3,6],[4,6],[4,7],[6,8],[7,8]]

*/
