#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))
typedef long long ll;
const ll mod=100000000;
int main(){
	char save[9909],shit[200];
	ll nt=0,n,decimals=0,ans[1000],k,len,j,i;
	while(~scanf("%s %lld",shit,&n)){
		memset(ans,0,1000*8);
		memset(save,0,9909);
		k=strlen(shit);
		if(strchr(shit,'.')) 
			for(i=k-1;shit[i]=='0';i--) {
			shit[i]=0;
			k--;
		}	
		for(i=0;i<k;i++) {
			if(shit[i]!='.') nt=nt*10+shit[i]-'0';
			else decimals=k-i-1;
		}
		//--------------------------------
		ans[0]=nt;
		len=1;
		for(i=0;i<n-1;i++){
			for(j=len;j>=0;j--){
				ans[j]*=nt;
				ans[j+1]+=ans[j]/mod;
				ans[j]%=mod;
			}
			if(ans[len]) len++;
		}
		decimals*=n;
		k=0;
		for(i=0;i<400;i++) {
			if(!ans[i]) continue;
			for(int j=0;j<8;j++) {
				save[k++]=ans[i]%10+'0';
				ans[i]/=10;
			}
		}
		for(i=max(strlen(save)-1,decimals);i>decimals;i--) 
			if(save[i]!='0') break;
		for(;i>decimals;i--) 
			putchar(save[i]?save[i]:'0');
		if(save[i]!=0) {
			putchar(save[i]);
		}
		i--;
		if(i>=0) putchar('.');
		for(;i>=0;i--) putchar(save[i]?save[i]:'0');
		puts("");
		nt=decimals=0;
		memset(shit,0,20);
	}
} 
