#include<stdio.h>
void move(int *p,int n,int m) {
	for(int i=0; i<m; i++) for(int j=n-2; j>=0; j--)
			(*(p+j))^=(*(p+j+1))^=(*(p+j))^=(*(p+j+1));
}
int main() {
	int a[666] = {0},n,m,i=0;
	scanf("%d%d",&n,&m);
	while(i<n) scanf("%d",&a[i++]);
	move(a,n,m);
	for(i=0; i<n; i++) printf("%d ",a[i]);
}
