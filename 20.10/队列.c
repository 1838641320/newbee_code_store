#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef int ty;
#define maxsize 5
struct Node{
	ty data[maxsize];
	int size,rear;
};
typedef struct Node node;
node *CreatQueue(){
	node *ret=(node*)malloc(sizeof(node));
	memset(ret->data,0,sizeof ret->data);
	ret->size=ret->rear=0;
	return ret;
}
int IsFull(node *l){return l->size>=maxsize;}
int IsEmpty(node *l){return l->size==0;}
void AddQ(node *l,ty x){
	if(IsFull(l)) return;
	int p=(l->rear+l->size++)%maxsize;
	l->data[p]=x;
}
ty Delete(node *l){
	if(IsEmpty(l)) return -1;
	l->size--;
	ty ret=l->data[l->rear];
	l->rear=(l->rear+1)%maxsize;
	return ret;
}
int main(){
	int n,op,x;
	scanf("%d",&n);
	node *l=CreatQueue();
	while(n--){
		scanf("%d",&op);
		if(op==1) scanf("%d",&x),AddQ(l,x);
		else printf("%d ",Delete(l));
	}
	puts("");
	printf("%d\n",l->size);
	while(!IsEmpty(l)) printf("%d ",Delete(l));
}