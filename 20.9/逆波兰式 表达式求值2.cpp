#include<bits/stdc++.h>
using namespace std;
const int maxn=3e3+9;
char in[maxn] = {},res[maxn];
double cal(double x,double y,char c) {
	if (c=='+') return x+y;
	if (c=='-') return x-y;
	if (c=='*') return x*y;
	if (c=='/') return x/y;
	if (c=='^') return pow(x,y);
	return 0;
}
inline int op(char a) {
	if (a=='+'||a=='-') return 1;
	if (a=='*'||a=='/') return 2;
	if (a=='^') return 3;
	return 0;
}
void repolish(char *s,char *p) {
	char st[maxn]={};
	int top=0;
	for(;*s!='\n';) {
		if(isdigit(*s)||*s=='.') {
			while(isdigit(*s)||*s=='.')
				*p++=*s++;
			*p++=' ';
			continue;
		}
		char c=*s++;
		if (c=='(') {st[top++]=c;continue;}
		while(op(c)) {
			if (!top||st[top-1]=='('||op(c)>op(st[top-1])) {
				st[top++]=c;
				break;
			}
			else *p++=st[--top];
		}
		if(c==')') {
			while (st[top-1]!='(')
				*p++=st[--top];
			top--;
		}
	}
	while (top) *p++=st[--top];
	*p=0;
}
double cal_repolish(char *s) {
	double ans[maxn]={},a,b;
	int top=0;
	while (*s) {
		while(*s==' ') s++;
		if (isdigit(*s)||*s=='.') 
			ans[top++]=strtod(s,&s);
		if(op(*s)) {
			b=ans[--top];
			if(top) a=ans[--top];
			else a=0;
			ans[top++]=cal(a,b,*s++);
		}
	}
	return ans[top-1];
}
int main() {
	while (fgets(in,maxn-1,stdin)) {
		repolish(in,res);
		printf("%lf\n",cal_repolish(res));
	}
}