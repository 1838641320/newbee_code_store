#include<stack>
#include<iostream>
using namespace std;
typedef struct ET {
	int n;
	char A,B,C;
};
stack<ET> st;
void print(ET et) {
	cout<<et.A<<"->"<<et.C<<endl;
}
void hanio(int n,char A,char B,char C) {
	st.push({n,A,B,C});
	while (!st.empty()) {
		ET now = st.top();st.pop();
		if (now.n<2) { print(now); continue; }
		else {
			st.push({now.n-1,now.B,now.A,now.C});//这里注意入栈顺序
			st.push({1,now.A,now.B,now.C});//递归是A B、B C
			st.push({now.n-1,now.A,now.C,now.B});//由于栈的顺序，注意B C、A B
		}
	}
}
int main() {
	int n;
	cin>>n;
	hanio(n,'A','B','C');
}
