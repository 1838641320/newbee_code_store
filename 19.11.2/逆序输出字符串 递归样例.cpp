#include <stdio.h>
void reverse_str(char *p){
    if(*p){
        reverse_str(p+1);
        putchar(*p);
    }
}
int main(){
    char str[666];
    gets(str);
    reverse_str(str);
}
