#include<cstdio>
#include<cstdlib>
#include<ctime>
#define rep(i,a,b) for(int i=a,bb=b;i<bb;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
template<class ty> void swap(ty&a,ty&b){ty t=b;b=a,a=t;};
template<class ty=int> class list{
public:
	struct Node{
		ty data;
		Node *next;
	};
	Node* head;
	list(){
		head=new Node;
		head->data=0;
		head->next=NULL;
	}
	~list(){
		delete head;
	}
	list(ty *a,size_t n){
		Node *p=new Node;
		p->next=NULL;
		for(int i=0;i<n;i++){
			Node *h=new Node;
			h->next=p;
			p->data=a[i];
			p=h;
		}
		p->data=0;
		head=p;
	}
	void print(){
		Node *p=head;
		for(p=p->next;p;p=p->next) printf("%d ",p->data);
		puts("");
	}
	void deleteNext(Node* p){
		Node* t=p->next;
		p->next=t->next;
		delete t;
	}
	Node* insert(Node *p,ty x){
		Node *t=new Node;
		t->data=x;
		t->next=p->next;
		p->next=t;
		return t;
	}
	void reverse(Node*start,Node*end){
		Node *t=end,*t1;
		while(start!=t){
			t1=start->next;
			start->next=end;
			end=start;
			start=t1;
		}
	}
	void deletemax(){
		Node *h=head;
		if(h->next==NULL) return;
		ty maxv=h->data;
		Node* s=h->next,*p=h->next;
		for(;s;s=s->next) 
			if(maxv < s->data) maxv=s->data;
		for(s=h;s;){
			if(s->next&&s->next->data==maxv) deleteNext(s);
			else s=s->next;
		}
	}
};
int main(){
	srand(time(0));
	int n=20;
	int a[n]={};
	for(int i=0;i<n;i++) a[i]=rand()%60,printf("%d ",a[i]);
	puts("");
	list<int> mylist;
	list<int>::Node* p=mylist.head;
	for(int i=0;i<n;i++) {
		p=mylist.insert(p,a[i]);
	}
	mylist.print();
	mylist.deletemax();mylist.deletemax();
	mylist.print();
	mylist.deletemax();mylist.deletemax();
	mylist.print();
	p=mylist.head->next;
	while(p->next&&p->data>10) p=p->next;
	mylist.reverse(mylist.head->next,p->next);
	mylist.head->next=p;
	mylist.print();
}