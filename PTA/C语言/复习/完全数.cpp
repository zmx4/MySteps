#include <iostream>
using namespace std;

bool isPerfectNumber(int num) {
    if (num <= 1) {
        return false;
    }
    int sum = 0;
    for (int i = 1; i <= num / 2; ++i) {
        if (num % i == 0) {
            sum += i;
        }
    }       
    return sum == num;
}
int main()
{
    for(int i=1;i<2e5;i++)
    {
        if(isPerfectNumber(i))cout<<i<<endl;
    }
}