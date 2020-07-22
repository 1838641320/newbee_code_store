#include"s.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=1e6+9;
char s[maxn]={};
int d[maxn]={};
void lyndon(char *s,int len){
	for(int i=1;i<=len;){
		int j=i,k=j+1;
		d[i]=i;
		while(k<=len&&s[k]>=s[j]){
			if(s[k]>s[j]) j=i,d[k]=i;
			else d[k]=d[j]+k-j,j++;
			k++;
		}
		while(i<=j) i+=k-j;
	}
}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%s",s+1);
		int len=strlen(s+1);
		lyndon(s,len);
		ll ans=0;
		for(int i=len;i;i--) ans=(ans*1112ll+d[i])%mod;
		printf("%lld\n",ans);
	}
}