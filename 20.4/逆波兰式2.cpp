#include"pch.h"
#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof a)
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
char s[3000]={};
double cal(double x,double y,char c) {
	if (c=='+') return x+y;
	if (c=='-') return x-y;
	if (c=='*') return x*y;
	if (c=='/') return x/y;
	if (c=='^') return pow(x,y);
	if (c=='_') return log(y)/log(x);
	return 0;
}
inline int op(char a) {
	if (a=='+'||a=='-') return 1;
	if (a=='*'||a=='/') return 2;
	if (a=='^'||a=='_') return 3;
	return 0;
}
void repolish(deque<char> &res,deque<double> &resn,char *s) {
	stack<char> st;
	while (1) {
		if (*s>='0'&&*s<='9') {
			double a=strtod(s,&s);
			res.push_back('n');
			resn.push_back(a);
			continue;
		}
		char c=*s++;
		if (c=='\n') break;
		if (c=='(') { st.push(c);continue; }
		while (op(c)) {
			if (st.empty()||st.top()=='('||op(c)>op(st.top())) {
				st.push(c);
				break;
			}
			else res.push_back(st.top()),st.pop();
		}
		if (c==')') {
			while (st.top()!='(')
				res.push_back(st.top()),st.pop();
			st.pop();
		}
	}
	while (!st.empty()) { res.push_back(st.top());st.pop(); }
}
double cal_repolish(deque<char> &res,deque<double> &resn) {
	stack<double> ans;
	while (!res.empty()) {
		if (res.front()=='n') {
			ans.push(resn.front());
			resn.pop_front();
			res.pop_front();
		}
		else {
			double a,b;
			b=ans.top(),ans.pop();
			if (!ans.empty()) a=ans.top(),ans.pop();
			else a=0;
			ans.push(cal(a,b,res.front()));
			res.pop_front();
		}
	}
	return ans.top();
}
int main() {
	deque<char> res;
	deque<double>resn;
	while (fgets(s,9999,stdin)) {
		res.clear();
		resn.clear();
		repolish(res,resn,s);
		cout<<cal_repolish(res,resn)<<'\n';
	}
}