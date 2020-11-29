#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
template<class ty>void read(ty&a){
	a=0;int f=0,c=getchar();
	for(;!isdigit(c)&&~c;c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+(c^48);
	if(f) a=-a;
}
template<class a,class ...b>void read(a&A,b&...B){read(A);read(B...);}
//-------------------------------------------------------------------
#include<map>
#include<vector>
#include<bitset>
using namespace std;
vector<int> prime;
void seive(int x){
	x=sqrt(x);
	char vec[x+5];
	vec[0]=vec[1]=1;
	for(int i=2;i<x;i++) if(!vec[i])
		for(int j=i*i;j<=x;j+=i) vec[j]=1;
	rep(i,0,x) if(vec[i]==0) prime.push_back(i);
}
map<int,int> moebius(int n){
	map<int,int> res;
	vector<int> pr;
	for(int i:prime)
		if(i*i>n) break;
		else if(n%i==0) {
			pr.push_back(i);
			while(n%i==0) n/=i;
		}
	if(n>1) pr.push_back(n);
	rep(i,0,1<<pr.size()){
		int mu=1,d=1;
		rep(j,0,pr.size()) if((1<<j)&i) d*=pr[j],mu*=-1;
		res[d]=mu;
	}
	return res;
}
int main(){
	seive(2e9);
	int n;
	while(~scanf("%d",&n)){
		auto ret=moebius(n);
		for(auto i:ret) printf("%d %d\n",i.first,i.second);
	}
}