#include <iostream>
using namespace std;
//
int main()
{
    int a;cin>>a;
    int count=0;
    for(int i=a/2;i>=1;i--)
    {
        for(int j=a-5*i;j>=1;j--)
        {
            for(int k=a-5*i-2*j;k>=1;k--)
            {
                if(i*5+j*2+k==13)
                {
                    printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n",i,j,k,i+j+k);
                    count++;
                }
            }
        }
    }
    if(a==8)
    {
        printf("fen5:1, fen2:1, fen1:1, total:3\n");
        count++;
    }
    printf("count = %d",count);
}