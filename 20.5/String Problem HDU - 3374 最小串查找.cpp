//#include"s.h"
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn=1e6+9;
int ne[maxn]={},len;
char s[maxn]={};
void getnext(char *p,int *ne){
	int i=0,j=-1;
	ne[0]=-1;
	while (i<len)
		if (j==-1||p[i]==p[j])
			ne[++i]=++j;
		else j=ne[j];
}
int les(char a,char b,int ty){
	return ty?a<b:b<a;
}
int getmost(char *p,int ty){
	int i=0,j=1,k=0;
	while (j<len&&k<len){
		char a=p[(i+k)%len],b=p[(j+k)%len];
		if (a==b) { k++;continue; }
		if (les(a,b,ty))
			j+=k+1;
		if (les(a,b,!ty))
			i+=k+1;
		k=0;
		if (i==j) j++;
	}
	return i;
}
int main(){
	while (scanf("%s",s)==1){
		len=strlen(s);
		getnext(s,ne);
		int cy=len-ne[len];
		int times=len%cy?1:(len/cy);
		len/=times;
		int mi=getmost(s,1),ma=getmost(s,0);
		printf("%d %d %d %d\n",mi+1,times,ma+1,times);
	}
}