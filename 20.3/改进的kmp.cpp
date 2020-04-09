#include"stdafx.h"
#include<stdio.h>
#include<string.h>
#define maxn (int)1e5+8
char pattern[maxn]={0},text[maxn]={0};
int nextval[maxn]={0};
void Next(char *p,int *next) {
	next[0]=-1;
	int len=strlen(p);
	for (int i=1,j=0;i<len;) {
		if (j==-1||p[i]==p[j])
			next[i]=p[++i]==p[++j]?next[j]:j;
		else j=next[j];
	}
}
int KmpSearch(char *s,char *p,int *next) {
	int i=0,j=0,sLen=strlen(s),pLen=strlen(p);
	while (i<sLen&&j<pLen) {
		if (j==-1||s[i]==p[j])
			i++,j++;
		else j=next[j];
	}
	return j==pLen?i-j:-1;
}
int main() {
	scanf("%s%s",text,pattern);
	Next(pattern,nextval);
	printf("%d\n",KmpSearch(text,pattern,nextval));
}