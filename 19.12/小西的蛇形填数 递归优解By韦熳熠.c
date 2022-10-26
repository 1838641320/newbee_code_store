#include<stdio.h>
int a[101][101];
void fn(int n,int u,int o) {
	int i,j;
	if(n>=2) {
		for(i=u; i<=n-1; i++,o++) a[i][n-1]=o;
		for(i=n-2; i>=u; i--,o++) a[n-1][i]=o;
		for(j=n-2; j>=u; j--,o++) a[j][u]=o;
		for(j=u+1; j<n-1; j++,o++) a[u][j]=o;
		u++;
		fn(n-1,u,o);
	}
}
int main(void) {
	int n,m,i,j,u,o,k;
	while(scanf("%d",&n)!=EOF) {
		u=0;o=1;
		fn(n,u,o);
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++)
				printf("%d ",a[i][j]);
			puts("");
		}
	}
}
