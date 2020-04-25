#include"pch.h"
#include<bits/stdc++.h>
typedef long long ll;
ll M=998244353,f[999999],n,m;
ll q(ll x,ll n) { ll c=1;for (x%=M;n;n/=2,x=(x*x)%M) if (n&1) c=(c*x)%M;return c; }
int main() { std::cin>>n>>m;f[0]=1;
	for (ll i=1;i<=m;i++) f[i]=(f[i-1]*i)%M;
	std::cout<<((n-2)%M*q(2,n-3)%M*f[m]%M*q(f[n-1]*f[m-n+1],M-2))%M;}