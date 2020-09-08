#include<functional>
#include<cstdio>
#include<random>
#include<ctime>
using namespace std;
template<class ty=int,class Cmp=less<ty>,int maxn=(int)1e6+9>
struct myheap{
	function<bool(ty,ty)> cmp=Cmp();
	int sz;
	ty v[maxn];
	void clear(){sz=0;}
	void push(int x){
		v[++sz]=x;
		for(int p=sz;p>1;p/=2){
			if(cmp(v[p/2],v[p])) return;
			swap(v[p/2],v[p]);
		}
	}
	int pop(){
		swap(v[1],v[sz--]);
		for(int p=1,t=1;;p=t){
			if(p*2<=sz&&cmp(v[p*2],v[t])) t=p*2;
			if(p*2+1<=sz&&cmp(v[p*2+1],v[t])) t=p*2+1;
			if(t==p) break;
			swap(v[p],v[t]);
		}
		return v[sz+1];
	}
};
int main(){
	mt19937 rd(time(0));
	myheap<> pq;
	int x;
	while(scanf("%d",&x)==1){
		pq.clear();
		for(int i=0;i<x;i++) pq.push(rd()%(x*50));
		for(int i=1;i<=pq.sz;i++) printf("%d ",pq.v[i]);puts("\n\n");
		while(pq.sz) printf("%d ",pq.pop());puts("\n\n");
	}
}