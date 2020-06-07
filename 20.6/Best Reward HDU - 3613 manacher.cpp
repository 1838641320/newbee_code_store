#include"s.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn=5e5+9;
char s[maxn*2];
int p[maxn*2],value[300],tsum,sum,len;
void manachar() {
	memset(p,0,sizeof(p));
	len=strlen(s);
	int id=0;
	for (int i=len; i>=0; i--) {
		s[i*2+2]=s[i];
		s[i*2+1]='#';
	}
	s[0]='*';
	for (int i=2; i<2*len+1; i++) {
		if (p[id]+id>i)
			p[i]=min(p[2*id-i],p[id]+id-i);
		else
			p[i]=1;
		while (s[i-p[i]]==s[i+p[i]])
			p[i]++;
		if (id+p[id]<i+p[i])
			id=i;
	}
}
void solve(){
	rep(i,'a','z'+1) scanf("%d",value+i);
	scanf("%s",s);
	manachar();
	int ans=0;
	len=len*2+2;
	tsum=0;sum=value[s[2]];
	for (int i=4; i<len; i+=2)
		tsum+=value[s[i]];
	for (int i=4; i<len; i+=2) {
		int left=i/2,right=(i+len-1)/2;
		int t=sum*(p[left]==left)+tsum*(right+p[right]==len);
		ans=max(ans,t);
		sum+=value[s[i]];
		tsum-=value[s[i]];
	}
	printf("%d\n",ans);
}
int main(){
	int t;cin>>t;
	while (t--) solve();
}