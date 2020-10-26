#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
typedef int ty;
struct Node{
	ty data[99999];
	int last;
};
typedef struct Node node;
//creat a list using an array of length n
node *creat(ty a[],int n){
	node *l=(node*)malloc(sizeof(node));
	rep(i,0,n) l->data[i]=a[i];
	l->last=n-1;
	return l;
}
//delete element at position index
//the return value is the deleted node's value
ty deleten(node *l,int index){
	ty ret=l->data[index];
	for(int i=l->last;i>index;i--)
		l->data[i-1]=l->data[i];
	l->last--;
	return ret;
}
//insert a element of value x at index
void insert(node *l,int index,ty x){
	for(int i=l->last;i>=index;i--)
		l->data[i+1]=l->data[i];
	l->data[index]=x;
	l->last++;
}
//print the list
void print(node *l){
	for(int i=0;i<=l->last;i++)
		printf("%d ",l->data[i]);
	puts("");
}
void solve1(node *l,int x){
	int max=0;
	for(int i=0;i<=l->last;i++)
		if(l->data[i]>l->data[max])
			max=i;
	insert(l,max,x);
}
int main(){
	int n,x,a[99999]={};
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i);
	scanf("%d",&x);
	node *l=creat(a,n);
	solve1(l,x);
	print(l);
}