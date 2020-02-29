#include<stdio.h>
#include<string.h>
#define maxn (int)1e5+8
char pattern[maxn]= {0},text[maxn]= {0};
int next[maxn]= {0};
void Next(char *s,int *fail) {
	fail[0]=-1,fail[1]=0;
	int len=strlen(s);
	for(int i=1,j=0;i<len&&j<len;) {
		if(j==-1||s[i]==s[j])fail[++i]=++j;
		else j=fail[j];
	}
}
int KmpSearch(char* s, char* p) {
	int i = 0,j = 0,sLen = strlen(s),pLen = strlen(p);
	while (i < sLen && j < pLen) {
		if (j == -1 || s[i] == p[j]) 
			i++,j++;
		else j = next[j];
	}
	return j == pLen?i - j:-1;
}
int main() {
	scanf("%s%s",pattern,text);
	Next(pattern,next);
	printf("%d\n",KmpSearch(text,pattern));
}
