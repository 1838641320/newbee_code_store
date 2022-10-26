#include<stdio.h>
#include<string.h>
int main(){
	char string[120],i1,i2,i3;
	int i,j;
	scanf("%s",string); //输入字符串 
	for (i=0;i<119;i++) if (string[i]==0) break;//有效字符串的长度 
	i1=string[0];i2=string[1];i3=string[2];//保存前三个 
	strcpy(string,string+3);//字符串前移 
	string[i-1]=i3;string[i-2]=i2;string[i-3]=i1;//前三个放于后面 
	printf("%s\n",string);//输出 
	return 0;}
