#include<stdio.h>
#include<string.h>
int main(){
	char string[120],i1,i2,i3;
	int i,j;
	scanf("%s",string); //�����ַ��� 
	for (i=0;i<119;i++) if (string[i]==0) break;//��Ч�ַ����ĳ��� 
	i1=string[0];i2=string[1];i3=string[2];//����ǰ���� 
	strcpy(string,string+3);//�ַ���ǰ�� 
	string[i-1]=i3;string[i-2]=i2;string[i-3]=i1;//ǰ�������ں��� 
	printf("%s\n",string);//��� 
	return 0;}
