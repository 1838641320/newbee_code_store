#include<cstdio>
#include<cstring>
#include<ext/pb_ds/assoc_container.hpp>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
using namespace __gnu_pbds;
template<typename cnode, typename node,typename cmp, typename ___>
struct myupdate{
	virtual cnode node_begin() const =0;
	virtual cnode node_end() const =0;
	#define lch get_l_child()
	#define rch get_r_child()
	#define data get_metadata()
	typedef int metadata_type;
	void operator()(node it,cnode ed){
		node l=it.lch,r=it.rch;
		int left=l==ed?0:l.data,
			right=r==ed?0:r.data;
		const_cast<int&>(it.data)=left+right+(*it)->second;
	}
	int pre_sum(int x,int base=0){
		for(cnode i=node_begin();i!=node_end();){
			cnode l=i.lch,r=i.rch;
			if(x<(*i)->first) i=l;
			else {
				base+=(*i)->second;
				if(l!=node_end()) base+=l.data;
				i=r;
			}
		}
		return base;
	}
};
int main(){
	int __;scanf("%d",&__);
	for(int ___=1;___<=__;___++){
		printf("Case %d:\n",___);
		int n;scanf("%d",&n);
		tree<int,int,less<int>,rb_tree_tag,myupdate> sgt;
		for(int i=1,a;i<=n;i++)
			scanf("%d",&a),sgt.insert({i,a});
		char cmd[20];
		int a,b;
		while(scanf("%s",cmd),cmd[0]!='E'){
			scanf("%d%d",&a,&b);
			if(cmd[0]=='Q') {
				printf("%d\n",sgt.pre_sum(b)-sgt.pre_sum(a-1));
				continue;
			}
			auto j=sgt.lower_bound(a);
			sgt.erase(j);
			if(cmd[0]=='A') sgt.insert({a,j->second+b});
			else if(cmd[0]=='S') sgt.insert({a,j->second-b});
		}
	}
}