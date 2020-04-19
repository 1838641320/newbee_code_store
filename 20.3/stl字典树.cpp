#include"stdafx.h"
#include<bits/stdc++.h>
using namespace std;
class Trie {
public:
	struct node {
		vector<int> num;
		map<char,int> next;
	};
	vector<node> dt;
	int total_words=0;
	Trie() { dt.push_back({}); };
	void insert(string &s) {
		int p=0;
		for (char i:s) {
			if (dt[p].next[i]) p=dt[p].next[i];
			else {
				dt[p].next[i]=dt.size();
				p=dt.size();
				dt.push_back({});
			}
		}
		dt[p].num.push_back(++total_words);
	}
	vector<int> find(string &s) {
		int p=0;
		for (char i:s) {
			int ne=dt[p].next[i];
			if (ne) p=ne;
			else return {};
		}
		return dt[p].num;
	}
};
int main() {
	Trie trie;
	string s;
	while (cin>>s,s[0]!='.') trie.insert(s);
	cout<<"insertion completed"<<'\n'<<"totle words:"<<trie.total_words<<'\n';
	while (cin>>s) {
		auto res=trie.find(s);
		for (int i:res) cout<<i<<' ';
		puts("");
	}
}