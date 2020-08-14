#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxp=1e3+9;
int Next[maxp],n,m;
string pat,text;
void getnext(string &p,int *next) {
	next[0]=-1;
	for(int i=0,j=-1;i<p.length();next[++i]=++j)
		for(;~j&&p[i]!=p[j];j=next[j]);
}
int kmp_c(string &p,string &t,int *next) {
	getnext(p,next);
	int i=0,j=0,ans=0;
	while (i<t.length()) {
		if (j==-1||t[i]==p[j])
			i++,j++;
		else j=next[j];
		if (j==p.length()) {
			ans++;
			j=0;
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	while (cin>>text) {
		if (text[0]=='#') break;
		cin>>pat;
		cout<<kmp_c(pat,text,Next)<<endl;
	}
}