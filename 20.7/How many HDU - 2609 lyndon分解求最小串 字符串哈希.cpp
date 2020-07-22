#include"s.h"
#include<bits/stdc++.h>
char s[209],res[109];
unsigned hash,len,place=0,i,j,k,n;
unsigned lyndon(){
	scanf("%s",s);
	len=strlen(s);
	memcpy(s+len,s,len);
	for(i=0;i<len;){
		j=i,k=j+1;
		place=i;
		while(k<2*len&&s[k]>=s[j]){
			if(s[k]==s[j]) j++;
			else j=i;
			k++;
		}
		while(i<=j) i+=k-j;
	}
	memcpy(res,s+place,len);
	hash=0;
	for(i=0;i<len;i++) hash=hash*10007+res[i];
	return hash;
}
int main(){
	for(;~scanf("%d",&n);){
		std::set<int> res;
		for(;n--;) res.insert(lyndon());
		printf("%d\n",res.size());
	}
}