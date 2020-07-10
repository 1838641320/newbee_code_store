#include"s.h"
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
class gauss_cal{
public:
	struct fract{ int num,den; };
	typedef vector<fract> vec;
	typedef vector<vec> Matrix;
	int line=3,col=3,precision=2;
	Matrix matrix;
	fract det={1,1};
	void init(int l,int c){
		matrix.clear();
		line=l,col=c;
		matrix.resize(l,vec(c));
		rep(i,0,l) rep(j,0,c)
			cin>>matrix[i][j].num,
			matrix[i][j].den=1;
	}
	void print(){
		for(auto &i:matrix) {
			for(auto &j:i) {
				printf("%d",j.num);
				if(j.den!=1) printf("/%d ",j.den);
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
			auto a=matrix[l1][i],b=matrix[l2][i];
			a.num=a.num*b.den*div+b.num*a.den*mul;
			a.den*=b.den*div;
			matrix[l1][i]=simplify(a);
		}
	}
	void mul(int l1,int mul,int div){
		if(l1<0||l1>line) return;
		l1--;
		det=simplify({det.num*div,det.den*mul});
		for(int i=0;i<col;i++){
			auto a=matrix[l1][i];
			a.num*=mul;
			a.den*=div;
			matrix[l1][i]=simplify(a);
		}
	}
	fract simplify(fract a){
		int g=gcd(a.num,a.den);
		a.num/=g;
		a.den/=g;
		if(a.den<0) a.num*=-1,a.den*=-1;
		return a;
	}
};
void autosolve(gauss_cal::Matrix mat,gauss_cal::fract det){
	int l=mat.size(),c=mat[0].size();
	
}
int main(){
	int l,c,l1,l2,pre=2;
	char cmd[99],*p;
	gauss_cal mat;
	while(cin>>l>>c){
		mat.init(l,c);
		while(fgets(cmd,99,stdin),*cmd!='!'){
			if(strcmp(cmd,"det\n")==0){
				printf("%d",mat.det.num);
				if(mat.det.den!=1) printf("/%d",mat.det.den);
				puts("");
				continue;
			}
			if(strcmp(cmd,"autosolve\n")==0){
				autosolve(mat.matrix,mat.det);
				continue;
			}
			p=cmd;
			while(*p&&!isdigit(*p)) p++;
			l1=strtol(p,&p,10);
			if(count(cmd,cmd+99,' ')){
				while(*p&&!isdigit(*p)) p++;
				l2=strtol(p,&p,10);
				mat.Swap(l1,l2);
				mat.print();
				continue;
			}
			int flag=count(cmd,cmd+99,'+')+count(cmd,cmd+99,'-')*2;
			flag+=count(cmd,cmd+99,'*')*4+count(cmd,cmd+99,'/')*8;
			int mul=flag&2?-1:1,div=1;
			if(flag&4){
				while(*p&&!isdigit(*p)) p++;
				mul*=strtol(p,&p,10);
			}
			if(flag&8){
				while(*p&&!isdigit(*p)) p++;
				div=strtol(p,&p,10);
			}
			if(count(cmd,cmd+99,'r')==1)
				mat.mul(l1,mul,div);
			if(count(cmd,cmd+99,'r')==2){
				while(*p&&!isdigit(*p)) p++;
				l2=strtol(p,&p,10);
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