#include <bits/extc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> balanced_tree;
balanced_tree tr;
int main(){
    mt19937 rd(time(0));
	for(int i=1;i<99;i++) tr.insert(rd()%200);
	for(int i:tr) printf("%d ",i);
	puts("");
	int a;
	while(cin>>a){
		auto fa=tr.find_by_order(a);
		if(fa!=tr.end()) 
		printf("       %dth big :%d\n",a,*tr.find_by_order(a));
		printf("%d number is :%d th big\n",a,tr.order_of_key(a));
	}
}