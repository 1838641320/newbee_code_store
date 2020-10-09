#include<bits/stdc++.h>
// #include<cstdio>
// #include<cstring>
// #include<cstdlib>
#define rep(i,a,b) for(int i=a,bb=b;i<bb;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
ll gcd(ll x,ll y){while(y^=x^=y^=x%=y);return x;}
using namespace std;
//-----------------
int op[300]={};
int isdecimal(char *s){
	if(isdigit(*s)||*s=='.') return 1;
	if(op[*s--]==1) {
		while(*s=='('||*s==')') s--;
		return op[*s];
	}
	return 0;
}
char res[300]={},s[300]={};
void repolish(char *s,char *p){
	op[0]=99;
	op['+']=op['-']=1;
	op['*']=op['/']=2;
	stack<char> st;
	while(*s){
		if(isdecimal(s)){
			if(*s!='+') *p++=*s++;
			else s++;
			while(isdigit(*s)||*s=='.')
				*p++=*s++;
			*p++=' ';
			continue;
		}
		char c=*s++;
		if(c=='(') {st.push(c);continue;}
		while(op[c]){
			if(!st.size()||st.top()=='('||op[c]>op[st.top()]){
				st.push(c);break;
			}
			else *p++=st.top(),st.pop(),*p++=' ';
		}
		if(c==')'){
			while(st.top()!='(')
				*p++=st.top(),st.pop(),*p++=' ';
			st.pop();
		}
	}
	while(st.size()) *p++=st.top(),st.pop(),*p++=' ';
	*--p=0;
}
int main(){
	scanf("%s",s+1);
	repolish(s+1,res);
	puts(res);
}