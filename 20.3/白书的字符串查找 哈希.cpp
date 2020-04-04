#include"stdafx.h"
#include<cstring>
#include<iostream>
using namespace std;
typedef unsigned long long ull;
const ull B = 100000097;
int contain(string &a,string &b) {
	int al = a.length(),bl = b.length();
	if (al>bl) return 0;
	ull t = 1;
	for (int i = 0;i<al;i++) t *= B;
	ull ah = 0,bh = 0;
	for (int i = 0;i<al;i++) ah = ah*B+a[i];
	for (int i = 0;i<al;i++) bh = bh*B+b[i];
	for (int i = 0;i+al<=bl;i++) {
		if (ah==bh) return 1;
		if (i+al<bl) bh = bh*B+b[i+al]-b[i]*t;
	}
	return 0;
}
int main() {
	string s1,s2;
	cin>>s1>>s2;// bc abc 
	if (contain(s1,s2)) 
		cout<<"s2包含s1"<<endl;
	else 
		cout<<"s2不包含s1"<<endl;
}