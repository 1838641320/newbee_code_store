#include<stdio.h>
#define combinatorial(m,n) (fact(n)/(fact(m)*fact(n-m)))
long long fact(int n){long long i,product=1;for (i=1;i<=n;i++) product*=i;return product;}
int main(){
int line,column,N;
scanf("%d",&N);
for (line=0;line<N;line++)
	{for (column=0;column<=line;column++) 
		if (column<line) printf("%lld ",combinatorial(column,line));
		else printf("%lld",combinatorial(column,line));
	printf("\n");}}
