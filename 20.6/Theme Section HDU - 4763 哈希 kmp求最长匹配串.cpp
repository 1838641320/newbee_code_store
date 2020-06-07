#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const ull B=1e9+97;
const int maxn=1e6+9;
char s[maxn],p[maxn/3+9];
int len,plen,ne[maxn/3+9];
void getnext(){
	int i=0,j=-1;ne[0]=-1;
	while(i<plen)
		if(j==-1||p[j]==p[i])
			ne[++i]=++j;
		else j=ne[j];
}
int kmp(){
	getnext();
	int i=0,j=0,res=0;
	while(i<len&&j<plen)
		if(j==-1||s[i]==p[j])
			++i,++j,res=max(res,j);
		else j=ne[j];
	return res;
}
int solve(){
	scanf("%s",s);
	len=strlen(s);
	if(len<3) return puts("0");
	ull ah=0,bh=0,t=1;
	plen=0;
	for(int k=0;k*3<len;k++){
		ah=ah*B+s[k];
		bh=bh+s[len-k-1]*t;
		if(ah==bh) plen=k+1;
		t*=B;
	}
	if(!plen) return puts("0");
	memcpy(p,s,plen);
	for(int i=0;i<plen;i++) {
		s[i]='.';
		s[len-i-1]='.';
	}
	printf("%d\n",kmp());
}
int main(){
	int t;cin>>t;
	while(t--) solve();
}