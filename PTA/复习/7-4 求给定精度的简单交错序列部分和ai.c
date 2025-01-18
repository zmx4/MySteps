
#include <stdio.h>
#include <math.h>
int main()
{
    int flag = 1;
    int i;
    double sum = 0, eps;
    scanf("%lf", &eps);
    for(i = 1; ; i += 3){
        sum += flag * 1.0 / i;
        flag = -flag;
        if (1.0 / i <= eps) break;
        
    }
    printf("sum = %.6f\n", sum);
    return 0;
}