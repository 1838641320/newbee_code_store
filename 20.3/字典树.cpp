#include"stdafx.h"
#include<bits/stdc++.h>
using namespace std;
struct trie {
	int nex[100000][26],cnt,exist[100000];
	void insert(string s,int k) {
		int p=0;
		for (int i=0; i<s.length(); i++) {
			int c=s[i]-'a';
			if (!nex[p][c]) nex[p][c]=++cnt;
			p=nex[p][c];
		}
		exist[p]=k;
	}
	int find(string s) {
		int p=0;
		for (int i=0; i<s.length(); i++) {
			int c=s[i]-'a';
			if (!nex[p][c]) return 0;
			p=nex[p][c];
		}
		return exist[p];
	}
};
trie dt;
int main() {
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		string s;
		cin>>s;
		dt.insert(s,i);
	}
	for (int i=0;i<m;i++) {
		string s;
		cin>>s;
		cout<<dt.find(s)<<'\n';
	}
}