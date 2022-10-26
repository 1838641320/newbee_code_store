# include <stdio.h>
int DayExit(int year, int month, int day) {
	int d,leap;
	if(leap==(year%4==0&&year%100!=0||year%400==0)) {
		switch(month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			d=31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			d=30;
			break;
		case 2:
			d=29;
			break;
		}
	} else {
		switch(month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			d=31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			d=30;
			break;
		case 2:
			d=28;
			break;
		}
	}
	if(month<=12&&month>0&&day<=d&&day>0)
		printf("1");
	else
		printf("0");
}

int main(void) {
	int year,month,day;
	while(scanf("%d%d%d",&year,&month,&day)!=EOF) {
		DayExit(year,month,day);
	}
	return 0;
}

