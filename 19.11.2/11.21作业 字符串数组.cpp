#include<stdio.h>
#include<string.h>
int main(){
	char line[200]= {0},cap[200]= {0};
	int i=0,length,yes=0,exist[30]= {0};
	gets(line);
	length=strlen(line);
	for(i=0; i<length; i++)
		if(line[i]>='A'&&line[i]<='Z'&&exist[line[i]-'A']==0) {
			cap[yes++]=line[i];
			exist[line[i]-'A']=1;
		}
	if(yes) printf("%s",cap);
	else printf("Not Found");
}
