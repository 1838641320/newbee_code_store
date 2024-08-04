#include <iostream>
#include <algorithm>
#include<cstring>
using namespace std;
#include<queue>
template<class t>
ostream& operator<<(ostream&os,const vector<t> &a){
	for(auto i=0u;i<size(a);i++) 
		os<<",{"[!i]<<a[i];
	return os<<"}\0{}"+empty(a)*2;
}
//---------------------------------------------------------

class Solution {
public:
	vector<int> numberOfAlternatingGroups(vector<int>& c, vector<vector<int>>& q) {
		
	}
};
//---------------------------------------------------------
#include<random>
int main(){
	// ios::sync_with_stdio(0);
	// cin.tie(0);cout.tie(0);
	// freopen("1.txt","r",stdin);
	// freopen("CON","r",stdin);
	mt19937 rd(time(0));
	auto gen=[&](int l,int r){
		return rd()%(r-l+1)+l;
	};
	Solution s;
	{
		
	}
	// for(int i=0;i<1e5;i++){
	//     int n=gen(1,10);
	//     // n=4e4;
	// }
}
// -g3 -fsanitize=address,undefined

/*
[1,10,9]
[1,1,3,3]


*/
