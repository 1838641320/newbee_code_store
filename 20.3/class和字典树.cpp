#include"stdafx.h"
#include<bits/stdc++.h>
using namespace std;
class Trie {
public:
	struct node {
		int num;
		map<char,int> next;
	};
	vector<node> dt;
	Trie() { dt.push_back({}); };
	void insert(string &s,int k) {
		int p=0;
		for (char i:s) {
			if (dt[p].next[i]) p=dt[p].next[i];
			else {
				dt[p].next[i]=dt.size();
				p=dt.size();
				dt.push_back({});
			}
		}
		dt[p].num=k;
	}
	int find(string &s) {
		int p=0;
		for (char i:s) {
			int ne=dt[p].next[i];
			if (ne) p=ne;
			else return 0;
		}
		return dt[p].num;
	}
};
int main() {
	Trie three;
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		string s;
		cin>>s;
		three.insert(s,i);
	}
	for (int i=0;i<m;i++) {
		string s;
		cin>>s;
		cout<<three.find(s)<<'\n';
	}
}