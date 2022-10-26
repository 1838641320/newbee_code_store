#include<stdio.h>
#include<string.h>
#define maxline 6666 
int main() {
	int al,bl,bit,carry;
	char a[maxline]= {0},b[maxline]= {0},c[maxline]= {0};
	while(~scanf("%s %s",a+1,b+1)) {
		al=strlen(a+1);
		bl=strlen(b+1);
		carry=0;bit=0;a[0]='0';b[0]='0';
		while(al>0||bl>0) {
			c[bit]=(a[al]-'0')+(b[bl]-'0')+carry;
			carry=c[bit]/10;
			c[bit]%=10;
			if(al>0) al--;
			if(bl>0) bl--;
			bit++;
		}
		if(carry-1) bit--;
		else c[bit]++;
		for (int i=bit; i>=0; i--) printf("%hd",c[i]);
		printf("\n");
		memset(a,0,maxline);memset(b,0,maxline);memset(c,0,maxline);
	}
}
