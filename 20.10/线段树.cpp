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
template<class ty=int>class segmentTree{
private:
	ty inf;
	struct node{
		size_t v;
		node *l,*r;
		node(node *n=NULL,size_t x=0){l=r=n;v=x;}
	};
	node *root,*end;
	void insert(ty v,node *&ro,ty l,ty r){
		if(ro==end) ro=new node(end);
		ro->v++;
		if(l==r) return;
		ty mid=(l+r)>>1;
		if(mid>=v) insert(v,ro->l,l,mid);
		else insert(v,ro->r,mid+1,r);
	}
	bool erase(ty v,node *ro,ty l,ty r){
		if(l==r) return ro->v--;
		if(ro==end) return false;
		ty mid=(l+r)>>1;
		if(mid>=v) {
			if(!erase(v,ro->l,l,mid)) return false;
			if(ro->l->v==0) delete(ro->l),ro->l=end;
		}
		else {
			if(!erase(v,ro->r,mid+1,r)) return false;
			if(ro->r->v==0) delete(ro->r),ro->r=end;
		}
		return ro->v--;
	}
public:
	segmentTree(ty maxv=1e9+9){
		end=new node(NULL);
		end->l=end->r=end;
		root=new node(end);
		inf=maxv;
	}
	void insert(ty v){
		if(-inf>=v||inf<=v) 
			return (void)puts("value out of bound");
		insert(v,root,-inf,inf);
	};
	void erase(ty v){
		if(-inf>=v||inf<=v) 
			return (void)puts("value out of bound");
		erase(v,root,-inf,inf);
	}
	ty getKth(size_t k){
		k<1?k=1:(k>root->v?k=root->v:0);
		size_t t;
		node *ro=root;
		ty l=-inf,r=inf,mid;
		while(l!=r){
			mid=(l+r)>>1;
			t=ro->l->v;
			if(k<=t) ro=ro->l,r=mid;
			else k-=t,ro=ro->r,l=mid+1;
		}
		return l;
	}
	size_t getRankOf(ty x){
		size_t sum=1;
		node *ro=root;
		ty l=-inf,r=inf,mid;
		while(l!=r&&ro!=end){
			ty mid=(l+r)>>1;
			if(mid<x) sum+=ro->l->v,l=mid+1,ro=ro->r;
			else r=mid,ro=ro->l;
		}
		return sum;
	}
};
using namespace lmdd;
int main(){
	int bound=2e7;
	segmentTree<ll> tr(bound);
	int op,x;
	int n;read(n);
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