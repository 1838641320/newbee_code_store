#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
typedef int ty;
struct Node{
	ty data;
	struct Node *nex;
};
typedef struct Node node;
#define new(x) (x*)malloc(sizeof(x))
node* CreatStack(){
	node *ret=new(node);
	ret->data=0;
	ret->nex=NULL;
	return ret;
}
int IsEmpty(node *l){
	return l->nex==NULL;
}
void push(node*l,ty x){
	node *t=new(node);
	t->data=x;
	t->nex=l->nex;
	l->nex=t;
	l->data++;
}
ty pop(node *l){
	if(IsEmpty(l)) return -1;
	node *t=l->nex;
	ty ret=t->data;
	l->nex=t->nex;
	free(t);
	l->data--;
	return ret;
}
int main(){
	int n,op,x;
	scanf("%d",&n);
	node *l=CreatStack();
	while(n--){
		scanf("%d",&op);
		if(op==1) scanf("%d",&x),push(l,x);
		else printf("%d ",pop(l));
	}
	puts("");
	printf("%d\n",l->data);
	while(!IsEmpty(l)) printf("%d ",pop(l));
}