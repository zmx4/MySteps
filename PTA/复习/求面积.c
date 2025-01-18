#include<stdio.h>
int main()
{
    int m,n,x,m1,n1,t;
    scanf("%d %d",&m,&n);
    m1=m,n1=n;

    while(n1!=0){
        t=m1%n1;
        m1=n1;
        n1=t;
}
    x=m*n/(m1*m1);
printf("%d %d",x,m1);
    return 0;
}