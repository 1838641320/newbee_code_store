#include"stdafx.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void cal(ll last,ll sum,ll num,ll op,bool ad) {
	if (last==9) {
		if (ad&&sum+num!=100||!ad&&sum-num!=100) return;
		stack<int> ops;
		while (op) ops.push(op%10ll),op /= 10ll;
		putchar('1');
		ops.pop();
		for (int i = 2;i<=9;i++) {
			int o = ops.top();ops.pop();
			o==0&&putchar('+');
			o==1&&putchar('-');
			printf("%d",i);
		}
		puts("=100");
		return;
	}
	if (ad) cal(last+1,sum+num,last+1,op*10,1);
	else    cal(last+1,sum-num,last+1,op*10,1);
	if (ad) cal(last+1,sum+num,last+1,op*10+1,0);
	else    cal(last+1,sum-num,last+1,op*10+1,0);
	     cal(last+1,sum,num*10+last+1,op*10+2,ad);
}
int main() {
	cal(1,0,1,1,1);
}
/*#include"stdafx.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void cal(ll sum,ll num,int op,int ad) {
	if (num%10==9) {
		if (ad&&sum+num!=100||!ad&&sum-num!=100) return;
		int ops[20] = {},top=-1;
		while (op) ops[++top]=op%3,op /= 3;
		top--;
		putchar('1');
		for (int i = 2;i<=9;i++) {
			int o = ops[top--];
			o==0&&putchar('+');
			o==1&&putchar('-');
			printf("%d",i);
		}
		puts("=100");
		return;
	}
	cal(sum+num*ad,num%10+1,op*3,1);
	cal(sum+num*ad,num%10+1,op*3+1,-1);
	cal(sum,num*10+num%10+1,op*3+2,ad);
}
int main() {
	cal(0,1,1,1);
}*/