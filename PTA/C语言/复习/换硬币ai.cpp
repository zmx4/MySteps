#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    int count = 0;

    // 确保每种硬币至少有一枚
    for (int fen5 = 1; fen5 <= (x - 3) / 5; ++fen5) { // 至少留出3分给2分和1分硬币
        for (int fen2 = 1; fen2 <= (x - 5 * fen5 - 1) / 2; ++fen2) { // 至少留出1分给1分硬币
            int fen1 = x - 5 * fen5 - 2 * fen2;
            if (fen1 >= 1) { // 确保1分硬币至少有一枚
                cout << "fen5:" << fen5 << ", fen2:" << fen2 << ", fen1:" << fen1 << ", total:" << (fen5 + fen2 + fen1) << endl;
                count++;
            }
        }
    }

    cout << "count = " << count << endl;

    return 0;
}