#include <stdio.h>
#include <windows.h>
 
//设置光标位置
void setCursorPosition(int x, int y);
//设置文字颜色
void setColor(int color);
 
int main(){
setColor(3);
setCursorPosition(3, 3);
puts("★");
 
setColor(0XC);
setCursorPosition(1, 1);
puts("◆");
 
setColor(6);
setCursorPosition(6, 6);
puts("■");
 
return 0;
}
 
//自定义的光标定位函数
void setCursorPosition(int x, int y){
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//自定义的文字颜色函数
void setColor(int color){
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color) ;
}
