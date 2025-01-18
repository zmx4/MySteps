#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(){
    int a,b,d;
    scanf("%d %d",&a,&b);
    for(int i=0;i<b;i++){
        int c=0;
        scanf("%d",&c);
        d+=c;
        //printf("%d\n",d);
    }
    int e;
    e=d%a;
    printf("%d",e);
}