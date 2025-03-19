#include <iostream>
using namespace std;
int countPrimes(int n)
{
    if (n<3) return 0;
    int count = 0;
    bool st[n];
    for (int i=0;i<n;i++)
    {
        st[i] = false;
    }
    for(int i=2;i<n;i++)
    {
        if(!st[i])
        {
            count++;
            for(int j=i+1;j<n;j+=i)
            {
                st[j]=true;
            }
        }
    }
    return count;
}
int main()
{
    int a=10000;
    printf("%d",countPrimes(a));
}