#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef long long ll;
typedef struct {
	char a[12];
	int b,c;
} Player;
int cmp(const void *_a,const void *_b) {
	Player *x=(Player*)_a,*y=(Player*)_b;
	if(x->c!=y->c) return y->c-x->c;
	else if((x->b!=y->b)) return x->b-y->b;
	else return strcmp(x->a,y->a);
}
int main() {
	ll i,j,n,m,t,number_of_player;
	char in[30],*p;
	Player player[1000]= {0};
	while(~scanf("%lld%lld",&n,&m)) {
		i=0;
		while(~scanf("%s",player[i++].a)) {
			for(j=0; j<n; j++) {
				scanf("%s",in);
				t=atoi(in);
				if(t>0) {
					player[i-1].b+=t;
					player[i-1].c++;
				}
				if(p=strchr(in,'(')) player[i-1].b+=atoi(p+1)*m;
			}
		}
		number_of_player=i-1;
		qsort(player,number_of_player,sizeof(Player),cmp);
		for(i=0; i<number_of_player; i++) printf("%-10s %2d %4d\n",player[i].a,player[i].c,player[i].b);
	}
}

