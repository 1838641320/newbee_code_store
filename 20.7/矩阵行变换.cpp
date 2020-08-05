// #include<bits/extc++.h>
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
class fract{
public:
	int num,den;
	void simplify(){
		auto &a=*this;
		int g=__gcd(a.num,a.den);
		a.num/=g;
		a.den/=g;
		if(a.den<0) a.num*=-1,a.den*=-1;
	}
	void print(){
		printf("%d",num);
		if(den^1) printf("/%d",den);
	}
};
class gauss_cal{
public:
	typedef vector<fract> vec;
	typedef vector<vec> Matrix;
	int line=3,col=3;
	Matrix matrix;
	fract det={1,1};
	void init(int l,int c){
		char ch;int a,b;
		matrix.clear();
		line=l,col=c;
		matrix.resize(l,vec(c));
		rep(i,0,l) rep(j,0,c){
			scanf("%d%c",&a,&ch);
			if(ch=='/') scanf("%d",&b);
			else b=1;
			matrix[i][j]={a,b};
		}
	}
	void print(){
		for(auto &i:matrix) {
			for(auto &j:i) {
				j.print();
				putchar('\t');
			}
			puts("\n");
		}
		puts("");
	}
	void Swap(int l1,int l2){
		l1--,l2--;
		swap(matrix[l1],matrix[l2]);
	}
	void add(int l1,int l2,int mul,int div){
		if(l1<0||l2<0||l1>line||l2>line) return;
		l1--,l2--;
		for(int i=0;i<col;i++){
			auto &a=matrix[l1][i],b=matrix[l2][i];
			a.num=a.num*b.den*div+b.num*a.den*mul;
			a.den*=b.den*div;
			a.simplify();
		}
	}
	void mul(int l1,int mul,int div){
		if(l1<0||l1>line) return;
		l1--;
		det={det.num*div,det.den*mul};det.simplify();
		for(int i=0;i<col;i++){
			auto &a=matrix[l1][i];
			a.num*=mul;
			a.den*=div;
			a.simplify();
		}
	}
};
void autosolve(gauss_cal::Matrix mat,fract det){
	int l=mat.size(),c=mat[0].size();
	
}
int getnext_int(char *&p){
	while(*p&&!isdigit(*p)) p++;
	return strtol(p,&p,10);
}
int main(){
	int l,c,l1,l2,pre=2;
	char cmd[99],*p;
	gauss_cal mat;
	while(scanf("%d%d",&l,&c)==2){
		fflush(stdin);
		mat.init(l,c);fflush(stdin);
		while(fgets(cmd,99,stdin),*cmd!='!'){
			if(strcmp(cmd,"det\n")==0){
				mat.det.print();
				puts("");
				continue;
			}
			if(strcmp(cmd,"autosolve\n")==0){
				autosolve(mat.matrix,mat.det);
				continue;
			}
			p=cmd;
			l1=getnext_int(p);
			if(count(cmd,cmd+99,' ')){
				l2=getnext_int(p);
				mat.Swap(l1,l2);
				mat.print();
				continue;
			}
			int flag=count(cmd,cmd+99,'+')+count(cmd,cmd+99,'-')*2;
				flag+=count(cmd,cmd+99,'*')*4+count(cmd,cmd+99,'/')*8;
			int mul=flag&2?-1:1,div=1;
			if(flag&4) mul*=getnext_int(p);
			if(flag&8) div=getnext_int(p);
			if(count(cmd,cmd+99,'r')==1)
				mat.mul(l1,mul,div);
			if(count(cmd,cmd+99,'r')==2){
				l2=getnext_int(p);
				mat.add(l1,l2,mul,div);
			}
			mat.print();
			memset(cmd,0,sizeof cmd);
		}
	}
}
/*

one
r1 r2 

two
r2+r2
r1-r2
r2+2*r1
r2+3/5*r3

three
r1*4

four
det

five
!

six
autosolve

*/