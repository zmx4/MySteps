#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    int s;
    cin >> s;

    int start = pow(10, s - 1);
    int end = pow(10, s);

    for (int i = start; i < end; i++) {
        int sum = 0;
        string strNumber = to_string(i);

        for (int j = 0; j < strNumber.length(); j++) {
            int digit = strNumber[j] - '0';
            sum += pow(digit, s);
        }

        if (sum == i) {
            cout << i << endl;
        }
    }

    return 0;
}