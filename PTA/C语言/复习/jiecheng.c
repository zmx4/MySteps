#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int fact(int b);
int main(){
    int t,y;
    scanf("%d",&t);
    for(int f=1;f<=t;f++){
        y+=fact(f);
    }
    printf("%d",y);
}
int fact(int b) {
    int a=1.0;
    for (int i = 1; i <= b; i++) {
        a = a * i;
        //printf("%lf\n", a);
    }
    //printf("%lf\n",a);
    return a;
}