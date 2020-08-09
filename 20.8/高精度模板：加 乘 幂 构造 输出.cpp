#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

namespace Bigint{
	typedef long long ll;
	typedef vector<ll> Int;
	const ll bi=1e8;
	void print(Int a){
		printf("%lld",a[a.size()-1]);
		for(int i=a.size()-2;~i;i--) printf("%08lld",a[i]);
	}
	inline ll adc(ll a,ll &carry){
		a+=carry;
		carry=a/bi;
		return a%bi;
	}
	Int mul(Int a,Int b){
		Int c(a.size()+b.size()+2);
		for(int i=0;i<a.size();i++){
			ll carry=0;
			for(int j=0;j<b.size();j++) 
				c[i+j]=adc(c[i+j]+a[i]*b[j],carry);
			if(carry) c[i+b.size()]+=carry;
		}
		while(c.size()>1&&c[c.size()-1]==0) c.pop_back();
		return c;
	}
	Int mul(Int a,ll b){//b<=bi
		Int c=a;
		ll carry=0;
		for(int i=0;i<c.size();i++)
			c[i]=adc(c[i]*b,carry);
		if(carry) c.push_back(carry);
		return c;
	}
	Int add(Int a,Int b){
		if(b.size()>a.size()) swap(a,b);
		Int c=a;
		ll carry=0;
		for(int i=0;i<b.size();i++) 
			c[i]+=b[i];
		for(int i=0;i<c.size();i++) 
			c[i]=adc(c[i],carry);
		if(carry) c.push_back(carry);
		return c;
	}
	Int make(char *s){
		Int a;
		for(int i=strlen(s)-8;i>=0;i-=8)
			a.push_back(atoll(s+i)),
			s[i]=0;
		if(s[0]) a.push_back(atoll(s));
		return a;
	}
	Int ksm(Int a,ll n){
		Int c=make((char*)"1");
		for(;n;n/=2,a=mul(a,a)) if(n&1) c=mul(c,a);
		return c;
	}
}

using namespace Bigint;
char in[9999]={},in2[9999]={};
int main(){
	while(puts("next 2 number:"),scanf("%s%s",in,in2)==2){
		auto a=make(in),b=make(in2);
		print(mul(a,b));puts("");
		print(add(a,b));puts("");
		ll n;
		if(scanf("%lld",&n)==1) print(ksm(a,n));puts("");
	}
}