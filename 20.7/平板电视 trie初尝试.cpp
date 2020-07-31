#include <bits/extc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
using namespace __gnu_pbds;
typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pref_trie;
pref_trie t1;
int main(){
    string a;
	int n=0;
	while(cin>>a,a[0]!='!') t1.insert(a);
	puts("insertion complete");
	int tyyy=1,b,cnt;
	while(tyyy){
		cin>>a;
		auto res=t1.prefix_range(a);
		cnt=0;
		for(auto i=res.first;i!=res.second;i++) cnt++;
		cout<<cnt<<endl;

		// cout<<t1.order_of_key(a)<<endl;

		// auto lb=t1.lower_bound(a),ub=t1.upper_bound(a);
		// for(auto i:*lb) cout<<i<<endl;
		// puts("------");
		// for(auto i:*ub) cout<<i<<endl;
	}
}