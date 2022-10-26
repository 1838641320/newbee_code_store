#include<stdio.h>
typedef struct{
	double imagine,real;
} C;
void calculate(C* x,C* y,C* z){
	z->real=x->real*y->real-x->imagine*y->imagine;
	z->imagine=x->real*y->imagine+x->imagine*y->real;
}
int main(){
	C x,y,z;
	while(~scanf("%lf%lf%lf%lf",&x.real,&x.imagine,&y.real,&y.imagine)){
	calculate(&x,&y,&z);
	printf("%lf%+lfi\n",z.real,z.imagine);
}}
