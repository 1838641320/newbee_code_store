#include"s.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a,bb=b;i<bb;i++)
using namespace std;
typedef long long ll;
mt19937 rd;
void radixsort(vector<ll>&a,int num){
	vector<queue<ll>> buck(num);
	ll maxv=*max_element(a.begin(),a.end());
	int len=1;
	while(maxv) {
		for(ll i:a) 
			buck[i/len%num].push(i);
		vector<ll> b;
		for(int i=0;i<num;i++){
			auto &bu=buck[i];
			while(bu.empty()==0) b.push_back(bu.front()),bu.pop();
		}
		len*=num;maxv/=num;
		a=b;
	}
}
int main() {
	rd.seed(time(0));
	vector<ll> vec;
	for(int i=0;i<66666;i++) 
		vec.push_back(abs(ll(rd())));
	puts("ready");getchar();
	radixsort(vec,10);
	for(int i=0;i<vec.size();i++)
		printf("%lld%c",vec[i],(i+1)%10?' ':'\n');
}