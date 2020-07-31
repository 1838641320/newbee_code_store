#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
rope<int> S;
int n;
map<int,int> ans;
int main(){
	while(~scanf("%d",&n)){
		S.clear();ans.clear();
		S.insert(0,8001,-1);
		for(int i=1;i<=n;i++){
			int a,b,c;scanf("%d%d%d",&a,&b,&c);
			int len=b-a;
			S.erase(a+1,len);S.insert(a+1,len,c);
		}
		for(int i=0;i<=8000;){
			int c=S[i];
			if(~c) ans[c]++;
			while(i<=8000&&S[i]==c) i++;
		}
		for(auto i:ans) printf("%d %d\n",i.first,i.second);
		puts("");
	}
}