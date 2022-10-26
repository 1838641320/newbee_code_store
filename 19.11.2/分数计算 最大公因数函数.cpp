#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	int num;//·Ö×Ó 
	int den;//·ÖÄ¸ 
} fra;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void simplifiy(fra* f) {
	int t=gcd(f->num,f->den);
	f->num/=t;
	f->den/=t;
	if(f->den<0); {f->den*=-1;f->num*=-1;}
	if(f->den<0&&f->num<0) {f->den*=-1;f->num*=-1;}
}
void fraction_computation(fra* f,fra* in,char op) {
	if(op=='+'){
		f->num=(f->num)*(in->den)+(f->den)*(in->num);
		f->den*=(in->den);
	}
	if(op=='-'){
		f->num=(f->num)*(in->den)-(f->den)*(in->num);
		f->den*=(in->den);
	}
	if(op=='*'){
		f->num*=(in->num);
		f->den*=(in->den);
	}
	if(op=='/'){
		f->num*=(in->den);
		f->den*=(in->num);
	}
}
int main() {
	char c[80],op,op1;
	int a,b,i=0,length;
	fra f,in;
	f.den=in.num=1;
	f.num=in.num=0;
	while(1) {
		op1=getchar();
		scanf("%d",&in.num);
		op=getchar();
		if(op=='/') {
			scanf("%d",&in.den);
			getchar();
		}
		else in.den=1;
		simplifiy(&in);
		fraction_computation(&f,&in,op1);
		simplifiy(&f);
		if (f.den==1) printf("%d\n\n",f.num);
		else printf("%d/%d\n\n",f.num,f.den);
	}
}
