#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE=1010,DLEN=8,MAXN=1e8;
class BigNum{
public:
	long long a[1000];  //`可以控制大数的位数`
	int len;
	BigNum(){len=1;memset(a,0,sizeof(a));}  //`构造函数`
	BigNum(const char*);   //将一个字符串类型的变量转化为大数
	BigNum(const BigNum &); //拷贝构造函数
	BigNum &operator=(const BigNum &); //重载赋值运算符，大数之间进行赋值运算
	friend istream& operator>>(istream&,BigNum&); //重载输入运算符
	friend ostream& operator<<(ostream&,BigNum&); //重载输出运算符

	BigNum operator+(const BigNum &)const;  //重载加法运算符，两个大数之间的相加运算
	BigNum operator-(const BigNum &)const;  //重载减法运算符，两个大数之间的相减运算
	BigNum operator*(const BigNum &)const;  //重载乘法运算符，两个大数之间的相乘运算
	BigNum operator/(const int &)const;     //重载除法运算符，大数对一个整数进行相除运算

	int operator%(const int &)const;        //大数对一个int类型的变量进行取模运算
	bool operator>(const BigNum &T)const;   //大数和另一个大数的大小比较

};

//将一个字符串类型的变量转化为大数
BigNum::BigNum(const char *s){
	int k,index,L,i;
	memset(a,0,sizeof(a));
	L=strlen(s);
	len=L/DLEN;
	if(L%DLEN)len++;
	index=0;
	for(i=L-1;i>=0;i-=DLEN){
		long long t=0;
		k=i-DLEN+1;
		if(k<0)k=0;
		for(int j=k;j<=i;j++)
			t=t*10+s[j]-'0';
		a[index++]=t;
	}
}
//拷贝构造函数
BigNum::BigNum(const BigNum &b):len(b.len){
	memset(a,0,sizeof(a));
	for(int i=0;i<len;i++)
		a[i]=b.a[i];
}
//重载赋值运算符，大数之间赋值运算
BigNum & BigNum::operator=(const BigNum &n){
	len=n.len;
	memset(a,0,sizeof(a));
	for(int i=0;i<len;i++)
		a[i]=n.a[i];
	return *this;
}
istream& operator>>(istream &in,BigNum &b){
	char ch[MAXSIZE*8],*p=ch;
	in>>ch;
	bool neg=0;
	if(*p=='-') neg=1,p++;
	int L=strlen(p),count=0;
	for(int i=L-1;i>=0;){
		long long sum=0;
		int t=1;
		for(int j=0;j<DLEN&&i>=0;j++,i--,t*=10){
			sum+=(p[i]-'0')*t;
		}
		b.a[count]=sum;
		count++;
	}
	b.len=count++;
	if(neg) b.a[b.len-1]=0-b.a[b.len-1];
	return in;
}
//重载输出运算符
ostream& operator<<(ostream& out,BigNum& b){
	int i;
	cout<<b.a[b.len-1];
	for(i=b.len-2;i>=0;i--){
		printf("%08d",b.a[i]);
	}
	return out;
}
//两个大数之间的相加运算
BigNum BigNum::operator+(const BigNum &b)const{
	BigNum t(*this);
	int i,big;
	big=b.len>len?b.len:len;
	for(i=0;i<big;i++){
		t.a[i]+=b.a[i];
		t.a[i+1]+=t.a[i]/MAXN;
		t.a[i]%=MAXN;
	}
	t.len=big;
	if(t.a[big]) t.len++;
	return t;
}
//两个大数之间的相减运算
BigNum BigNum::operator-(const BigNum &b)const{
	int big;
	bool neg;
	BigNum t1,t2;
	if(*this>b){
		t1=*this;
		t2=b;
		neg=0;
	}
	else{
		t1=b;
		t2=*this;
		neg=1;
	}
	big=t1.len;
	for(int i=0;i<big;i++){
		if(t1.a[i]<t2.a[i]){
			int j=i+1;
			while(t1.a[j]==0)
				j++;
			t1.a[j--]--;
			while(j>i)
				t1.a[j--]+=MAXN-1;
			t1.a[i]+=MAXN-t2.a[i];
		}
		else t1.a[i]-=t2.a[i];
	}
	t1.len=big;
	while(t1.a[t1.len-1]==0 && t1.len>1){
		t1.len--;
		big--;
	}
	if(neg)
		t1.a[big-1]=0-t1.a[big-1];
	return t1;
}
//两个大数之间的相乘
BigNum BigNum::operator*(const BigNum &b)const{
	BigNum ret;
	for(int i=0,j;i<len;i++){
		long long up=0;
		for(j=0;j<b.len;j++){
			long long temp=a[i]*b.a[j]+ret.a[i+j]+up;
			ret.a[i+j]=temp%MAXN;
			up=temp/MAXN;
		}
		if(up) ret.a[i+j]=up;
	}
	ret.len=len+b.len;
	while(ret.a[ret.len-1]==0 && ret.len>1)ret.len--;
	return ret;
}
//大数对一个整数进行相除运算
BigNum BigNum::operator/(const int &b)const{
	BigNum ret;
	long long down=0;
	for(int i=len-1;i>=0;i--){
		ret.a[i]=(a[i]+down*MAXN)/b;
		down=a[i]+down*MAXN-ret.a[i]*b;
	}
	ret.len=len;
	while(ret.a[ret.len-1]==0 && ret.len>1)
		ret.len--;
	return ret;
}
//`大数对一个 int类型的变量进行取模`
int BigNum::operator%(const int &b)const{
	long long d=0;
	for(int i=len-1;i>=0;i--)
		d=((d*MAXN)%b+a[i])%b;
	return d;
}
//大数和另一个大数的大小比较
bool BigNum::operator>(const BigNum &b)const{
	int ln;
	if(len>b.len)return true;
	else if(len==b.len){
		ln=len-1;
		while(a[ln]==b.a[ln]&&ln>=0)
		  ln--;
		if(ln>=0 && a[ln]>b.a[ln])
		   return true;
		else
		   return false;
	}
	else
	   return false;
}

BigNum a,b,c;
void qpowb(BigNum &x,int n){
	BigNum c("1");
	for(;n;x=x*x,n/=2) 
		if(n&1) c=c*x;
	x=c;
}
int main() {
	while(cin>>a>>b){
		c=a+b;
		cout<<c<<endl;
		c=a-b;
		cout<<c<<endl;
		c=a*b;
		cout<<c<<endl;
		int ddd;scanf("%d",&ddd);
		c=c/ddd;
		cout<<c<<endl;
		int n;scanf("%d",&n);
		qpowb(a,n);
		cout<<a<<endl;
		puts("----------");
	}
}