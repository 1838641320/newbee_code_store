#include <stdio.h>
#include <windows.h>
void setCursorPosition(int x, int y)//������(x,y)������ַ���ch
{
COORD coord;
coord.X = x;//�� 
coord.Y = y;//�� 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void setColor(int color)//�Զ����������ɫ����
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
puts("��");
setCursorPosition(3, 2);
puts("��");
return 0;
}
