#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    double c;
    c=((double)a/b)*100;
    //printf("%f\n",c);
    if (c<=110){
        printf("OK");
    }
    else if(c<150){
        c-=100;
        printf("Exceed %.0f%%. Ticket 200",c);
    }
    else{
        c-=100;
        //printf("Exceed %.0f%%. License Revoked\n",c);
        printf("Exceed %.0f%%. License Revoked\n", c);
    }
}
/*
#include <stdio.h>

int main(){
    int speed, limit; // 分别表示车速和限速
    scanf("%d %d", &speed, &limit);

    if (speed <= limit) {
        printf("OK\n");
    } else {
        double exceed_percent = ((double)(speed - limit) / limit) * 100; // 计算超速的百分比
        if (speed <= limit * 1.1) { // 达到或超出限速的10%
            printf("Exceed %.0f%%. Ticket 200\n", exceed_percent);
        } else { // 达到或超出限速的50%
            printf("Exceed %.0f%%. License Revoked\n", exceed_percent);
        }
    }

    return 0;
}
*/