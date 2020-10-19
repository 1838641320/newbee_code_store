#include<cstring>
#include<algorithm>
#include<iostream>
#include<ctime>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
ll gcd(ll x,ll y){while(y^=x^=y^=x%=y);return x;}
using namespace std;
//-----------------
template<class ty>struct stack{
	struct node{
		ty data;
		node *nex;
	};
	int size;
	node *head;
	stack(){
		head=new node;
		*head={0,0};
	}
	void push(ty x){
		node *t=new node;
		t->data=x;
		t->nex=head->nex;
		head->nex=t;
		size++;
	}
	ty pop(){
		if(!size) return 0;
		node *t=head->nex;
		ty ret=t->data;
		head->nex=t->nex;
		delete t;
		size--;
		return ret;
	}
	ty peek(){
		if(!size) return 0;
		return head->nex->data;
	}
};
int main(){
	stack<int> st;
	srand(time(0));
	int n=rand()%100;
	printf("%d\n",n);
	rep(i,0,n){
		int x=rand();
		st.push(x);
		printf("%d%c",x,i%10==0?'\n':' ');
	}
	puts("");
	while(st.size){
		printf("%d ",st.pop());
	}
}