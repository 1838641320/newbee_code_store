#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
	// ����n����prime��������1~n������ 
	int n;
	scanf("%d",&n);
	int *original=malloc(4*n),*prime=malloc(4*n),p=0;
	memset(original,0,4*n);
	memset(prime,0,4*n);
	original[0]=original[1]=1;//�����������Ϊһ���������Ϊһ 
	for(int i=2; i<n; ++i) {
		if(!original[i])//���Ǻ��������� 
			prime[p++]=i;//�������������� 
		for(int i1=0;i1<p;i1++) {
			if(i*prime[i1]>=n) break;//������Χ�� 
			original[i*prime[i1]]=1;//�����ı������Ǻ��� 
			if(!i%prime[i1]) break;//i��ĳ�����ı���������
		}
	}
	//��prime��������1~n������
	puts("�����������1��ͳ�Ƹ�����2");
	int choice;
	scanf("%d",&choice);
	switch(choice) {
	case 1 :
		for(int i1=0; i1<p; i1++)
			printf("%d ",prime[i1]);
		break;
	case 2:
		printf("%d\n",p);
	}
}
