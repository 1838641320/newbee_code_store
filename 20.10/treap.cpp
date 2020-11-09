#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,a,b) for(int i=a,bb=b;i<bb;i++)
#define mem(a,b) memset(a,b,sizeof a)
namespace lmdd{
	using ll=long long;
	template<class ty>ty gcd(ty x,ty y){while(x^=y^=x^=y%=x);return y;}
	template<class ty>void read(ty&a){
		a=0;int f=0,c=getchar();
		for(;!isdigit(c)&&~c;c=getchar()) f|=c=='-';
		for(;isdigit(c);c=getchar()) a=a*10+(c^48);
		if(f) a=-a;
	}
	template<class a,class ...b>void read(a&A,b&...B){read(A);read(B...);}
}
//-----------------------
#include<ctime>
template<class ty>class treap{
	struct node{
		ty val;
		int pri;
		size_t sz;
		node *l,*r;
		node(ty x,node *p,int (*rd)()=rand){
			val=x,pri=rd();
			l=r=p;sz=1;
		}
	};
	node *root,*end,*L,*M,*R;
	void update(node *ro){
		ro->sz=ro->l->sz+ro->r->sz+1;
	}
	node* merge(node* lr,node* rr){
		if(lr==end) return rr;
		if(rr==end) return lr;
		if(lr->pri>rr->pri)
			{lr->r=merge(lr->r,rr);update(lr);return lr;}
		else 
			{rr->l=merge(lr,rr->l);update(rr);return rr;}
	}
	void split(node *ro,ty x,node*&lr,node*&rr){
		if(ro==end) {lr=rr=end;return;}
		if(ro->val<=x)
			lr=ro,split(ro->r,x,ro->r,rr);
		else 
			rr=ro,split(ro->l,x,lr,ro->l);
		update(ro);
	}
	void debug(node *ro){
		using std::cout;
		if(ro==end) return;
		debug(ro->l);
		cout<<ro->val<<' ';
		debug(ro->r);
	}
public:
	treap(){
		srand(time(0));
		end=new node(0,NULL);
		end->sz=0;
		root=end;
	}
	void insert(ty v){
		split(root,v,L,R);
		root=merge(L,merge(new node(v,end),R));
	}
	void erase(ty v){
		split(root,v-1,L,R);
		split(R,v,M,R);
		if(M!=end) {
			node *t=M;
			M=merge(M->l,M->r);
			delete t;
		}
		root=merge(L,merge(M,R));
	}
	ty getKth(size_t k){
		node *ro=root;
		size_t t;
		k<1?k=1:(k>ro->sz?k=ro->sz:0);
		while(1){
			t=ro->l->sz;
			if(k<=t) ro=ro->l;
			else if(k==t+1) return ro->val;
			else k-=t+1,ro=ro->r;
		}
	}
	size_t getRankOf(ty v){
		split(root,v-1,L,R);
		size_t ret=L->sz+1;
		root=merge(L,R);
		return ret;
	}
	void debug(){
		debug(root);puts("");
	}
};
using namespace lmdd;
int main(){
	treap<int> tr;
	int op,x,n;
	read(n);
	while(n--){
		read(op,x);
		if(op==1) tr.insert(x);
		else if(op==2) tr.erase(x);
		else if(op==3) printf("%d\n",tr.getRankOf(x));
		else if(op==4) printf("%d\n",tr.getKth(x));
		else if(op==5) printf("%d\n",tr.getKth(tr.getRankOf(x)-1));
		else if(op==6) printf("%d\n",tr.getKth(tr.getRankOf(x+1)));
	}
}