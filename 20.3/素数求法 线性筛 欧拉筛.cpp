#include"stdafx.h"
#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+9;
vector<int> prime;
char no[N] = {};
void make(int n) {
	for (int i = 2;i<=n;i++) {
		if (!no[i])
			prime.push_back(i);
		for (int j = 0;j<prime.size()&&prime[j]*i<=n;j++) {
			no[prime[j]*i] = 1;
			if (i%prime[j]==0) break;
		}
	}
}
int main() {
	make(N-9);
	string out;
	char temp[10];
	for (int i:prime) sprintf(temp,"%7d ",i),out+=temp;
	cout<<out<<'\n'<<out.length();
}