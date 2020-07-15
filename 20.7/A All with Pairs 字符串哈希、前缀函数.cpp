#include"s.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef unsigned long long ull;
const ull mod=998244353,base=1e9+97;
const int maxn=1e5+9,maxl=1e6+9;
std::vector<ull> hash[maxn]={};
std::vector<int> next[maxn]={};
ull cnt[maxl]={},Pow[maxl];
int n;
char s[maxl]={};
std::unordered_map<ull,int> mp;
void handle(int id){
	int len=strlen(s);
	hash[id].resize(len+1);
	next[id].resize(len+1);
	next[id][0]=-1;
	for(int j=-1,i=0;i<len;next[id][++i]=++j)
		for(;~j&&s[i]!=s[j];j=next[id][j]);
	for(int i=1;i<=len;i++)
		hash[id][i]=hash[id][i-1]*base+s[i-1];
	ull has=0;
	for(int i=len;i;i--){
		has=has+s[i-1]*Pow[len-i];
		mp[has]++;
	}
}
int main(){
	Pow[0]=1;
	for(int i=1;i<maxl;i++) Pow[i]=Pow[i-1]*base;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%s",s);
		handle(i);
	}
	ull ans=0;
	for(int i=0;i<n;i++){
		int len=hash[i].size()-1;
		for(int j=1;j<=len;j++){
			cnt[j]=mp[hash[i][j]];
			cnt[next[i][j]]-=cnt[j];
		}
		for(int j=1;j<=len;j++)
			ans=(cnt[j]*j*j+ans)%mod;
	}
	printf("%llu\n",ans);
}