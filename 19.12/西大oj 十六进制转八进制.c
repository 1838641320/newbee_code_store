#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int atox(char a){
	if(!a) return 0;
	return (a>='0'&&a<='9')?a-'0':a-'A'+10;
}
int main(){
	int i,n,len,j,printed,result[200008],k;
	char tran[4]={0},string[100008];
	scanf("%d",&n);
	getchar();
	while(n--){
		memset(string,0,100008);
		memset(result,0,4*200008);
		string[0]=string[1]=string[2]='0';
		gets(string+3);
		len=strlen(string+3);
		printed=k=0;
		j=len;
		while(j>=0){
			memcpy(tran,string+j,3);
			if(strlen(tran)==3) i=atox(tran[0])*256+atox(tran[1])*16+atox(tran[2]);
			else if(strlen(tran)==2) i=atox(tran[0])*16+atox(tran[1]);
			else i=atox(tran[0]);
			j-=3;
			result[k++]=i;
		}
		while(k--){
			if(printed==0&&result[k]==0) continue; 
			if(printed==0) printf("%o",result[k]);
			else printf("%04o",result[k]);
			printed++;
		}
		if(printed) puts("");
		else puts("0");
	}
}
