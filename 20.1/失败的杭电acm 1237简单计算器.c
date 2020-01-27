#include<stdio.h>
double cal(double a,double b,char op){
	switch(op){
		case '+':return a+b;
		case '-':return a-b;
		case '*':return a*b;
		case '/':return a/b;
	}
}
int main(){
	double a=0,b=0,c;
	char op1='+',op2=0,op3,l,caled=0;
	while(scanf("%lf%c",&c,&l)){
		if(caled==0&&l=='\n') return 0;
		if(l=='\n'){
			if(b==0) a=cal(a,c,op1);
			else a=cal(a,cal(b,c,op2),op1);
			printf("%.2lf\n",a);
			b=a=op2=caled=0;
			op1='+';
		}
		else {
			caled++;
			op3=getchar();
			if(op3=='+'||op3=='-') {
				if(b==0) a=cal(a,c,op1);
				else a=cal(a,cal(b,c,op2),op1);
				op1=op3;
				b=0;
			}
			else if(op3=='*'||op3=='/'){
				if(b==0) b=c;
				else b=cal(b,c,op2);
				op2=op3;
			}
		}
	}
}

