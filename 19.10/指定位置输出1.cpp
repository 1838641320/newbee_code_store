#include <stdio.h>
#include <windows.h>
void setCursorPosition(int x, int y)//在坐标(x,y)处输出字符串ch
{
COORD coord;
coord.X = x;//行 
coord.Y = y;//列 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void setColor(int color)//自定义的文字颜色函数
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color) ;
}
int main(){
char ch2[80];
scanf("%s",ch2);
setCursorPosition(0,0);
printf("great\ngreat");
//setCursorPosition(3,2);
printf("great");
scanf("%s",ch2);
setCursorPosition(30, 9);
puts("★");
setCursorPosition(3, 2);
puts("★");
return 0;
}
