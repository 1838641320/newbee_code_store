#include <iostream>
#include <algorithm>
#include<cstring>
using namespace std;
#include<queue>
//---------------------------------------------------------
using ll=long long;

class Solution {
public:
    int minimumDistance(vector<vector<int>>& a) {
        
    }
};
//---------------------------------------------------
#include<sstream>
namespace my_util{
template<class t>
ostream& operator<<(ostream&os,const vector<t> &a){
	for(auto i=0u;i<size(a);i++) 
		os<<",{"[!i]<<a[i];
	return os<<"}\0{}"+empty(a)*2;
}
template<typename T>
T convertFromString(const char *&str,int &len) {
    std::istringstream iss(str);
    T result;
    iss >> result;
    {auto a=iss.tellg();
    iss.seekg(0, std::ios::end);
    str+=(len=strlen(str)-(iss.tellg()-a));}
    return result;
}
template<typename T>
T convertFromString(const char *&str) {
    int tmp;
    return convertFromString<T>(str,tmp);
}
template<typename ty>
auto parse(const char *&s,auto getf,auto pushf){
    auto a=getf;
    s+=1;
    for(;s[0]!=']';){
        pushf(a,s);
        if(s[0]==',') s++;
    }
    s+=1;
    return a;
}
template<typename ty>
auto fpush1(vector<ty> &a,const char *&s){
    a.push_back(convertFromString<ty>(s));
}
template<typename ty>
auto fpush2(vector<vector<ty>> &a,const char*&s){
    a.push_back(parse<ty>(s,vector<ty>{},fpush1<ty>));
}
auto operator ""_V2(const char* s,size_t ){
    return parse<int>(s,vector<vector<int>>{},fpush2<int>);
}
auto operator ""_V1(const char* s,size_t ){
    return parse<int>(s,vector<int>{},fpush1<int>);
}
}
int main(){
    using namespace my_util;
	Solution s;
	vector<vector<int>> g,g2;
	vector<int> a,b;
    vector<string> w={"a","aba","ababa","aa"};
	g2={{0,2},{1,2},{4,2},{3,4}};
	g={{3,4,2,1},{4,2,1,1},{2,1,1,0},{3,4,1,0}};
    g={{2, 1, 1, 1, 1, 2, 2, 1, 0},
        {0, 0, 1, 2, 0, 0, 0, 2, 2},
        {2, 0, 2, 2, 1, 2, 1, 0, 0}};
    a={0,0,0,0};
	b={2,4,9,5};
	cout<<s.minimumDistance(g)<<"\n";
}



/*
-o zhong_dao_da.exe
#include <iostream>
#include<vector>
using namespace std;
int main() {
    string s;
    vector<string> t;
    while(getline(cin,s)){
        for(char&c:s){
            if(c=='[') c='{';
            if(c==']') c='}';
        }
        t.push_back(s);
    }
    for(auto i:t) cout<<i<<"\n";
}
*/
