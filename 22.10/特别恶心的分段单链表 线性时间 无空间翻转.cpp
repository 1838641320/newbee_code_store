#include <algorithm>
#include <cstring>
#include <iostream>
#define rep(i, a, b) for (int i = a; i < (int)b; i++)
using namespace std;
typedef long long ll;
const ll mod = 998244353;

struct list_node{
	int val;
	list_node *nex;
};
list_node *cr(const vector<int> &a){
	list_node *ret=nullptr;
	for(int i=a.size()-1;i>=0;i--){
		auto t=new list_node({a[i]});
		t->nex=ret;
		ret=t;
	}
	return ret;
}
list_node *fxxx(list_node *li){
	if(li==nullptr||li->nex==nullptr) return li;
	auto same=[](list_node *a){
		if(!a||!a->nex) return false;
		return a->val==a->nex->val;
	};
	int sa=same(li);
	list_node *ret=nullptr,*p1=li,*p2=li,*r1;//[]
	while(p2!=nullptr){
		while(sa==same(p2->nex)&&p2->nex){
			p2=p2->nex;
		}
		sa=same(p2->nex);
		list_node *l1=nullptr;
		if(p2!=nullptr&&!sa) p2=p2->nex;
		if(p2!=nullptr) p2=p2->nex;
		for(auto x=p1;x!=p2;){//[)
			auto t=x->nex;
			x->nex=l1;
			l1=x;
			x=t;
		}
		if(!ret){
			r1=ret=l1;
			while(r1->nex) r1=r1->nex;
		}
		else r1->nex=l1;
		while(r1->nex) r1=r1->nex;
		p1=p2;
	}
	return ret;
}
list_node *fx(list_node *li){
	vector<decltype(li->val)> tp;
	
}
void print_li(list_node *li){
	while(li!=nullptr)
		cout<<li->val<<' ',li=li->nex;
	cout<<endl;
}
void solve(int __ca = 0) {
	print_li(fxxx(cr({1,2,2,3,4,5,3,3,3,4,5})));
	print_li(fxxx(cr({2,2,3,4,4,4,3})));
	print_li(fxxx(cr({1,2,3,4,5})));
}
int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);cout.tie(0);
	int t = 1;
	// cin>>t;
	for (int i = 1; i <= t; i++) solve();
}
