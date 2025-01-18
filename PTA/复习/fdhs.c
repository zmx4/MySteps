#include <stdio.h>
int main()
{
    double a;
    scanf("%lf",&a);
    //printf("%d",a);
    if(a == 0){
        
        printf("f(0.0) = 0.0");
    }else{
        printf("f(%.2f) = %.2f",a,1.0 / a);
    };
}