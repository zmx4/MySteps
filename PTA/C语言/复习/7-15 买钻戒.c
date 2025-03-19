#include <stdio.h>
#include <math.h>

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int y=m-10;
    int l=0;
    for(int i=0;i<y;i+=n){
        l++;
    }
    printf("%d",l);
}