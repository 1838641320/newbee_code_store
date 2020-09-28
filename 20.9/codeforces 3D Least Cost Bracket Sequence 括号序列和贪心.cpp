// #include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<queue>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
ll gcd(ll x,ll y){while(y^=x^=y^=x%=y);return x;}
const ll mod=1e9+7;
const int maxn=1e6+9;
using namespace std;
using pii=pair<int,int>;
priority_queue<pii,vector<pii>,greater<pii>> pq;
char s[maxn]={};
int main(){
	scanf("%s",s);
	int lay=0,len=strlen(s);
	ll ans=0;
	rep(i,0,len){
		if(s[i]=='(') lay++;
		if(s[i]==')') lay--;
		if(s[i]=='?'){
			s[i]=')';
			lay--;
			int l,r;scanf("%d%d",&l,&r);
			ans+=r;
			pq.push({l-r,i});
		}
		if(lay<0){
			if(pq.empty()) return puts("-1");
			lay+=2;
			ans+=pq.top().first;
			s[pq.top().second]='(';
			pq.pop();
		}
	}
	if(lay) puts("-1");
	else printf("%lld\n%s",ans,s);
}