#include"stdafx.h"
#include<bits/stdc++.h>
using namespace std;
int main() {
	char s[700] = {};
	cin>>s;
	for (int i = strlen(s)-2;i>=0;) {
		if (s[i+1]<0) {
			putchar(s[i]),putchar(s[i+1]);
			i -= 2;
		}
		else putchar(s[i--+1]);
	}
	if (s[0]>0) putchar(s[0]);
}