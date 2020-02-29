#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
typedef pair<int,int> P;
const int maxn = 1e2+8,d[8][2] = {{1,1},{0,1},{-1,1},{1,0},{-1,0},{1,-1},{0,-1},{-1,-1}};
int n,m,i,j;
char f[maxn][maxn];
int s() {
	int ans = 0;
	for (int i = 0;i<n;i++) for (int j = 0;j<m;j++) if (f[i][j]=='@') {
		f[i][j] = '*';
		ans++;
		stack<P> search;
		search.push({i,j});
		while (!search.empty()) {
			P p = search.top();search.pop();
			for (int k = 0;k<8;k++) {
				int x = p.first+d[k][0],y = p.second+d[k][1];
				if (x<0||y<0||x>=n||y>=m) continue;
				if (f[x][y]=='@') search.push({x,y});
				f[x][y] = '*';
			}
		}
	}
	return ans;
}
int main() {
	while (~scanf("%d%d%*c",&n,&m),n|m) {
		memset(f,0,sizeof(f));
		for (int i = 0;i<n;i++)
			scanf("%s",f[i]);
		printf("%d\n",s());
	}
}