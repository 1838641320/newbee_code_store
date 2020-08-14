#include<cstdio>
#include<algorithm>
#define rep(i,a,b) for(unsigned i=a;i<b;i++)
const unsigned maxn=5e6+9,base=29;
char s[maxn]={};
int n,__;
unsigned p[maxn]={},ori[maxn]={},mp[maxn],cnt[130],ha;
int judge(int len){
	unsigned k=n/len,sz=0,cnt2[130]={};
	ha=0;
	rep(i,0,len) ha=ha*base+s[i],cnt2[s[i]]++;
	rep(i,'a','z'+1) if(cnt2[i]*k!=cnt[i]) return 0;
	mp[sz++]=ha;
	rep(i,0,len) {
		ha=ha*base+s[i]-s[i]*p[len];
		mp[sz++]=ha;
	}
	std::sort(mp,mp+sz);
	rep(i,1,k) {
		ha=ori[i*len+len-1]-ori[i*len-1]*p[len];
		if(*std::lower_bound(mp,mp+sz,ha)!=ha) return 0;
	}
	return 1;
}
void solve(){
	scanf("%d",&n);getchar();
	fgets(s,maxn,stdin);
	rep(i,'a',128) cnt[i]=0;
	rep(i,0,n) {
		ha=ha*base+s[i];
		ori[i]=ha;
		cnt[s[i]]++;
	}
	rep(i,1,n) if(n%i==0) 
		if(judge(i)) return (void)puts("Yes");
	puts("No");
}
int main(){
	p[0]=1;
	rep(i,1,maxn) p[i]=p[i-1]*base;
	scanf("%d",&__);
	while(__--) solve();
}