#include<stdio.h>
typedef struct Node {
	int a,b;
	struct Node *next;
}node;
int main() {
	node* abc;
	node qqq;
	abc=&qqq;
	qqq.a=666;
	printf("%d",abc->a);
}
