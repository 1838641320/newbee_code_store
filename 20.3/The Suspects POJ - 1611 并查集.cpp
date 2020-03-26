#include<cstdio>
const int maxn = 30009;
int sick[maxn],m,n;
inline int find(int x) { return sick[x]==x?x:(sick[x] = find(sick[x])); }
inline void unite(int x,int y) { if ((x = find(x))!=(y = find(y))) sick[x] = y; }
int main() {
	while (scanf("%d%d",&n,&m),n|m) {
		int ans = 1,ill,i,num,fir,peo;
		for (i = -1;i++<n;) sick[i] = i;
		while (m--) {
			scanf("%d %d",&num,&fir);
			while (--num) scanf("%d",&peo),unite(peo,fir);
		}
		for (ill = find(0),i = 0;i++<n;) ans += ill==find(i);
		printf("%d\n",ans);
	}
}