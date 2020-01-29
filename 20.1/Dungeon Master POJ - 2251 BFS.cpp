#include<cstdio>
#include<queue>
#include<cstring>
#define change [n.x+dx[i]][n.y+dy[i]][n.z+dz[i]]
#define ori [n.x][n.y][n.z]
using namespace std;
typedef struct {
	int x, y, z;
}P;
char maze[32][32][32]={0};
const int dx[]={1,-1,0,0,0,0},dy[]={0,0,1,-1,0,0},dz[]={0,0,0,0,1,-1};
int len[32][32][32],L,R,C,i;
queue<P> route;
int main() {
	P s,e,n;
	while (scanf("%d%d%d%*c",&L,&R,&C),L|R|C){
		memset(len,0x3f,32*32*32*4);
		memset(maze,0,32*32*32);
		for (int i=1;i<=L;getchar(),i++)for(int j=1;j<=R;getchar(),j++) for (int k=1;k<=C;k++){
			maze[i][j][k]=getchar();
			if (maze[i][j][k]=='S') s={i,j,k};
			if (maze[i][j][k]=='E') e={i,j,k};
		}
		len[s.x][s.y][s.z]=0;
		route.push(s);
		while (!route.empty()){
			n=route.front();
			route.pop();
			for (i=0;i<6;i++){
				char c=(maze change);
				if ((c=='.'||c=='E')&&(len change)>(len ori)+1) {
					P t={n.x+dx[i],n.y+dy[i],n.z+dz[i]};
					route.push(t);
					(len change)=(len ori)+1;
				}
			}
		}
		if (len[e.x][e.y][e.z]==0x3f3f3f3f) puts("Trapped!");
		else printf("Escaped in %d minute(s).\n",len[e.x][e.y][e.z]);
	}
}
