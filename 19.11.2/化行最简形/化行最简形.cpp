#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define swap(a,b) {double t;t=b;b=a;a=t;}
//自动行变换的函数 
void Line_minimalist_matrix(double *a,int n,int m,int th,int th2) {
	int i=0,j=0,l,c;
	double save;
	if(*(a+(th-1)+(th2-1)*m)==0) {
		printf("第%d列第%d行的元素为0，无法对该列化简",th,th2);
		return;
	}
	if(th>m||th2>n){
		printf("错误的行/列\n");
		return;
	}
	save=*(a+(th-1)+(th2-1)*m);
	for(i=0; i<m; i++)
		*(a+i+(th2-1)*m)/=save;
	for(l=0; l<n; l++) {
		save=*(a+l*m+th-1);
		if(th2-l-1&&save) {
			for(c=0; c<m; c++)
				*(a+l*m+c)-=save*(*(a+(th2-1)*m+c));
		}
	}
}
int main() {
	system("mode con cols=150 lines=900");
	puts("使用说明：输入行、列数，依次输入矩阵行，列的值。\n运算结束后输入000进行下个矩阵的运算");
	puts("支持五种操作，例子：\n\t①r4 r2\n\t(交换第四行 第二行，中间空格分开)");
	puts("\t②r3*(或/)k\n\t（第三行乘(或除以)k，k是任意非零实数）");
	puts("\t③r1+(-)r2(*/)k\n\t（第一行加上第二行乘或除以非零实数k）");
	puts("\t④2\n\t（对这（第二）列做行变化，趋向行最简形）");
	puts("\t⑤2 3\n\t（使第3行第2列变为1，该列其余元素化为0，趋向行最简形）");
	puts("以上所有的操作请不要添加任何额外的空格！！！！");
	puts("\n");
	puts("行变换操作样例：r2 r3 \tr1*4 \t r2/2 \t r2+r1*4 \t r3-r1/2 \n");
	int i,line,column,precise;
	puts("输出保留1位，2位，3位还是4位小数？");
	scanf("%d",&precise);
	while(1) {
		char s1[4]= {0},s2[8]= {0};
		puts("有几行？有几列？（空格分开）");
		scanf("%d%d",&line,&column);
		if(line>9||column>12) {
			printf("矩阵行/列太大了\n");
			continue;
		}
		double a[line][column],*p,multiplier,divisor;
		p=(double*)a;
		puts("\n依次输入矩阵各个元素的值");
		for(i=0; i<line*column; i++) scanf("%lf",p+i);
		getchar();
		puts("\n赋值已完成！\n请输入要做的行变换");
		while(1) {
			memset(s1,0,4);
			memset(s2,0,4);
			multiplier=1;
			divisor=1;
			fgets(s1,4,stdin);
			if(s1[0]=='0') break;///运算新矩阵 
			//这里开始自动行变换部分 
			if(s1[0]>'0'&&s1[0]<='9') {
				if(atoi(s1)>column) {
					puts("输入错误列");
					continue;
				}
				if(s1[2]) {
					char bit;
					if (s1[2]==' ') {
						bit=getchar();
						getchar();
						Line_minimalist_matrix((double*)a,line,column,atoi(s1),bit-'0');
					} else {
						getchar();
						Line_minimalist_matrix((double*)a,line,column,atoi(s1),atoi(s1+2));
					}
				} else Line_minimalist_matrix((double*)a,line,column,atoi(s1),atoi(s1));

			}
			//这里结束自动行变换部分 
			puts("");
			//这里开始手动行变换部分 
			if(s1[2]==' '&&s1[0]=='r') {
				fgets(s2,4,stdin);
				for(i=0; i<column; i++) swap(a[s1[1]-'1'][i],a[s2[1]-'1'][i]);
			} else if(s1[2]=='*'||s1[2]=='/') {
				if(s1[2]=='*') scanf("%lf",&multiplier);
				else scanf("%lf",&divisor);
				getchar();
				for(i=0; i<column; i++) a[s1[1]-'1'][i]*=multiplier/divisor;
			} else if(s1[2]=='+'||s1[2]=='-') {
				fgets(s2,4,stdin);
				if (s2[2]!='\n') {
					if(s2[2]=='*') scanf("%lf",&multiplier);
					else scanf("%lf",&divisor);
					getchar();
				}
				if (s1[2]=='+') for(i=0; i<column; i++) a[s1[1]-'1'][i]+=a[s2[1]-'1'][i]*(multiplier/divisor);
				if (s1[2]=='-') for(i=0; i<column; i++) a[s1[1]-'1'][i]-=a[s2[1]-'1'][i]*(multiplier/divisor);
			}
			//这里结束手动行变换部分 
			for(i=0; i<line*column; i++)//去除-0 
				if(fabs(*(p+i))<0.000001) *(p+i)=0;
			//按保留不同的小数位数输出 
			for(i=0; i<line*column; i++) {
				if(precise==4) {
					printf("%10.4lf",*(p+i));
					if((i+1)%column==0) puts("\n\n");
					continue;
				}
				if(precise>2) printf("%8.3lf",*(p+i));
				else if(precise>1) printf("%7.2lf",*(p+i));
				else printf("%6.1lf",*(p+i));
				if((i+1)%column==0) puts("\n");//换行 
			}
		}
	}
}
