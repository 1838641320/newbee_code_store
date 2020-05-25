#include"p.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn=100000+9;
typedef long long ll;
ll a[maxn]={},ps[maxn]={},n,up=0,dw=0;
int main() {
	cin>>n;
	rep(i,0,n) scanf("%lld",a+i);
	adjacent_difference(a,a+n,ps);
	rep(i,1,n)
		if (ps[i]>0) up+=ps[i];
		else dw-=ps[i];
	printf("%lld",max(up,dw));
}