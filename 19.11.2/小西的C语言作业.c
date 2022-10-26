#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int a,b,o;
	char c[60],*p;
	while(~scanf("%s",c)){
		if(c[0]=='~'){
			printf("%d\n",~atoi(c+1));
			continue;
		}
		a=atoi(c);
		if(p=strchr(c,'^')) printf("%d\n",a^(atoi(p+1)));
		if(p=strchr(c,'|')) printf("%d\n",a|(atoi(p+1)));
		if(p=strchr(c,'&')) printf("%d\n",a&(atoi(p+1)));
	}
}

