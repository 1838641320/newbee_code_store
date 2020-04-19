#include"stdafx.h"
#include<bits/stdc++.h>
using namespace std;
const char *read="%d%d",*out="%d\n";
int main() {
	int a,b;
	__asm {
		lea ebx,b
		push ebx
		lea ebx,a
		push ebx
		push read
		call scanf
		sub eax,eax
		add eax,[a]
		add eax,[b]
		push eax
		push out
		call printf
		mov eax,[a]
		sub eax,[b]
		mov dword ptr[esp+4],eax
		call printf
		mov eax,[a]
		imul eax,[b]
		mov dword ptr[esp+4],eax
		call printf
		add esp,16
	}
}