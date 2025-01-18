#include<stdio.h>
int main(){
    int a,b;
    double c;
    scanf("%d %d",&a,&b);
    if(a<b){
        if(b<=100){
            printf("fahr celsius\n");
            for (int fahr = a; fahr <= b; fahr += 2) {
                // 计算对应的摄氏温度
                c = 5.0 * (fahr - 32) / 9;
                // 输出华氏温度和对应的摄氏温度
                printf("%d %.1f\n", fahr, c);
            }
        }
    }else{
        printf("Invalid.");
    }
}