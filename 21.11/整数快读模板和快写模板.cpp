int gc(){
	const int Q=(1<<23)+1;
	static char in[Q],*is=in,*it=in;
	return is==it?it=(is=in)+fread(in,1,Q,stdin),(is==it?EOF:*is++):*is++;
}
template<class A>
void print(A a,char c=' '){
	static char o1[99]={},*o=o1;
	if(a<0) putchar('-'),a=-a;
	if(a==0) putchar('0');
	while(a>0) *(++o)=a%10,a/=10;
	while(o!=o1) putchar(*(o--)+48);
	putchar(c);
}
template<class A,class ...B>
void print(A a,char c,B...b){
	print(a,c);
	print(b...);
}
template<class T> void read(T&a){
	a=0;int f=0,c=gc();
	for(;!isdigit(c);c=gc()) f|=c=='-';
	for(;isdigit(c);c=gc()) a=a*10+(c^'0');
	if(f) a=-a;
}
template<class A,class...B>
void read(A&x,B&...y){read(x),read(y...);}
