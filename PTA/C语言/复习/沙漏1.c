#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
    int i=0;
    
    char b;
    
    scanf("%d %c",&i,&b);
    int n=i;
    if(i<=7){
        printf("%c",b);
        printf("\n%d",n-1);
    }
    else if(i<=17){
        printf("%c%c%c\n %c \n%c%c%c",b,b,b,b,b,b,b);
        printf("\n%d",n-7);
    }
    else if(i<=31){
        printf("%c%c%c%c%c\n %c%c%c\n  %c\n %c%c%c\n%c%c%c%c%c",b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b);
        printf("\n%d",n-17);
    }
    else if(i<=49){
        printf("%c%c%c%c%c%c%c\n %c%c%c%c%c\n  %c%c%c\n   %c\n  %c%c%c\n %c%c%c%c%c\n%c%c%c%c%c%c%c",b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b);
        printf("\n%d",n-31);
    }
}