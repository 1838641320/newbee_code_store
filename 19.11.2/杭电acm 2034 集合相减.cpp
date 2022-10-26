#include<stdio.h>
#define sort998(a,n) for (int i=0;i<n-1;i++) for(int j=i+1;j<n;j++) if(a[i]>a[j]) a[i]^=a[j]^=a[i]^=a[j];
#define non 999999999999
int main() {
    long long m,n;
    while(~scanf("%lld%lld",&n,&m)) {
        if (n==0&&m==0) return 0;
        long long a[106]= {0},b,i;
        int exist=0;
        for(i=0; i<n; i++) scanf("%lld",&a[i]);
        for(i=0; i<m; i++) {
            scanf("%lld",&b);
            for(int j=0; j<n; j++) if(a[j]==b) a[j]=non;
        }
        sort998(a,n);
        for(int j=0; j<n; j++) {
            if(a[j]!=non) {
                printf("%lld ",a[j]);
                exist=1;
            }
        }
        if(exist==0) puts("NULL");
        else puts("");
    }
}
