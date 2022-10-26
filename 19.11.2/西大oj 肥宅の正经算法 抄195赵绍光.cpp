#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main() {
	int n, i, j, x=0, y=0, t, cnt=0;
	scanf("%d",&n);
	int *a;
	a = (int *)malloc( 1000000* sizeof(int));
	memset(a,0,1000000);
	for( i=0; i<n; i++ ) {
		scanf("%d%d",&x,&y);
		if( a[x]!=0 && y>a[x])
			continue;
		a[x] = y;
	}//输入，地址位置保存起点，地址内容保存终点，留下终点最小值 
	for(t=0,i=0; i<1000000; i++ ) {
		if( a[i] == 0 ) continue;
		if( i >= t ) {//走过了上一个终点，可以开始算了 
			t = a[i];
			cnt++;
		}
		if( a[i] < t) t = a[i];//如果有终点更近，更新终点 
	}
	printf("%d\n",cnt);
}
