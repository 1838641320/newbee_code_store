#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
int ans[9999+8],prime[9999+8] = {0};
int n,s,e,p = 0;
int j_p(int n) {
	for (int j = 2,t = sqrt(n);j<=t;j++) if (n%j==0) return 0;
	return 1;
}
inline void Pri() {
	for (int i = 1000;i<9999;i++) if (j_p(i)) prime[p++] = i;
}
inline int is_pri(int n) { return n==*lower_bound(prime,prime+p,n); }
void bfs(int s) {
	queue<int> qu;
	qu.push(s);
	while (1) {
		int it = qu.front();qu.pop();
		if (it==e) break;
		int b = (it/1000)*1000+it%100,c = (it/100)*100+it%10,d = (it/10)*10;
		for (int i = it%1000+1000;i<9999;i += 1000)
			if (is_pri(i)&&ans[i]==0x3f3f3f3f)
				qu.push(i),ans[i] = ans[it]+1;
		for (int i = 0;i<999;i += 100)
			if (is_pri(i+b)&&ans[i+b]==0x3f3f3f3f)
				qu.push(i+b),ans[i+b] = ans[it]+1;
		for (int i = 0;i<99;i += 10)
			if (is_pri(i+c)&&ans[i+c]==0x3f3f3f3f)
				qu.push(i+c),ans[i+c] = ans[it]+1;
		for (int i = 0;i<=9;i++)
			if (is_pri(i+d)&&ans[i+d]==0x3f3f3f3f)
				qu.push(i+d),ans[i+d] = ans[it]+1;
	}
}
int main() {
	Pri();
	cin>>n;
	while (n--) {
		memset(ans,0x3f,sizeof(ans));
		cin>>s>>e;
		ans[s] = 0;
		bfs(s);
		cout<<ans[e]<<'\n';
	}
}