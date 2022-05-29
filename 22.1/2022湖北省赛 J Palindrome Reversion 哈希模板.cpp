#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#include<queue>
#include<numeric>
typedef long long ll;
const int maxn=1e5+9;
namespace my_hash{
	typedef __int128_t lll;
	const ll mod=1945555039024054273,base=233;
	vector<ll> pb;
	void init(int n){
		pb.resize(n+5);
		pb[0]=1;
		for(int i=1;i<(int)pb.size();i++) pb[i]=(lll)pb[i-1]*base%mod;
	}
	struct node{
		ll has=0;int len=0;
		node operator+(const node&a)const{
			ll v=(lll(has)*pb[a.len]+a.has)%mod;
			return {v,len+a.len};
		}
		bool operator==(const node&a)const{
			return has==a.has&&len==a.len;
		}
	};
	vector<ll> fit(char *s,int n){//1 index
		vector<ll> ret(n+1);
		for(int i=1;i<=n;i++) ret[i]=((lll)ret[i-1]*base+s[i])%mod;
		return ret;
	}
	node get(vector<ll>&ha,int l,int r){//[1,n]
		l=max(l,1),r=min(r,(int)ha.size());
		if(l>r) return {0,0};
		ll ret=(ha[r]-(lll)ha[l-1]*pb[r-l+1])%mod;
		if(ret<0) ret+=mod;
		return {ret,r-l+1};
	}
}
char s[maxn];
void solve(){
	using namespace my_hash;
	scanf("%s",s+1);
	int n=strlen(s+1);
	init(n);
	auto check=[&]()->pair<int,int>{
		auto ha1=fit(s,n);
		reverse(s+1,s+1+n);
		auto ha2=fit(s,n);
		reverse(s+1,s+1+n);
		int st=1;
		while(st<n-st+1&&s[st]==s[n-st+1])
			st++;
		int ed;
		for(ed=st;ed<=n;ed++){
			int s1=n-st+1,e1=n-ed+1;
			auto a=get(ha1,1,st-1)+get(ha2,e1,s1)+get(ha1,ed+1,n);
			auto b=get(ha2,1,e1-1)+get(ha1,st,ed)+get(ha2,s1+1,n);
			if(a==b) return {st,ed};
		}
		return {-1,-1};
	};
	if(auto it=check();it.first!=-1){
		printf("%d %d\n",it.first,it.second);
		return;
	}
	reverse(s+1,s+1+n);
	if(auto it=check();it.first!=-1) {
		printf("%d %d\n",n+1-it.second,n+1-it.first);
		return;
	}
	puts("-1 -1");
}
int main() {
	int t=1;
	// scanf("%d",&t);
	while(t--) solve();
}
