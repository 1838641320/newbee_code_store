#include<stdio.h>
#include<string.h>
int main() {
	char article[500][80]={0},in[40000]={0},word[80]={0},*p;
	int count,i,j,exist;
	while(1){
		gets(in);
		if(in[0]=='#') return 0;
		count=i=0;
		while(~sscanf(in+i,"%s",word)){
			p=in+i;
			while(*p==' ') p++;
			i=p-in;
			i+=strlen(word)+1;
			exist=0;
			for(j=0;j<count;j++) 
				if(!strcmp(article[j],word)) {
					exist=1;
					break;
				}
			if(!exist) strcpy(article[count++],word);
		}
		printf("%d\n",count);
		memset(article,0,40000);
		memset(in,0,40000);
		memset(word,0,80);
	}
}
