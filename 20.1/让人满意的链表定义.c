#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Word {
	int n;
	char a[76];
	struct Word* next;
} wd;
int size =sizeof(wd);
int main() {
	int choice,i_node;
	wd *start,*now,*p;
	while(1) {
		scanf("%d",&choice);
		switch(choice) {
		case 0://新建 
			i_node=1;
			start=malloc(size);
			memset(start->a,0,76);
			scanf("%s",start->a);
			getchar();
			start->n=i_node;
			start->next=0;
			now=start;
		case 1: {//增加内容，直到输入失败 
			char b[76]={0};
			while(~scanf("%s",b)){
				getchar();
				i_node++;
				p=malloc(size);
				now->next=p;
				now=now->next;
				strcpy(now->a,b);
				now->n=i_node;
				p->next=0;
			}
			break;
		}
		case 2://输出 
			for(p=start;;p=p->next){
				printf("%s ",p->a);
				if(p->next==0) break;
			}
			puts("");
		}
	}
}
