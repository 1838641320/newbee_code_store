#include<stdio.h>
int main(){
	short bit=0,c[1003],d=0,ia,ib;
	char a[1005]={0},b[1005]={0};
	bit=0;
	for (ia=1;;ia++) {//�������1
		a[ia]=getchar();
		if ((a[ia]<'0')||(a[ia]>'9')) {a[ia]=15;break;}
		a[ia]=(a[ia]-'0');} 
	for (ib=1;;ib++) {//�������2
		b[ib]=getchar();
		if ((b[ib]<'0')||(b[ib]>'9')) {b[ib]=15;break;}
		b[ib]=(b[ib]-'0');}
	printf("\n");
	while((ib>0)||(ia>0))//�͵�����������c[] �ӵ�λ�ŵ���λ 
		{
		c[bit]=a[ia-1]+b[ib-1]+d;
		if (c[bit]>9)
			{c[bit]=c[bit]-10;
			d=1;}
		else d=0;
		if (ia>0) ia--;
		if (ib>0) ib--;
		bit++;
		}
	bit--;
	if (c[bit]==1) printf("1");
	bit--;
	//�Ӹ�λ���λ���
	for(;bit>=0;bit--) printf("%d",c[bit]);}
