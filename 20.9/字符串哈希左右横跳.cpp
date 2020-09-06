#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
using ull=unsigned long long;
using ll=long long;
using lll=__int128_t;
const ull b=1e9+97,invb=7754385056447814049llu;
char s[9999];
ull pp[9999]={};
int main(){
	pp[0]=1;
	rep(i,1,9999) pp[i]=pp[i-1]*b;
	scanf("%s",s);
	int len;scanf("%d",&len);
	ull ha=0;
	rep(i,0,len) ha=ha*b+s[i];
	char in[6];
	int p=0;
	while(scanf("%s",in)==1){
		if(in[0]=='l'){
			p--;
			ha=(ha-s[p+len])*invb+s[p]*pp[len-1];
			printf("%llu\n",ha);
		}
		if(in[0]=='r'){
			ha=ha*b+s[p+len]-s[p]*pp[len];
			p++;
			printf("%llu\n",ha);
		}
	}
}