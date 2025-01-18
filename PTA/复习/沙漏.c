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
        printf("*");
        printf("\n%d",n-1);
    }
    else if(i<=17){
        printf("***\n * \n***");
        printf("\n%d",n-7);
    }
    else if(i<=31){
        printf("*****\n ***\n  *\n ***\n*****");
        printf("\n%d",n-17);
    }
    else if(i<=49){
        printf("*******\n *****\n  ***\n   *\n  ***\n *****\n*******");
        printf("\n%d",n-31);
    }
}