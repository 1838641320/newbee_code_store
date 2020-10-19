#define __max(a,b) (((a) > (b)) ? (a) : (b))
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
typedef int ty;
struct Node{
	ty data;
	struct Node *next;
};
typedef struct Node node;
//creat a list using an array of length n
node *creat(ty a[],size_t n){
	node *L=(node*)malloc(sizeof(node)),*p=L;
	for(int i=0;i<n;i++){
		p->next=(node*)malloc(sizeof(node));
		p->next->data=a[i];
		p=p->next;
	}
	p->next=0;
	return L;
}
//delete the node after node *p
//the return value is the deleted node's value
ty deletnex(node *l){
	node *t=l->next;
	ty a=t->data;
	l->next=t->next;
	free(t);
	return a;
}
//insert a node of value x after node *p
void insert(node *p,ty x){
	node *t=p->next;
	p->next=(node*)malloc(sizeof(node));
	p->next->data=x;
	p->next->next=t;
}
//print the list
void print(node *l){
	for(node *p=l->next;p!=NULL;p=p->next)
		printf("%d ",p->data);
	puts("");
}
ty solve1(node *l,ty x){
	if(l->next==NULL) 
		return insert(l,x),x;
	ty a=l->next->data;
	for(node *p=l->next ; p!=NULL ; p=p->next)
		a=__max(a,p->data);
	for(node *p=l ; p->next!=NULL ; p=p->next)
		if(p->next->data==a) {
			insert(p,x);
			break;
		}
	return __max(a,x);
}
void DeleteFirstX(node *l,ty x){
	for(node *p=l ; p->next!=NULL ; p=p->next)
		if(p->next->data==x){
			deletnex(p);
			return;
		}
}
int main(){
	ty a[9999]={};
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++) 
		scanf("%d",a+i);
	node *l=creat(a,n);
	scanf("%d",&x);
	print(l);
	ty maxe=solve1(l,x);
	print(l);
	DeleteFirstX(l,maxe);
	print(l);
}