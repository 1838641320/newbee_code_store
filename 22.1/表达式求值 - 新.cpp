#include<iostream>
#include<algorithm>
#include<stack>
#include<unordered_map>
#include<functional>
using namespace std;
template<class ty>
ty eval(string str,unordered_map<char,function<ty(ty,ty)>>&func,unordered_map<char, int>&pri){
	stack<ty> nums;
	stack<char> op;
	auto eval=[&]()->void{
		auto a=nums.top();nums.pop();
		auto b=nums.top();nums.pop();
		auto c=op.top();op.pop();
		nums.push(func[c](b,a));
	};
	for (int i=0;i<(int)str.size();i++) {
		auto c=str[i];
		if(c==' ') continue;
		if (isdigit(c)) {
			ty x={};int j=i;
			while (j < (int)str.size() && isdigit(str[j]))
				x=x*10+str[j++]-'0';
			i=j-1;
			nums.push(x);
		}
		else if (c=='(') op.push(c);
		else if (c==')') {
			while (op.top()!='(') eval();
			op.pop();//op.top()=='('
		}
		else { 
			while (op.size() && op.top()!='(' && pri[op.top()]>=pri[c])
				eval();
			op.push(c);
		}
	}
	while (op.size()) eval();
	return nums.top();
}
int main() {
	unordered_map<char,function<int(int,int)>> func={
		{'&',bit_and<int>()},
		{'^',bit_xor<int>()},
		{'|',bit_or<int>()},
		{'+',plus<int>()},
		{'-',minus<int>()},
		{'*',multiplies<int>()},
		{'/',divides<int>()}
	};
	unordered_map<char,int> priority={
		{'&',-11},
		{'^',-12},
		{'|',-13},
		{'+',-6},
		{'-',-6},
		{'*',-5},
		{'/',-5}
	};
	string s;
	while(cin>>s){
		cout<<eval(s,func,priority)<<endl;
	}
}