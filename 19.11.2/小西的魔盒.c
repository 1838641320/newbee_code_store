#include<stdio.h>
#include<string.h>
#define empty 9187201950435737471
int main() {
	long long n,y,op;
	int not_first=0;
	scanf("%lld",&n);
	long long bottom,top,box[100000+10],j;
	memset(box,127,8*100000+80);
	bottom=0;
	top=1;
	while(n--) {
		scanf("%lld",&op);
		switch(op) {
		case 0:
			scanf("%lld",&y);
			for(j=top; j>bottom&&y<box[j-1]; j--)
				box[j]=box[j-1];
			box[j]=y;
			top++;
			break;
		case 1:
			if(box[bottom]!=empty&&not_first) printf(" %lld",box[bottom]);
			if(box[bottom]!=empty&&not_first==0) {
				printf("%lld",box[bottom]);
				not_first++;
			}
			box[bottom]=empty;
			if(box[bottom+1]!=empty) bottom++;
			else {
				bottom=0;
				top=1;
			}
			break;
		}
	}
}