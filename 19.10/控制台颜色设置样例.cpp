#include <conio.h>
#include <stdio.h>
#include <windows.h>
int main()
{
//system("color f0");
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    int i;
    for (i=0;i<255;i++)
    {
        SetConsoleTextAttribute(hOut, i);
        printf("%3d\t",i);
    }
    printf("\n");
    SetConsoleTextAttribute(hOut, 0x0007);
    printf("ÑÝÊ¾½áÊø");
    getch();
    return 0;
}
