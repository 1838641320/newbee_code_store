#include<stdio.h>
#define _max ((unsigned)-1)/2
#define _min -(int)(((unsigned)-1)/2)
int main(){
	int line,col,sum,max,min,max_l,max_c,min_l,min_c,input;
	scanf("%d%d",&line,&col);
	sum=0;min=_max;max=_min;
	for (int i=0;i<line*col;i++){
		scanf("%d",&input);
		sum+=input;
		if(input>max) {max=input;max_l=i/col;max_c=i%col;}
		if(input<min) {min=input;min_l=i/col;min_c=i%col;}
	}
	printf("��Ϊ%d\n",sum);
	printf("���ֵΪ%d,�к�Ϊ%d,�к�Ϊ%d\n��СֵΪ%d,�к�Ϊ%d,�к�Ϊ%d\n",max,max_l,max_c,min,min_l,min_c);
}
