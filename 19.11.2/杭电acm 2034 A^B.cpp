#include<stdio.h>
int main() {
    int A,B;
    while(1) {
        scanf("%d%d",&A,&B);
        if (A==0&&B==0) return 0;
        for (int i=A; B>1; B--) {
            A*=i;
            A%=1000;
        }
        printf("%d\n",A);
    }
}
