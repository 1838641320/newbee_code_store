#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int maxn = 2e5+8;
map<int,int> mp;
int n,m,i,j,mid;
int main() {
	scanf("%d%d",&n,&m);
	for (i = 1;i<=n;i++) 
		scanf("%d",&j),
		mp[j]++;
	int lb = 1,ub = n;
	while (ub>=lb) {
		mid = (lb+ub)>>1;
		int cnt = 0;
		for (auto i:mp) cnt += i.second/mid;
		if (cnt>=m)
			lb = mid+1;
		else
			ub = mid-1;
	}
	int cnt = 0;
	for(auto i:mp) 
		for (j = ub;j<=i.second;j += ub) {
			printf("%d ",i);
			cnt++;
			if (cnt==m) return 0;
		}
}