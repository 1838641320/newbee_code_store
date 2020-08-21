#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
using TR=__gnu_pbds::tree<pair<int,int>,__gnu_pbds::null_type,less<pair<int,int>>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
using ll=long long;
const int maxn=2e5+9;
int main(){
	TR tree;
	int n,opt,x;
	scanf("%d",&n);
	rep(tag,0,n){
		scanf("%d %d",&opt,&x);
		if(opt==1) tree.insert({x,tag});
		else if(opt==2)
			tree.erase(tree.lower_bound({x,0}));
		else if(opt==3)
			printf("%d\n",tree.order_of_key({x,0})+1);
		else if(opt==4)
			printf("%d\n",*tree.find_by_order(x-1));
		else if(opt==5){
			auto it=tree.lower_bound({x,0});
			printf("%d\n",*--it);
		}
		else if(opt==6){
			auto it=tree.upper_bound({x,1e9});
			printf("%d\n",*it);
		}
	}
}