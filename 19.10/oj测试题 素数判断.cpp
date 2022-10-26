#include<stdio.h>
#include<math.h>
int prime(int m){
	int j,q;
	q=sqrt(m);
	for (j=2;j<=q;j++){
	if (m%j==0) return 0;}
	return 1;}
int main(){
	int n,x,y,flag=1;
	while(1) {
	scanf("%d%d",&x,&y);
	if (x==0&&y==0) break;
	for (n=x;n<=y;n++)
		{flag=prime(n*n+n+41);if (flag==0) {printf("Sorry\n");break;}}
	if (flag==1) printf("OK\n");}}
