#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,a,b) for(int i=a,bb=b;i<bb;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
//-----------------------
#include<string>
using namespace std;
const int maxn=1e4+9;
string s;
string si[maxn*10]={};
int dp[maxn]={};
int n,m;
int ch[1000009][26],sz=0,ed[1000009];
void insert(string &a,int i){
	int t,d=0;
	for(char c:a){
		t=tolower(c)-'a';
		if(!ch[d][t]) ch[d][t]=++sz;
		d=ch[d][t]; 
	}
	ed[d]=i;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>s>>m;
	rep(i,0,m){
		cin>>si[i+1];
		insert(si[i+1],i+1);
	}
	dp[0]=114514;
	for(int i=0;i<n;i++){
		for(int j=i,d=0;j>=0;j--){
			d=ch[d][s[j]-'a'];
			if(!d) break;
			if(ed[d]&&dp[j]) {
				dp[i+1]=ed[d];break;
			}
		}
	}
	string ans[n+2];
	int ss=0;
	while(n){
		ans[ss++]=si[dp[n]];
		n-=ans[ss-1].size();
	}
	while(ss) cout<<ans[--ss]<<' ';
}