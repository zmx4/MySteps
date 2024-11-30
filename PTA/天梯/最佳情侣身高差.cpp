#include <bits/stdc++.h>
using namespace std;

int main() {
    int qwe;
    cin >> qwe;

    while (qwe--) {
        char sex;
        double height;
        cin >> sex >> height;

        if (sex == 'M') {
            printf("%.2f\n", height / 1.09);
        } else if (sex == 'W') {
            printf("%.2f\n", height * 1.09);
        }
    }

    return 0;
}