#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#define maxn 6666
int ar[maxn];
char save[maxn*6+8];
int cmp(int *a,int *b){return *a-*b;}
#define improve
#ifdef self_first
void merge_sort(int *s,int *e){
	if(s+1>=e) return;
	int *m=s+(e-s)/2;
	merge_sort(s,m);
	merge_sort(m,e);
	int t[e-s];
	for(int i=0,j=0,k=0;i+j<e-s;){
		for(;s+i<m&&(cmp(&s[i],&m[j])>=0||m+j==e);i++) 
			t[k++]=s[i];
		for(;m+j<e&&(cmp(&s[i],&m[j])<0||s+i==m);j++) 
			t[k++]=m[j];
	}
	memcpy(s,t,sizeof(t));
}
#endif
#ifdef improve
void merge_sort(int *s,int *e){
	if(s+1>=e) return;
	int *m=s+(e-s)/2;
	merge_sort(s,m);
	merge_sort(m,e);
	int *i=s,*j=m,*t=(int*)malloc(4*(e-s)),*k=t;
	while(i<m&&j<e){
		if(cmp(i,j)>0) *k++=*i++;
		else *k++=*j++;
	}
	while(i<m) *k++=*i++;
	while(j<e) *k++=*j++;
	memcpy(s,t,4*(e-s));
}
#endif
int main(){
	srand(time(0));
	for(int i=0;i<maxn;i++) ar[i]=rand();
	double start=clock();
	merge_sort(ar,ar+maxn);
	printf("%lf\n",clock()-start);
	for(int i=0;i<maxn;i++) sprintf(save+i*6,"%5d%c",ar[i],i%16==15?'\n':' ');
	puts(save);
}
