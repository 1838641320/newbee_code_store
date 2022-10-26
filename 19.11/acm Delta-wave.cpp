#include<stdio.h>
#include<math.h>
int main(){
	unsigned N,M,Nc,Nl,Mc,Ml,route,col_gap;
	while(scanf("%d%d",&N,&M)!=EOF){
	if (N>M) N^=M^=N^=M;
	Nl=sqrt(N-1)+1;Nc=N-(Nl-1)*(Nl-1);
	Ml=sqrt(M-1)+1;Mc=M-(Ml-1)*(Ml-1);
	route=0+2*(Ml-Nl);
	if ((Mc>=Nc)&&((Mc-Nc)<=route)) {
		col_gap=0;
		if (Nc%2==0&&Mc%2!=0) route++;
		else if (Nc%2!=0&&Mc%2==0) route--;}
	else if(Mc>=Nc) col_gap=Mc-(Nc+2*(Ml-Nl));
	else col_gap=Nc-Mc;
	route+=col_gap;
	printf("%u\n",route);}
	return 0;
}
