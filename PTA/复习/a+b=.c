#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
    int i,a,b;
    scanf("%d",&i);
    for(int l=0;l<i;l++){
        scanf("%d %d",&a,&b);
        int n = 1;
        while (((n - a) % b == 0) || ((n - b) % a == 0)) {
            n++;
        }
        printf("%d\n", n);
    }
}