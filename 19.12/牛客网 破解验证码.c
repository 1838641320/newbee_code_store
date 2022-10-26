#include<stdio.h>
#include<string.h>
int main(){
    int n,i;
    char in[100009],*p;
    scanf("%d",&n);
    getchar();
    while(n--){
        i=0;
        gets(in);
        while(*(in+i)){
            p=in+i;
            if(*p=='0'||*p=='2'||*p=='4'||*p=='6'||*p=='9') {
				printf("%c",*p);
				i++;
			}
			else if(!memcmp(p,"two",3)){
            	putchar('2');
            	i+=3;
			}
            else if(!memcmp(p,"six",3)){
            	putchar('6');
            	i+=3;
			}
            else if(!memcmp(p,"zero",4)){
            	putchar('0');
            	i+=4;
			}
			else if(!memcmp(p,"four",4)){
            	putchar('4');
            	i+=4;
			}
			else if(!memcmp(p,"nine",4)){
            	putchar('9');
            	i+=4;
			}
			else i++;
        }
        puts("");
    }
}
