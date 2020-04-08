#include<stdio.h>
#include<string.h>
#define maxn (int)1e5+9
char s[maxn]={},p[maxn]={};
int next[maxn]={},ls,lp;
void get_next(char *p,int *next){
	next[0]=-1,next[1]=0;
	for(int i=1,j=0;i<lp;){
		if(j==-1||s[i]==s[j]) next[++i]=++j;
		else j=next[j];
	}
}
int kmp_search(char *s,char *p,int *next){
	int i=0,j=0;
	for(;i<ls&&j<lp;){
		if(j==-1||s[i]==p[j]) i++,j++;
		else j=next[j];
	}
	return j==lp?i-j:-1;
}
int main(){
	while(scanf("%s%s",s,p)==2){
		ls=strlen(s),lp=strlen(p);
		memset(next,0,sizeof(next));
		get_next(p,next);
		printf("%d\n",kmp_search(s,p,next));
	}
}
