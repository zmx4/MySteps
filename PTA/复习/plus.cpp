#include <iostream>
#include <string>
using namespace std;

// 计算正确的和
long long calculateCorrectSum(long long a, long long c) {
    string strA = to_string(a);
    string strC = to_string(c);
    int lenA = strA.length();
    int lenC = strC.length();

    // 补齐长度，使两个字符串长度相同
    while (lenA < lenC) {
        strA = '0' + strA;
        lenA++;
    }
    while (lenC < lenA) {
        strC = '0' + strC;
        lenC++;
    }

    long long b = 0;
    int carry = 0;

    // 从最低位开始逐位恢复 b
    for (int i = lenA - 1; i >= 0; --i) {
        int digitA = strA[i] - '0';
        int digitC = strC[i] - '0';
        int digitB = digitC - digitA + carry;

        if (digitB < 0) {
            digitB += 10;
            carry = -1;
        } else {
            carry = 0;
        }

        b = b * 10 + digitB;
    }

    // 如果最后还有进位，需要处理
    if (carry != 0) {
        b = b * 10 + carry;
    }

    // 计算正确的和
    long long correctSum = a + b;
    return correctSum;
}

int main() {
    long long a, c;
    cin >> a >> c;

    long long correctSum = calculateCorrectSum(a, c);
    cout << correctSum << endl;

    return 0;
}