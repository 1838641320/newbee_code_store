# include <stdio.h>
int DayExit(short leap, short month, short day)
{   if (day<1) return 0;
	switch (month){
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
	if (day>31) return 0;
	else 		return 1;
	case 4:case 6:case 9:case 11:
	if (day>30) return 0;
	else 		return 1;
	case 2:
	if (day>(28+leap)) 
				return 0;
	else 		return 1;
	default:	return 0;}
}
int main(void)
{int year;
short month,day,leap;
scanf("%d%hd%hd",&year,&month,&day);
leap=(year%4==0&&year%100!=0)||(year%400==0);
if (DayExit(leap,month,day)) printf("True");
else printf("False");
return 0;
}
