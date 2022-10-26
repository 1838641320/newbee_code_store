#include<stdio.h>
#include<string.h>
int list[504][504],marked[505],choice[505],k,girls,boys,girl,boy,coubles;;
int partner(int girl){
	for(int i=1;i<=boys;i++){
		if(list[girl][i]&&!marked[i]){
			marked[i]=1;
			if(!choice[i]||partner(choice[i])){
				choice[i]=girl;
				return 1;
			}
		}
	}
	return 0;
}
int main() {
	while(~scanf("%d",&k)&&k!=0){
		scanf("%d%d",&girls,&boys);
		coubles=0;
		memset(list,0,4*504*504);
		memset(choice,0,4*505);
		while(k--) {
			scanf("%d%d",&girl,&boy);
			list[girl][boy]=1;
		}
		for(int i=1;i<=girls;i++){
			memset(marked,0,505*4);
			coubles+=partner(i);
		}
		printf("%d\n",coubles);
	}
}
