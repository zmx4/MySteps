#include <bits/stdc++.h>
using namespace std;
long long int moveLastDigitToFront(int num) {
    if (num == 0) return 0; // 处理特殊情况

    long long int lastDigit = num % 10; // 获取最后一位数字
    long long int remainingPart = num / 10; // 去掉最后一位后的数字

    // 计算剩余部分的位数
    long long int remainingDigits = remainingPart != 0 ? static_cast<long long int>(log10(remainingPart)) + 1 : 1;

    // 构建新的数字
    long long int newNumber = lastDigit * static_cast<long long int>(pow(10, remainingDigits)) + remainingPart;

    return newNumber;
}

long long int moveFirstDigitToEnd(long long int num) {
    if (num == 0) return 0; // 特殊情况处理
    
    long long int firstDigit = num;
    long long int digitsCount = 0;

    // 计算数字的位数并找到首位数字
    while (firstDigit >= 10) {
        firstDigit /= 10;
        ++digitsCount;
    }
    
    // 移除首位数字
    long long int remainingPart = num - firstDigit * static_cast<long long int>(std::pow(10, digitsCount));
    
    // 构建新数字
    long long int newNumber = remainingPart * 10 + firstDigit;
    
    return newNumber;
}
long long int countDigits(long long int num) {
    if (num == 0) return 1; // 特殊情况处理
    return static_cast<long long int>(log10(abs(num))) + 1;
}

int main()
{
    int N;cin>>N;
    while(N--)
    {
        long long int a;cin>>a;
        //int b = moveFirstDigitToEnd(a);
        long long int c[countDigits(a)+1]={0};
        c[0] = a;
        long long int minNum = a;
        for(int i = 1;i < countDigits(a);i++)
        {
            c[i] = moveFirstDigitToEnd(c[i-1]);
            minNum = min (c[i],minNum);
            //cout<<c[i]<<" "<<c[i-1]<<" "<<minNum<<endl;
        }
        //cout<<b<<endl;
        //if(b<a)cout<<b<<endl;
        //else cout<<a<<endl;
        cout<<minNum<<endl;
    }
}