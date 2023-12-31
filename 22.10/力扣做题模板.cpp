#include <iostream>
#include <algorithm>
#include<cstring>
using namespace std;
#include<queue>
// #include<array>
// #include<numeric>
//---------------------------------------------------------
// #define printf
using ll=long long;
using pii=pair<int,int>;
const int mod=1e9+7,maxn=2e4+9;

class Solution {
public:
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& q) {
        return {1,1};
    }
};
//---------------------------------------------------
template<class t>
ostream& operator<<(ostream&os,const vector<t> &a){
	for(auto i=0u;i<size(a);i++) 
		os<<",{"[!i]<<a[i];
	return os<<"} "[empty(a)];
}
int main(){
	Solution s;
	vector<vector<int>> g,g2;
	vector<int> a,b;
	g2={{0,3},{3,6},{2,6},{0,6}};
	a={2,0,1};
	// a={1,2,3,4};
	// a={1,2,3,4,5};
	// cout<<s.getMaxFunctionValue(a,8)<<"\n";
	g={{1,2,4,5}};
	cout<<s.canMakePalindromeQueries("acbcab",g)<<"\n";
}
