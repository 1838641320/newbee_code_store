#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
using ll=long long;
const int maxn=4e4+9;
vector<int> prime;
void initPrime(int n){
	bool vis[maxn]={};
	for(int i=2;i<=n;i++){
		if(!vis[i]) prime.push_back(i);
		for(int j:prime){
			if(i*j>n) break;
			vis[i*j]=1;
			if(i%j==0) break;
		}
	}
}
int getgs(int x){
	while(x%4==0) x/=2;
	int res=0;
	for(int i:prime){
		if(i*i>x) break;
		while(x%i==0) res++,x/=i;
	}
	return res+(x>1);
}
int main() {
	initPrime(maxn-2);
	int t,n,res,a;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		res=0;
		rep(i,0,n) scanf("%d",&a),res^=getgs(a);
		puts(res?"W":"L");
	}
}