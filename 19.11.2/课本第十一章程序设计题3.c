#include<stdio.h>
#include<string.h>
int max_len(char *s[],int n){
	int max=0;
	for(int i=0;i<n;i++){
		if(max<strlen(s[i])) max=strlen(s[i]);
	}
	return max;
}
int main() {
	char *string[8]={"one","two","three","four","five","six","seven","eight666"};
	printf("%d\n",max_len(string,8));
}
