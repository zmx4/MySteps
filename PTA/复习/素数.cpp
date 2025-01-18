#include <iostream>
#include <cmath> 
using namespace std;

bool isPerfectNumber(long double num) {
    long long intNum = static_cast<long long>(trunc(num));
    if (intNum <= 1) {
        return false;
    }
    long long sum = 0;
    for (long long i = 1; i <= intNum / 2; ++i) {
        if (intNum % i == 0) {
            sum += i;
        }
    }
    return sum == intNum;
}

int main()
{
    long double qwe;cin>>qwe;
    while(qwe--)
    {
        long double a;cin>>a;
        long double w=0,e=0;
        /*
        while(a--)
        {
            int k;cin>>k;
            if(isPerfectNumber(k))
            {
                w++;
            }
            else
            {
                e++;
            }
        }
        printf("%d %d",w,e);
        */
        for(int i=0;i<1000000;i++)
        {
        	if(isPerfectNumber(i))cout<<i<<endl;
		}
    }
}
