#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
namespace BigInt{
	typedef long long ll;
	typedef std::vector<ll> Int;
	const ll bi=1e8;
	void print(Int a){
		printf("%lld",a.back());
		for(int i=a.size()-2;~i;i--) printf("%08lld",a[i]);
	}
	inline ll adc(ll a,ll &carry){
		carry=(a+=carry)/bi;
		return a-bi*carry;
	}
	Int make(const std::string&s){
		Int a;int l=s.size();
		for(int i=l-8;i>=0;i-=8)
			a.push_back(std::stoll(s.substr(i,8)));
		if(l%8) 
			a.push_back(std::stoll(s.substr(0,l%8)));
		return a;
	}
	Int operator*(Int a,Int b){
		Int c(a.size()+b.size()+2);
		for(int i=0;i<(int)a.size();i++){
			ll carry=0;
			for(int j=0;j<(int)b.size();j++)
				c[i+j]=adc(c[i+j]+a[i]*b[j],carry);
			if(carry) c[i+b.size()]+=carry;
		}
		while(c.size()>1&&c.back()==0) c.pop_back();
		return c;
	}
	Int operator*(Int a,int b){//b<=bi
		ll carry=0;
		for(ll &i:a) i=adc(i*b,carry);
		if(carry) a.push_back(carry);
		while(a.size()>1&&a.back()==0) a.pop_back();
		return a;
	}
	Int operator+(Int a,Int b){
		if(b.size()>a.size()) swap(a,b);
		ll carry=0;
		for(int i=0;i<(int)b.size();i++)
			a[i]+=b[i];
		for(ll &i:a) i=adc(i,carry);
		if(carry) a.push_back(carry);
		return a;
	}
	Int operator/(Int a,int b){
		ll carry=0;
		for(int i=a.size()-1;i>=0;i--)
			carry=(a[i]+=carry*bi)%b,
			a[i]/=b;
		while(a.size()>1&&a.back()==0) a.pop_back();
		return a;
	}
	Int operator-(Int a,Int b){//b<=a
		for(int i=0;i<(int)b.size();i++){
			a[i]-=b[i];
			if(a[i]<0) a[i]+=bi,a[i+1]--;
		}//a-b=-(b-a) if negative
		while(a.size()>1&&a.back()==0) a.pop_back();
		return a;
	}
	bool operator<(const Int&a,const Int&b){
		if(a.size()!=b.size()) 
			return a.size()<b.size();
		for(int i=a.size()-1;i>=0;i--)
			if(a[i]!=b[i]) return a[i]<b[i];
		return 0;
	}
	Int qpow(Int a,ll n){
		Int c=make("1");
		for(;n;n/=2,a=a*a) if(n&1) c=c*a;
		return c;
	}
	Int operator/(Int a,Int b){
		auto get=[](const Int&a,unsigned p)->__int128_t{return p<a.size()?a[p]:0;};
		Int res;
		ll bsz=b.size(),db=get(b,bsz-1)*bi+get(b,bsz-2)+1;
		while(b.size()<a.size()) b.insert(b.begin(),0);
		for(int i=a.size();i>=bsz;i--){
			auto m=(get(a,i)*bi*bi+get(a,i-1)*bi+get(a,i-2))/db;
			a=a-b*m;
			while(!(a<b)) a=a-b,m++;
			res.insert(res.begin(),m);
			b.erase(b.begin());
		}
		while(res.size()>1&&res.back()==0) res.pop_back();
		if(res.empty()) res.push_back(0);
		return res;
	}
}

struct BigIntTiny {
	int sign;
	std::vector<int> v;

	BigIntTiny() : sign(1) {}
	BigIntTiny(const std::string &s) { *this = s; }
	BigIntTiny(int v) {
		char buf[21];
		sprintf(buf, "%d", v);
		*this = buf;
	}
	void zip(int unzip) {
		if (unzip == 0) {
			for (int i = 0; i < (int)v.size(); i++)
				v[i] = get_pos(i * 4) + get_pos(i * 4 + 1) * 10 + get_pos(i * 4 + 2) * 100 + get_pos(i * 4 + 3) * 1000;
		} else
			for (int i = (v.resize(v.size() * 4), (int)v.size() - 1), a; i >= 0; i--)
				a = (i % 4 >= 2) ? v[i / 4] / 100 : v[i / 4] % 100, v[i] = (i & 1) ? a / 10 : a % 10;
		setsign(1, 1);
	}
	int get_pos(unsigned pos) const { return pos >= v.size() ? 0 : v[pos]; }
	BigIntTiny &setsign(int newsign, int rev) {
		for (int i = (int)v.size() - 1; i > 0 && v[i] == 0; i--)
			v.erase(v.begin() + i);
		sign = (v.size() == 0 || (v.size() == 1 && v[0] == 0)) ? 1 : (rev ? newsign * sign : newsign);
		return *this;
	}
	std::string to_str() const {
		BigIntTiny b = *this;
		std::string s;
		for (int i = (b.zip(1), 0); i < (int)b.v.size(); ++i)
			s += char(*(b.v.rbegin() + i) + '0');
		return (sign < 0 ? "-" : "") + (s.empty() ? std::string("0") : s);
	}
	bool absless(const BigIntTiny &b) const {
		if (v.size() != b.v.size()) return v.size() < b.v.size();
		for (int i = (int)v.size() - 1; i >= 0; i--)
			if (v[i] != b.v[i]) return v[i] < b.v[i];
		return false;
	}
	BigIntTiny operator-() const {
		BigIntTiny c = *this;
		c.sign = (v.size() > 1 || v[0]) ? -c.sign : 1;
		return c;
	}
	BigIntTiny &operator=(const std::string &s) {
		if (s[0] == '-')
			*this = s.substr(1);
		else {
			for (int i = (v.clear(), 0); i < (int)s.size(); ++i)
				v.push_back(*(s.rbegin() + i) - '0');
			zip(0);
		}
		return setsign(s[0] == '-' ? -1 : 1, sign = 1);
	}
	bool operator<(const BigIntTiny &b) const {
		return sign != b.sign ? sign < b.sign : (sign == 1 ? absless(b) : b.absless(*this));
	}
	bool operator==(const BigIntTiny &b) const { return v == b.v && sign == b.sign; }
	BigIntTiny &operator+=(const BigIntTiny &b) {
		if (sign != b.sign) return *this = (*this) - -b;
		v.resize(std::max(v.size(), b.v.size()) + 1);
		for (int i = 0, carry = 0; i < (int)b.v.size() || carry; i++) {
			carry += v[i] + b.get_pos(i);
			v[i] = carry % 10000, carry /= 10000;
		}
		return setsign(sign, 0);
	}
	BigIntTiny operator+(const BigIntTiny &b) const {
		BigIntTiny c = *this;
		return c += b;
	}
	void add_mul(const BigIntTiny &b, int mul) {
		v.resize(std::max(v.size(), b.v.size()) + 2);
		for (int i = 0, carry = 0; i < (int)b.v.size() || carry; i++) {
			carry += v[i] + b.get_pos(i) * mul;
			v[i] = carry % 10000, carry /= 10000;
		}
	}
	BigIntTiny operator-(const BigIntTiny &b) const {
		if (sign != b.sign) return (*this) + -b;
		if (absless(b)) return -(b - *this);
		BigIntTiny c;
		for (int i = 0, borrow = 0; i < (int)v.size(); i++) {
			borrow += v[i] - b.get_pos(i);
			c.v.push_back(borrow);
			c.v.back() -= 10000 * (borrow >>= 31);
		}
		return c.setsign(sign, 0);
	}
	BigIntTiny operator*(const BigIntTiny &b) const {
		if (b < *this) return b * *this;
		BigIntTiny c, d = b;
		for (int i = 0; i < (int)v.size(); i++, d.v.insert(d.v.begin(), 0))
			c.add_mul(d, v[i]);
		return c.setsign(sign * b.sign, 0);
	}
	BigIntTiny operator/(const BigIntTiny &b) const {
		BigIntTiny c, d;
		d.v.resize(v.size());
		double db = 1.0 / (b.v.back() + (b.get_pos((unsigned)b.v.size() - 2) / 1e4) +
						   (b.get_pos((unsigned)b.v.size() - 3) + 1) / 1e8);
		for (int i = (int)v.size() - 1; i >= 0; i--) {
			c.v.insert(c.v.begin(), v[i]);
			int m = (int)((c.get_pos((int)b.v.size()) * 10000 + c.get_pos((int)b.v.size() - 1)) * db);
			c = c - b * m, d.v[i] += m;
			while (!(c < b))
				c = c - b, d.v[i] += 1;
		}
		return d.setsign(sign * b.sign, 0);
	}
	BigIntTiny operator%(const BigIntTiny &b) const { return *this - *this / b * b; }
	bool operator>(const BigIntTiny &b) const { return b < *this; }
	bool operator<=(const BigIntTiny &b) const { return !(b < *this); }
	bool operator>=(const BigIntTiny &b) const { return !(*this < b); }
	bool operator!=(const BigIntTiny &b) const { return !(*this == b); }
};
