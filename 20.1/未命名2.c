
#include <stdio.h>
using namespace std;
#define MAXLINE 1000

void rcomment(int c);
void in_comment(void);
void deleteTail(void);
FILE* fp;
FILE* fp2;

int main()
{
    fp=fopen("1.c","r");
    fp2=fopen("2.c","w");
    bool deleteMutiline=false;
    char line[MAXLINE];
    int c;
    while((c=getc(fp))!=EOF)
        rcomment(c);
    return 0;
}
void rcomment(int c){
    int d;
    if(c=='/'){
        if((d=getc(fp))=='*')
            in_comment();
        else if (d=='/')
            deleteTail();
        else
        {
            putc(c,fp2);
            putc(d,fp2);
        }
    }else
        putc(c,fp2);
}
void in_comment(void){
    int c,d;
    c=getc(fp);
    d=getc(fp);
    while (c!='*'||d!='/')
    {
        c=d;
        d=getc(fp);
    }
}
void deleteTail(){
    int c;
    c=getc(fp);
    while (c!='\n')
    {
        c=getc(fp);
    }
    putc('\n',fp2);
}
