#include <stdio.h>
#include <windows.h>
 
//���ù��λ��
void setCursorPosition(int x, int y);
//����������ɫ
void setColor(int color);
 
int main(){
setColor(3);
setCursorPosition(3, 3);
puts("��");
 
setColor(0XC);
setCursorPosition(1, 1);
puts("��");
 
setColor(6);
setCursorPosition(6, 6);
puts("��");
 
return 0;
}
 
//�Զ���Ĺ�궨λ����
void setCursorPosition(int x, int y){
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//�Զ����������ɫ����
void setColor(int color){
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color) ;
}
