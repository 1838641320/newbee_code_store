#include<stdio.h>
void s(int n){
	if(n>1) s(n-1);
	putchar('A'+n-1);
	if(n>1) s(n-1);
}
int main(int N){
	scanf("%d",&N);
	s(N);
}
