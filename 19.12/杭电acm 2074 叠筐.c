#include<stdio.h>
int n,k,f=0,i,j;
char a,b,s[88][88],t;
int main() {
	while(~scanf("%d %c %c",&n,&a,&b)) {
		if(f++) puts("");
		k=0;
		for(i=n/2; i>=0; i--) {
			t=k%2?b:a;
			k++;
			for(j=i; j<n-i; j++) {
				s[i][j]=t;
				s[n-i-1][j]=t;
				s[j][i]=t;
				s[j][n-i-1]=t;
			}
		}
		s[0][0]=s[0][n-1]=s[n-1][0]=s[n-1][n-1]=' ';
		if(n==1) printf("%c\n",a);
		else {
			for(i=0; i<n; i++) {
				for(j=0; j<n; j++)
					putchar(s[i][j]);
				puts("");
			}
		}
	}
}
