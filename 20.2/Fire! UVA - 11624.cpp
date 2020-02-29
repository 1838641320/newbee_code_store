#include<cstdio>
#include<cstring>
#include<stack>
#define all(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef pair<int,int> P;
const int maxn = 1e3+8;
const P d[] = {{0,1},{0,-1},{-1,0},{1,0}};
char maze[maxn][maxn];
int n,r,c,ans;
stack<P> F[2],J[2];//fire,joe
int s() {
	all(i,r) all(j,c) {
		if (maze[i][j]=='J') J[1].push({i,j});
		if (maze[i][j]=='F') F[1].push({i,j});
	}
	for (int i = 1;;i++) {
		if (J[i%2].size()==0) return 0;
		while (J[i%2].size()) {
			int x = J[i%2].top().first,y = J[i%2].top().second;
			J[i%2].pop();
			if (maze[x][y]=='F') continue;
			if ((x==1||x==r||y==1||y==c)&&maze[x][y]=='J') return i;
			for (int k = 0;k<4;k++) {
				int dx = x+d[k].first,dy = y+d[k].second;
				if (maze[dx][dy]=='.')
					maze[dx][dy] = 'J',
					J[(i+1)%2].push({dx,dy});
			}
		}
		while (F[i%2].size()) {
			int x = F[i%2].top().first,y = F[i%2].top().second;
			F[i%2].pop();
			if (x==0||x==r+1||y==0||y==c+1) continue;
			for (int k = 0;k<4;k++) {
				int dx = x+d[k].first,dy = y+d[k].second;
				if (maze[dx][dy]=='.'||maze[dx][dy]=='J')
					maze[dx][dy] = 'F',
					F[(i+1)%2].push({dx,dy});
			}
		}
	}
}
int main() {
	scanf("%d",&n);
	while (n--) {
		while (!F[0].empty())F[0].pop();
		while (!F[1].empty())F[1].pop();
		while (!J[1].empty())J[1].pop();
		while (!J[0].empty())J[0].pop();
		ans = 0;
		memset(maze,0,sizeof(maze));
		scanf("%d%d%*c",&r,&c);
		for (int i = 1;i<=r;getchar(),i++)
			for (int j = 1;j<=c;j++)
				maze[i][j] = getchar();
		ans = s();
		if (!ans) puts("IMPOSSIBLE");
		else printf("%d\n",ans);
	}
}