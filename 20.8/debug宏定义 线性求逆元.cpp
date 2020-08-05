#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
#define debug(x) {for(auto i:x) cout<<i<<' ';cout<<#x<<endl;}
#define de(x) cout<<#x" "<<x<<endl;
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int main(){
	int n;scanf("%d",&n);
	int a[n];
	a[0]=a[1]=1;
	rep(i,2,n) a[i]=mod-mod/i*a[mod%i]%mod;
	debug(a);
	int sdfsdf=4545;
	de(sdfsdf);
}