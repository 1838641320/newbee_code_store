#include<stdio.h>
#include<string.h>
int main() {
    int array[100008],sort[500]={0},a,b,c;
    long long n,i,result=0,j=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%d%d%d",&a,&b,&c);
        sort[200+a-b+c]++;
        result+=a+b*n+2*c;
    }
    for(i=499;i>=0;i--) while(sort[i]--) array[j++]=i-200;
    for(i=0;i<n;i++)
        result+=(i+1)*array[i];
    printf("%lld",result);
    return 0;
}
