#include<cstring>
#include<algorithm>
#include<iostream>
#include<ctime>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
ll gcd(ll x,ll y){while(y^=x^=y^=x%=y);return x;}
using namespace std;
//-----------------
const int maxn=3e2+9;
int op[300]={};
int isdecimal(char *s){
	if(isdigit(*s)||*s=='.') return 1;
	if(op[*s--]==1) {
		while(*s=='('||*s==')') s--;
		return op[*s];
	}
	return 0;
}
char res[maxn]={},s[maxn]={};
void repolish(char *s,char *p){
	op[0]=99;
	op['+']=op['-']=1;
	op['*']=op['/']=2;
	char st[maxn];int top=0;
	while(*s){
		while(*s==' ') s++;
		if(isdecimal(s)){
			if(*s++!='+') *p++=s[-1];
			while(isdigit(*s)||*s=='.')
				*p++=*s++;
			*p++=' ';
			continue;
		}
		char c=*s++;
		if(c=='(') {st[top++]=c;continue;}
		while(op[c]){
			if(!top||st[top-1]=='('||op[c]>op[st[top-1]]){
				st[top++]=c;break;
			}
			else *p++=st[--top],*p++=' ';
		}
		if(c==')'){
			while(st[top-1]!='(')
				*p++=st[--top],*p++=' ';
			top--;
		}
	}
	while(top) *p++=st[--top],*p++=' ';
	*--p=0;
}
int main(){
	scanf("%s",s+1);
	repolish(s+1,res);
	puts(res);
}