#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn=1000009;
char src[maxn*2];
int p[maxn*2];
int manacher(){
	int len;
	len=strlen(src);
	for (int i=len;i>=0;i--){
		src[i*2+2]=src[i];
		src[i*2+1]='#';
	}
	src[0]='(';
	len=len*2+2;
	for (int i=2,id=0,mx=0;i<len;i++){
		if (i<mx)
			p[i]=min(p[2*id-i],mx-i);
		else p[i]=1;
		while (src[i-p[i]]==src[i+p[i]])
			p[i]++;
		if (i+p[i]>mx){
			id=i;
			mx=i+p[i];
		}
	}
	return *max_element(p+2,p+len)-1;
}
int main(){
	int cases=1;
	while (scanf("%s",src),strcmp(src,"END"))
		printf("Case %d: %d\n",cases++,manacher());
}