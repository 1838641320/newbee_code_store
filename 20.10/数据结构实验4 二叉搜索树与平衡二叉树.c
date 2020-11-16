#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
#define max(a,b) (((a) > (b)) ? (a) : (b))
typedef int ty;
int cmp(ty a,ty b){return a-b;}
struct node {
	ty data;
	struct node *ch[2];
	int high;
};
typedef struct node node;
#define new(x) (x*)malloc(sizeof(x))
node *tr1=0,*tr2=0,*end;
void init(node **end){
	(*end)=new(node);
	(*end)->high=(*end)->data=0;
	(*end)->ch[0]=(*end)->ch[1]=0;
}
node *creatnode(ty x){
	node *ret=new(node);
	ret->data=x;
	ret->ch[0]=ret->ch[1]=end;
	ret->high=1;
	return ret;
}
node* insert1(node* r,ty x){
	if(r==end) return creatnode(x);
	if(cmp(r->data,x)>0) r->ch[0]=insert1(r->ch[0],x);
	if(cmp(r->data,x)<0) r->ch[1]=insert1(r->ch[1],x);
	return r;
}
void update(node *r){
	r->high=max(r->ch[0]->high,r->ch[1]->high)+1;
}
int unbalance(node *r){
	return abs(r->ch[0]->high-r->ch[1]->high)>=2;
}
node *rotate(node *r,int d){
	node *b=r->ch[d];
	r->ch[d]=b->ch[1^d];
	b->ch[1^d]=r;
	update(r),update(b);
	return b;
}
node* insert2(node* r,ty x){
	if(r==end) return creatnode(x);
	int t=cmp(r->data,x)<0;
	r->ch[t]=insert2(r->ch[t],x);
	if(unbalance(r)){
		if((cmp(r->ch[t]->data,x)<0)!=t)
			r->ch[t]=rotate(r->ch[t],1^t);
		r=rotate(r,t);
	}
	update(r);
	return r;
}
int find(node *r,ty x){
	if(r==end) return 0;
	int ret=0,t;
	while(ret++,t=cmp(r->data,x)){
		r=r->ch[t<0];
		if(r==end) break;
	}
	return ret;
}
int main(){
	init(&end);
	tr1=end,tr2=end;
	int n;
	scanf("%d",&n);
	int a[n];
	rep(i,0,n){
		scanf("%d",&a[i]);
		tr1=insert1(tr1,a[i]);
		tr2=insert2(tr2,a[i]);
	}
	int ans=0;
	rep(i,0,n) ans+=find(tr1,a[i]);
	printf("%d\n",ans);
	ans=0;
	rep(i,0,n) ans+=find(tr2,a[i]);
	printf("%d\n",ans);
}