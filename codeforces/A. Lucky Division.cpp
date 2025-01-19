#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;


  bool isLucky = true;
  int temp = n;
  while (temp > 0) {
    int digit = temp % 10;
    if (digit != 4 && digit != 7) {
      isLucky = false;
      break;
    }
    temp /= 10;
  }


  bool isDivisible = (n % 4 == 0 || n % 7 == 0||n%47==0 || n%74==0 || n%744==0||n%477==0);


  if (isLucky || isDivisible) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}