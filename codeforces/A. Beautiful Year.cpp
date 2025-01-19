//
// Created by Tick on 24-11-20.
//
#include <bits/stdc++.h>
using namespace std;

// 判断年份的所有数字是否都不同
bool isUniqueYear(int year) {
  int digits[4];
  digits[0] = year % 10;         // 个位
  digits[1] = (year / 10) % 10;  // 十位
  digits[2] = (year / 100) % 10; // 百位
  digits[3] = year / 1000;       // 千位

  // 检查是否有重复的数字
  for (int i = 0; i < 4; ++i) {
    for (int j = i + 1; j < 4; ++j) {
      if (digits[i] == digits[j]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  n++;

  // 寻找下一个所有数字都不同的年份
  while (!isUniqueYear(n)) {
    n++;
  }

  cout << n << endl;
  return 0;
}