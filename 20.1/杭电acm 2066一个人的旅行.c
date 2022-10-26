#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxn 1005
int T,S,D,cities,answer;
int way[maxn][maxn]={0},time[maxn],start[maxn],end[maxn];
void search(int sn){
	for(int i=0;i<D;i++) if(sn==end[i]) return;
	for(int i=1;i<=cities;i++) {
		if(way[sn][i]&&time[i]>time[sn]+way[sn][i]){
			time[i]=time[sn]+way[sn][i];
			search(i);
		}
	}
}
int main(){
	while(~scanf("%d%d%d",&T,&S,&D)){
		cities=0;
		answer=0x7fffffff;
		memset(time,0x3f,maxn*4);
		memset(way,0,maxn*maxn*4);
		while(T--) {
			int a,b,t;
			scanf("%d%d%d",&a,&b,&t);
			if(t<way[a][b]||!way[a][b]){
				way[a][b]=t;
				way[b][a]=t;
			}
			cities=__max(cities,a);
			cities=__max(cities,b);
		}
		for(int i=0;i<S;i++) scanf("%d",&start[i]);
		for(int i=0;i<D;i++) scanf("%d",&end[i]);
		for(int i=0;i<D;i++) time[end[i]]=0x7fffffff;
		for(int i=0;i<S;i++) time[start[i]]=0;
		for(int i=0;i<S;i++) search(start[i]);
		for(int i=0;i<D;i++) answer=__min(answer,time[end[i]]);
		printf("%d\n",answer);
	}
}
