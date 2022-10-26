#include<stdio.h>
int main(){int a,b,c;printf("Enter 3 integers\n");scanf("%d%d%d",&a,&b,&c);if (a<=b) if (a<=c) if (b<=c);else c^=b^=c^=b;else {c^=b^=c^=b;a^=b^=a^=b;}else if (b<=c) if (a<=c) a^=b^=a^=b;else {a^=b^=a^=b;c^=b^=c^=b;}else a^=c^=a^=c;printf("\n%d %d %d\n",a,b,c);return 0;}
