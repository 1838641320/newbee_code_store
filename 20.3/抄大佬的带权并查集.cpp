#include"stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int s[maxn],d[maxn]={},par[maxn];
int T,N;
int find(int x) {
	if (x==par[x]) return x;
	int t = find(par[x]);
	d[x] = d[t];
	return t;
}
void unite(int a,int b) {
	int x = find(a);
	int y = find(b);
	if (x==y)return;
	par[y] = x;
	d[x] += d[y];
}
int main() {
	while (cin>>T) {
		while (T--) {
			cin>>N;
			for (int i = 0; i<maxn; i++) par[i] = i,d[i]=1;
			for (int i = 1; i<=N; i++) {
				cin>>s[i];
				unite(i,s[i]);
			}
			for (int i = 1; i<=N; i++) {
				if (i!=N)cout<<d[find(i)]<<" ";
				else cout<<d[find(i)]<<endl;
			}
		}
	}
}