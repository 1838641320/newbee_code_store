#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int n,a,k,ans = 0;
vector<int> num;
map<int,int> in;
int judge(int k) {
	int sum = k,it = 0;
	if (upper_bound(num.begin(),num.end(),k-1)==num.end()) return 0;
	for(;it!=num.size();it++) {
		if (k>num[it]) 
			it = upper_bound(num.begin(),num.end(),k-1)-num.begin();
		if (it==num.size()) break;
		ans = max(ans,sum);
		k <<= 1;
		sum += k;
	}
	return 1;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin>>n;
	for (int i = 0;i<n;i++) {
		scanf("%d",&a);
		in[a+1]++;
	}
	for (auto i:in) num.push_back(i.second);
	sort(num.begin(),num.end());
	int start = 1;
	for (;start<=n;start++) {
		if (judge(start)==0) break;
	}
	cout<<ans;
}