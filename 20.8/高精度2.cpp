#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE=1010,DLEN=8,MAXN=1e8;
class BigNum{
public:
	long long a[1000];  //`���Կ��ƴ�����λ��`
	int len;
	BigNum(){len=1;memset(a,0,sizeof(a));}  //`���캯��`
	BigNum(const char*);   //��һ���ַ������͵ı���ת��Ϊ����
	BigNum(const BigNum &); //�������캯��
	BigNum &operator=(const BigNum &); //���ظ�ֵ�����������֮����и�ֵ����
	friend istream& operator>>(istream&,BigNum&); //�������������
	friend ostream& operator<<(ostream&,BigNum&); //������������

	BigNum operator+(const BigNum &)const;  //���ؼӷ����������������֮����������
	BigNum operator-(const BigNum &)const;  //���ؼ������������������֮����������
	BigNum operator*(const BigNum &)const;  //���س˷����������������֮����������
	BigNum operator/(const int &)const;     //���س����������������һ�����������������

	int operator%(const int &)const;        //������һ��int���͵ı�������ȡģ����
	bool operator>(const BigNum &T)const;   //��������һ�������Ĵ�С�Ƚ�

};

//��һ���ַ������͵ı���ת��Ϊ����
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
//�������캯��
BigNum::BigNum(const BigNum &b):len(b.len){
	memset(a,0,sizeof(a));
	for(int i=0;i<len;i++)
		a[i]=b.a[i];
}
//���ظ�ֵ�����������֮�丳ֵ����
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
//������������
ostream& operator<<(ostream& out,BigNum& b){
	int i;
	cout<<b.a[b.len-1];
	for(i=b.len-2;i>=0;i--){
		printf("%08d",b.a[i]);
	}
	return out;
}
//��������֮����������
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
//��������֮����������
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
//��������֮������
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
//������һ�����������������
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
//`������һ�� int���͵ı�������ȡģ`
int BigNum::operator%(const int &b)const{
	long long d=0;
	for(int i=len-1;i>=0;i--)
		d=((d*MAXN)%b+a[i])%b;
	return d;
}
//��������һ�������Ĵ�С�Ƚ�
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