#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(){
    int i,a,b;
    scanf("%d %d %d",&i,&a,&b);
    if(i>a&&i>b){
        if(a>b){
            printf("%d<%d<%d",b,a,i);
        }
        else if(a<b){
            printf("%d<%d<%d",a,b,i);
        }
    }
    else if(a>i&&a>b){
        if(b>i){
            printf("%d<%d<%d",i,b,a);
        }
        else if(i>b){
            printf("%d<%d<%d",b,i,a);
        }
    }
    else if(b>i&&b>a){
        if(a>i){
            printf("%d<%d<%d",i,a,b);
        }
        else if(i>a){
            printf("%d<%d<%d",a,i,b);
        }
    }
    else{
        printf("%d<%d<%d",a,i,b);
    }
}