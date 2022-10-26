#include<stdio.h>
void A(int n,int i){
	printf("sin(%d",i);
	if(i<n){
		putchar((i%2)?'-':'+');
		A(n,i+1);	
	} 
	putchar(')');
}
void S(int n,int i){
	if(n>1){
		putchar('(');
		S(n-1,i+1);
		putchar(')');
	}
	A(n,1);
	printf("+%d",i);
}
int main(n){
	scanf("%d",&n);
	S(n,1);
}
