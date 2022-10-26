#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define swap(a,b) {double t;t=b;b=a;a=t;}
//�Զ��б任�ĺ��� 
void Line_minimalist_matrix(double *a,int n,int m,int th,int th2) {
	int i=0,j=0,l,c;
	double save;
	if(*(a+(th-1)+(th2-1)*m)==0) {
		printf("��%d�е�%d�е�Ԫ��Ϊ0���޷��Ը��л���",th,th2);
		return;
	}
	if(th>m||th2>n){
		printf("�������/��\n");
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
	puts("ʹ��˵���������С�������������������У��е�ֵ��\n�������������000�����¸����������");
	puts("֧�����ֲ��������ӣ�\n\t��r4 r2\n\t(���������� �ڶ��У��м�ո�ֿ�)");
	puts("\t��r3*(��/)k\n\t�������г�(�����)k��k���������ʵ����");
	puts("\t��r1+(-)r2(*/)k\n\t����һ�м��ϵڶ��г˻���Է���ʵ��k��");
	puts("\t��2\n\t�����⣨�ڶ��������б仯������������Σ�");
	puts("\t��2 3\n\t��ʹ��3�е�2�б�Ϊ1����������Ԫ�ػ�Ϊ0������������Σ�");
	puts("�������еĲ����벻Ҫ����κζ���Ŀո񣡣�����");
	puts("\n");
	puts("�б任����������r2 r3 \tr1*4 \t r2/2 \t r2+r1*4 \t r3-r1/2 \n");
	int i,line,column,precise;
	puts("�������1λ��2λ��3λ����4λС����");
	scanf("%d",&precise);
	while(1) {
		char s1[4]= {0},s2[8]= {0};
		puts("�м��У��м��У����ո�ֿ���");
		scanf("%d%d",&line,&column);
		if(line>9||column>12) {
			printf("������/��̫����\n");
			continue;
		}
		double a[line][column],*p,multiplier,divisor;
		p=(double*)a;
		puts("\n��������������Ԫ�ص�ֵ");
		for(i=0; i<line*column; i++) scanf("%lf",p+i);
		getchar();
		puts("\n��ֵ����ɣ�\n������Ҫ�����б任");
		while(1) {
			memset(s1,0,4);
			memset(s2,0,4);
			multiplier=1;
			divisor=1;
			fgets(s1,4,stdin);
			if(s1[0]=='0') break;///�����¾��� 
			//���￪ʼ�Զ��б任���� 
			if(s1[0]>'0'&&s1[0]<='9') {
				if(atoi(s1)>column) {
					puts("���������");
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
			//��������Զ��б任���� 
			puts("");
			//���￪ʼ�ֶ��б任���� 
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
			//��������ֶ��б任���� 
			for(i=0; i<line*column; i++)//ȥ��-0 
				if(fabs(*(p+i))<0.000001) *(p+i)=0;
			//��������ͬ��С��λ����� 
			for(i=0; i<line*column; i++) {
				if(precise==4) {
					printf("%10.4lf",*(p+i));
					if((i+1)%column==0) puts("\n\n");
					continue;
				}
				if(precise>2) printf("%8.3lf",*(p+i));
				else if(precise>1) printf("%7.2lf",*(p+i));
				else printf("%6.1lf",*(p+i));
				if((i+1)%column==0) puts("\n");//���� 
			}
		}
	}
}
