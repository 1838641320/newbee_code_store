#include<stdio.h>
int main(){
	int i,a[12],n;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<(n-1)/2;i++) a[i]^=a[n-1-i]^=a[i]^=a[n-1-i];
	for(i=0;i<n;i++) printf("%d ",a[i]);}
