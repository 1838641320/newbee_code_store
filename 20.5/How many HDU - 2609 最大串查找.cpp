#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn=100+9;
set<string> in;
string s,mi;
int n;
int getmax(string &p){
	int i=0,j=1,k=0,len=p.length();
	while (j<len&&k<len){
		char a=p[i+k],b=p[j+k];
		if (a==b) { k++;continue; }
		if (a<b)
			i+=k+1;
		if (a>b)
			j+=k+1;
		k=0;
		if (i==j) j++;
	}
	return i;
}
int main(){
	while (cin>>n){
		in.clear();
		rep(__,0,n){
			cin>>s;
			int len=s.length();
			s+=s;
			mi=s.substr(getmax(s),len);
			in.insert(mi);
		}
		cout<<in.size()<<endl;
	}
}